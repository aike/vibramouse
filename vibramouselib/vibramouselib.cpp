//
// vibramouselib.cpp - Vibramouse DLL main
//
// Copyright (C) 2009 aike. All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 
//   1. Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//   2. Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in
//      the documentation and/or other materials provided with the
//      distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS''
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS
// BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
// BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
// IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "stdafx.h"
#include<cmath>
#include <mmsystem.h>
#include <tchar.h>
#include <minwinbase.h>
#include <shlobj.h>
#pragma comment(lib,"winmm.lib")
#include "vibramouselib.h"

#define INIFILE_DEFAULT		L"vibramouse.ini"
#define INIFILE_RELPATH		L"\\vibramouse\\vibramouse.ini"

void CALLBACK vibramouseMoveMouse(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1,DWORD dw2);
void vibramouseDoVibration(void);
void vibramouseCalcNextPoint(int count0, int point0, int& sx, int& sy);

MMRESULT timerID;
int timerCount;
int ox, oy;

HINSTANCE hInst;
HHOOK hHook;
HWND hWnd;
BOOL bHook = FALSE;
BOOL bVibrating = FALSE;

UINT configKey;
UINT configModifire;

double paramLen;
double paramFreq;
double paramAmp;
double paramCres;
double paramPitch;
double paramDown;

int paramSpeed;

double paramCresMin;
double paramCresMax;
double paramDownMax;
double paramWid3;
int calcPoint = 0;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	hInst = hModule;
	WCHAR buf[8];
	LPCTSTR inifile = NULL;
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		inifile = vibramouseSetupIniFilePath();
		GetPrivateProfileString(INICONFIG, L"Key", L"Z", buf, 8, inifile);
		configKey = buf[0];
		GetPrivateProfileString(INICONFIG, L"Modifire", L"ALT", buf, 8, inifile);
		delete[] inifile;
		if (lstrcmp(buf, L"SHIFT") == 0) {
			configModifire = VK_SHIFT;
		} else if (lstrcmp(buf, L"CTRL") == 0) {
			configModifire = VK_CONTROL;
		} else {
			configModifire = VK_MENU;	// AltÉLÅ[
		}
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}



EXPORT int vibramouseSetHook()
{
	hHook = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)vibramouseHookProc, hInst, NULL);
	if (hHook == NULL) {
		//MessageBox(hWnd, TEXT("SetWindowsHookExé∏îsÇ≈Ç∑"), TEXT("Error"), MB_OK);
		return -1;
	} else {
		//MessageBox(hWnd, TEXT("SetWindowsHookExê¨å˜Ç≈Ç∑"), TEXT("OK"), MB_OK);
		bHook = TRUE;
		return 0;
	}
}

EXPORT int vibramouseEndHook()
{
	if (! bHook)
		return 0;
	if (UnhookWindowsHookEx(hHook) != 0) {
		//MessageBox(hWnd, TEXT("UnhookWindowsHookExê¨å˜Ç≈Ç∑"), TEXT("OK"), MB_OK);
		bHook = FALSE;
		return 0;
	} else {
		//MessageBox(hWnd, TEXT("UnhookWindowsHookExé∏îsÇ≈Ç∑"), TEXT("Error"), MB_OK);
		return -1;
	}
}


EXPORT LRESULT CALLBACK vibramouseHookProc(int nCode, WPARAM wp, LPARAM lp)
{
	if( nCode < 0 || nCode == HC_NOREMOVE )
		return CallNextHookEx(hHook, nCode, wp, lp);

	if ((wp == configKey) && (GetKeyState(configModifire) & 0x100)) {
		vibramouseDoVibration();
		return TRUE;
	}
	return CallNextHookEx(hHook, nCode, wp, lp);
}

void CALLBACK vibramouseMoveMouse(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
	timerCount++;
	if (timerCount > (int)paramLen) {
		bVibrating = FALSE;
		timeKillEvent(timerID);
	}

	int sx, sy;
	vibramouseCalcNextPoint(timerCount, calcPoint, sx, sy);
	mouse_event(MOUSEEVENTF_MOVE, sx, sy, 0, NULL);

	calcPoint++;
	if (calcPoint > 100000)
		calcPoint = 0;

}

void vibramouseGetParameter(void)
{
	LPCTSTR inifile = vibramouseSetupIniFilePath();

	int len   = GetPrivateProfileInt(INIPARAM, L"Length",		0, inifile);
	int freq  = GetPrivateProfileInt(INIPARAM, L"Frequency",	0, inifile);
	int amp   = GetPrivateProfileInt(INIPARAM, L"Amplitude",	0, inifile);
	int cres  = GetPrivateProfileInt(INIPARAM, L"Crescendo",	0, inifile);
	int pitch = GetPrivateProfileInt(INIPARAM, L"Pitch",		0, inifile);
	int down  = GetPrivateProfileInt(INIPARAM, L"Down",			0, inifile);

	paramSpeed = GetPrivateProfileInt(INICONFIG, L"Speed",	   20, inifile);

	delete[] inifile;

	paramLen = (double)len * 2 + 50;
	paramFreq = (double)(freq + 1) * 0.01;
	paramAmp = (double)amp / 2;
	paramCres = (double)cres;
	paramPitch = (51 - (double)pitch) * 0.015;
	paramDown = (double)down;

	paramCresMin = (100 - paramCres) / 100;
	paramCresMax = 1 - paramCresMin;

	paramDownMax = paramDown;
	paramWid3	 = pow(paramLen, 3.0);

}

void vibramouseDoVibration(void)
{
	if (bVibrating)
		return;

	vibramouseGetParameter();
	ox = 0;
	oy = 0;
	bVibrating = TRUE;
	timerCount = 0;
	timerID = timeSetEvent(paramSpeed, 0, vibramouseMoveMouse, 0, TIME_PERIODIC);
}

void vibramouseCalcNextPoint(int count0, int point0, int& sx, int& sy)
{
	double pit = (double)count0 * paramPitch;

	double cres0 = (double)count0 / paramLen * paramCresMax + paramCresMin;
	double down0 = paramDownMax * (pow(count0, 3.0) / paramWid3);
	int x0 = count0 * 3;
	int y0 = (int)(sin((double)point0 * paramFreq) * paramAmp * cres0 + down0 + pit + 0.5);

	sx = x0 - ox;
	sy = y0 - oy;
	ox = x0;
	oy = y0;
}


LPCTSTR vibramouseSetupIniFilePath(void)
{
	// Create buffer for retrieve full path of INI file.
	const int bufferLength = MAX_PATH + 1;
	LPTSTR path = new TCHAR[bufferLength];
	::ZeroMemory(path, bufferLength);

	// Retrieve User Application Data Folder path (Typically C:\Users\<username>\AppData)
	HRESULT hResult = S_OK;
	hResult = SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path);
	if (hResult != S_OK) {
		// If failed, Return default value(Maybe directing Windows folder...)
		return INIFILE_DEFAULT;
	}

	// Check Buffer space
	if (_tcslen(path) + _tcslen(INIFILE_DEFAULT) < bufferLength) {
		// Make full path of INI file.
		_tcscat_s(path, bufferLength, INIFILE_RELPATH);
		// MessageBox(hWnd, path, TEXT("[DEBUG]INIFILE"), MB_OK);

		// Create Directory of path
		LPTSTR dirPath = new TCHAR[bufferLength];
		memcpy(dirPath, path, bufferLength);
		TCHAR* lastBackslash = _tcsrchr(dirPath, _T('\\'));
		if (lastBackslash != NULL) {
			*lastBackslash = _T('\0');
		}
		// MessageBox(hWnd, dirPath, TEXT("[DEBUG]INIFILE DIR"), MB_OK);
		::CreateDirectory(dirPath, NULL);
		delete[] dirPath;

		// Complete!
		return path;
	}
	else {
		// Prevent Buffer Overrun
		return INIFILE_DEFAULT;
	}
}
