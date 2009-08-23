//
// Form1.h - Vibramouse GUI main
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

#pragma once

#include<cmath>
#include "../vibramouselib/vibramouselib.h"

namespace vibramouse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	struct ParameterBank {
		int len;
		int freq;
		int amp;
		int cres;
		int pitch;
		int down;
	} bank[4];

	/// <summary>
	/// Form1 の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
			getParameter();
			if (selBank == 0) radioButton1->Checked = true;
			else if (selBank == 1) radioButton2->Checked = true;
			else if (selBank == 2) radioButton3->Checked = true;
			else if (selBank == 3) radioButton4->Checked = true;
			displayParameters();
			setParameter();
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TrackBar^  trackBarLen;
	private: System::Windows::Forms::TrackBar^  trackBarFreq;
	private: System::Windows::Forms::TrackBar^  trackBarAmp;
	private: System::Windows::Forms::TrackBar^  trackBarCres;
	private: System::Windows::Forms::TrackBar^  trackBarPitch;
	private: System::Windows::Forms::TrackBar^  trackBarDown;
	protected: 

	protected: 


	private: System::Windows::Forms::Label^  labelLen;
	private: System::Windows::Forms::Label^  labelFreq;
	private: System::Windows::Forms::Label^  labelAmp;
	private: System::Windows::Forms::Label^  labelCres;
	private: System::Windows::Forms::Label^  labelPitch;
	private: System::Windows::Forms::Label^  labelDown;

	public:
	int selBank;
	int len;
	int freq;
	int amp;
	int cres;
	int pitch;
	int down;

	private: System::Windows::Forms::Label^  labelLenDisp;
	private: System::Windows::Forms::Label^  labelFreqDisp;
	private: System::Windows::Forms::Label^  labelAmpDisp;
	private: System::Windows::Forms::Label^  labelCresDisp;
	private: System::Windows::Forms::Label^  labelPitchDisp;
	private: System::Windows::Forms::Label^  labelDownDisp;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;


	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->trackBarLen = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarFreq = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarAmp = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarCres = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarPitch = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarDown = (gcnew System::Windows::Forms::TrackBar());
			this->labelLen = (gcnew System::Windows::Forms::Label());
			this->labelFreq = (gcnew System::Windows::Forms::Label());
			this->labelAmp = (gcnew System::Windows::Forms::Label());
			this->labelCres = (gcnew System::Windows::Forms::Label());
			this->labelPitch = (gcnew System::Windows::Forms::Label());
			this->labelDown = (gcnew System::Windows::Forms::Label());
			this->labelLenDisp = (gcnew System::Windows::Forms::Label());
			this->labelFreqDisp = (gcnew System::Windows::Forms::Label());
			this->labelAmpDisp = (gcnew System::Windows::Forms::Label());
			this->labelCresDisp = (gcnew System::Windows::Forms::Label());
			this->labelPitchDisp = (gcnew System::Windows::Forms::Label());
			this->labelDownDisp = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarLen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarFreq))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarAmp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarCres))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarPitch))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// trackBarLen
			// 
			this->trackBarLen->AutoSize = false;
			this->trackBarLen->Location = System::Drawing::Point(44, 10);
			this->trackBarLen->Maximum = 100;
			this->trackBarLen->Name = L"trackBarLen";
			this->trackBarLen->Size = System::Drawing::Size(225, 20);
			this->trackBarLen->TabIndex = 6;
			this->trackBarLen->TickFrequency = 10;
			this->trackBarLen->Scroll += gcnew System::EventHandler(this, &Form1::trackBarLen_Scroll);
			// 
			// trackBarFreq
			// 
			this->trackBarFreq->AutoSize = false;
			this->trackBarFreq->Location = System::Drawing::Point(44, 36);
			this->trackBarFreq->Maximum = 100;
			this->trackBarFreq->Name = L"trackBarFreq";
			this->trackBarFreq->Size = System::Drawing::Size(225, 20);
			this->trackBarFreq->TabIndex = 7;
			this->trackBarFreq->TickFrequency = 10;
			this->trackBarFreq->Scroll += gcnew System::EventHandler(this, &Form1::trackBarFreq_Scroll);
			// 
			// trackBarAmp
			// 
			this->trackBarAmp->AutoSize = false;
			this->trackBarAmp->Location = System::Drawing::Point(44, 62);
			this->trackBarAmp->Maximum = 100;
			this->trackBarAmp->Name = L"trackBarAmp";
			this->trackBarAmp->Size = System::Drawing::Size(225, 20);
			this->trackBarAmp->TabIndex = 8;
			this->trackBarAmp->TickFrequency = 10;
			this->trackBarAmp->Scroll += gcnew System::EventHandler(this, &Form1::trackBarAmp_Scroll);
			// 
			// trackBarCres
			// 
			this->trackBarCres->AutoSize = false;
			this->trackBarCres->Location = System::Drawing::Point(44, 88);
			this->trackBarCres->Maximum = 100;
			this->trackBarCres->Name = L"trackBarCres";
			this->trackBarCres->Size = System::Drawing::Size(225, 20);
			this->trackBarCres->TabIndex = 9;
			this->trackBarCres->TickFrequency = 10;
			this->trackBarCres->Scroll += gcnew System::EventHandler(this, &Form1::trackBarCres_Scroll);
			// 
			// trackBarPitch
			// 
			this->trackBarPitch->AutoSize = false;
			this->trackBarPitch->Location = System::Drawing::Point(44, 114);
			this->trackBarPitch->Maximum = 100;
			this->trackBarPitch->Name = L"trackBarPitch";
			this->trackBarPitch->Size = System::Drawing::Size(225, 20);
			this->trackBarPitch->TabIndex = 10;
			this->trackBarPitch->TickFrequency = 10;
			this->trackBarPitch->Scroll += gcnew System::EventHandler(this, &Form1::trackBarPitch_Scroll);
			// 
			// trackBarDown
			// 
			this->trackBarDown->AutoSize = false;
			this->trackBarDown->Location = System::Drawing::Point(44, 140);
			this->trackBarDown->Maximum = 100;
			this->trackBarDown->Name = L"trackBarDown";
			this->trackBarDown->Size = System::Drawing::Size(225, 20);
			this->trackBarDown->TabIndex = 11;
			this->trackBarDown->TickFrequency = 10;
			this->trackBarDown->Scroll += gcnew System::EventHandler(this, &Form1::trackBarDown_Scroll);
			// 
			// labelLen
			// 
			this->labelLen->AutoSize = true;
			this->labelLen->Location = System::Drawing::Point(12, 10);
			this->labelLen->Name = L"labelLen";
			this->labelLen->Size = System::Drawing::Size(25, 12);
			this->labelLen->TabIndex = 0;
			this->labelLen->Text = L"長さ";
			// 
			// labelFreq
			// 
			this->labelFreq->AutoSize = true;
			this->labelFreq->Location = System::Drawing::Point(12, 36);
			this->labelFreq->Name = L"labelFreq";
			this->labelFreq->Size = System::Drawing::Size(29, 12);
			this->labelFreq->TabIndex = 1;
			this->labelFreq->Text = L"周期";
			// 
			// labelAmp
			// 
			this->labelAmp->AutoSize = true;
			this->labelAmp->Location = System::Drawing::Point(12, 62);
			this->labelAmp->Name = L"labelAmp";
			this->labelAmp->Size = System::Drawing::Size(29, 12);
			this->labelAmp->TabIndex = 2;
			this->labelAmp->Text = L"振幅";
			// 
			// labelCres
			// 
			this->labelCres->AutoSize = true;
			this->labelCres->Location = System::Drawing::Point(12, 88);
			this->labelCres->Name = L"labelCres";
			this->labelCres->Size = System::Drawing::Size(29, 12);
			this->labelCres->TabIndex = 3;
			this->labelCres->Text = L"増幅";
			// 
			// labelPitch
			// 
			this->labelPitch->AutoSize = true;
			this->labelPitch->Location = System::Drawing::Point(12, 114);
			this->labelPitch->Name = L"labelPitch";
			this->labelPitch->Size = System::Drawing::Size(29, 12);
			this->labelPitch->TabIndex = 4;
			this->labelPitch->Text = L"上下";
			// 
			// labelDown
			// 
			this->labelDown->AutoSize = true;
			this->labelDown->Location = System::Drawing::Point(12, 140);
			this->labelDown->Name = L"labelDown";
			this->labelDown->Size = System::Drawing::Size(29, 12);
			this->labelDown->TabIndex = 5;
			this->labelDown->Text = L"下降";
			// 
			// labelLenDisp
			// 
			this->labelLenDisp->AutoSize = true;
			this->labelLenDisp->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->labelLenDisp->Location = System::Drawing::Point(275, 8);
			this->labelLenDisp->Name = L"labelLenDisp";
			this->labelLenDisp->Size = System::Drawing::Size(16, 16);
			this->labelLenDisp->TabIndex = 12;
			this->labelLenDisp->Text = L"0";
			this->labelLenDisp->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelFreqDisp
			// 
			this->labelFreqDisp->AutoSize = true;
			this->labelFreqDisp->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->labelFreqDisp->Location = System::Drawing::Point(275, 34);
			this->labelFreqDisp->Name = L"labelFreqDisp";
			this->labelFreqDisp->Size = System::Drawing::Size(16, 16);
			this->labelFreqDisp->TabIndex = 13;
			this->labelFreqDisp->Text = L"0";
			this->labelFreqDisp->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelAmpDisp
			// 
			this->labelAmpDisp->AutoSize = true;
			this->labelAmpDisp->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->labelAmpDisp->Location = System::Drawing::Point(275, 60);
			this->labelAmpDisp->Name = L"labelAmpDisp";
			this->labelAmpDisp->Size = System::Drawing::Size(16, 16);
			this->labelAmpDisp->TabIndex = 14;
			this->labelAmpDisp->Text = L"0";
			this->labelAmpDisp->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelCresDisp
			// 
			this->labelCresDisp->AutoSize = true;
			this->labelCresDisp->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->labelCresDisp->Location = System::Drawing::Point(275, 86);
			this->labelCresDisp->Name = L"labelCresDisp";
			this->labelCresDisp->Size = System::Drawing::Size(16, 16);
			this->labelCresDisp->TabIndex = 15;
			this->labelCresDisp->Text = L"0";
			this->labelCresDisp->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelPitchDisp
			// 
			this->labelPitchDisp->AutoSize = true;
			this->labelPitchDisp->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->labelPitchDisp->Location = System::Drawing::Point(275, 112);
			this->labelPitchDisp->Name = L"labelPitchDisp";
			this->labelPitchDisp->Size = System::Drawing::Size(16, 16);
			this->labelPitchDisp->TabIndex = 16;
			this->labelPitchDisp->Text = L"0";
			this->labelPitchDisp->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelDownDisp
			// 
			this->labelDownDisp->AutoSize = true;
			this->labelDownDisp->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->labelDownDisp->Location = System::Drawing::Point(275, 138);
			this->labelDownDisp->Name = L"labelDownDisp";
			this->labelDownDisp->Size = System::Drawing::Size(16, 16);
			this->labelDownDisp->TabIndex = 17;
			this->labelDownDisp->Text = L"0";
			this->labelDownDisp->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(314, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 190);
			this->pictureBox1->TabIndex = 18;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// radioButton1
			// 
			this->radioButton1->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(53, 176);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(47, 22);
			this->radioButton1->TabIndex = 19;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Bank1";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(106, 176);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(47, 22);
			this->radioButton2->TabIndex = 20;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Bank2";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(159, 176);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(47, 22);
			this->radioButton3->TabIndex = 21;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Bank3";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(212, 176);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(47, 22);
			this->radioButton4->TabIndex = 22;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Bank4";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton4_CheckedChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(723, 209);
			this->Controls->Add(this->trackBarLen);
			this->Controls->Add(this->trackBarFreq);
			this->Controls->Add(this->trackBarAmp);
			this->Controls->Add(this->trackBarCres);
			this->Controls->Add(this->trackBarPitch);
			this->Controls->Add(this->trackBarDown);
			this->Controls->Add(this->labelLen);
			this->Controls->Add(this->labelFreq);
			this->Controls->Add(this->labelAmp);
			this->Controls->Add(this->labelCres);
			this->Controls->Add(this->labelPitch);
			this->Controls->Add(this->labelDown);
			this->Controls->Add(this->labelLenDisp);
			this->Controls->Add(this->labelFreqDisp);
			this->Controls->Add(this->labelAmpDisp);
			this->Controls->Add(this->labelCresDisp);
			this->Controls->Add(this->labelPitchDisp);
			this->Controls->Add(this->labelDownDisp);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"VibraMouse 0.9";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Closing += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::Form1_Closing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarLen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarFreq))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarAmp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarCres))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarPitch))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void displayParameters(void)
		{
			trackBarLen->Value   = len;
			trackBarFreq->Value  = freq;
			trackBarAmp->Value   = amp;
			trackBarCres->Value  = cres;
			trackBarPitch->Value  = pitch;
			trackBarDown->Value  = down;
			labelLenDisp->Text   = String::Concat("", len);
			labelFreqDisp->Text  = String::Concat("", freq);
			labelAmpDisp->Text   = String::Concat("", amp);
			labelCresDisp->Text  = String::Concat("", cres);
			labelPitchDisp->Text = String::Concat("", pitch);
			labelDownDisp->Text  = String::Concat("", down);
			pictureBox1->Refresh();
		}
		void saveBank(int sel)
		{
			LPWSTR name[4] = {L"Bank1", L"Bank2", L"Bank3", L"Bank4" };
			WCHAR wc[20];
			LPWSTR s = wc;
			wsprintf(s, L"%d", bank[sel].len);
			WritePrivateProfileString(name[sel], L"Length",	   s, INIFILE);
			wsprintf(s, L"%d", bank[sel].freq);
			WritePrivateProfileString(name[sel], L"Frequency", s, INIFILE);
			wsprintf(s, L"%d", bank[sel].amp);
			WritePrivateProfileString(name[sel], L"Amplitude", s, INIFILE);
			wsprintf(s, L"%d", bank[sel].cres);
			WritePrivateProfileString(name[sel], L"Crescendo", s, INIFILE);
			wsprintf(s, L"%d", bank[sel].pitch);
			WritePrivateProfileString(name[sel], L"Pitch",	   s, INIFILE);
			wsprintf(s, L"%d", bank[sel].down);
			WritePrivateProfileString(name[sel], L"Down",	   s, INIFILE);
			wsprintf(s, L"%d", sel);
			WritePrivateProfileString(INIPARAM, L"Bank", s, INIFILE);
		}
		void setParameter(void)
		{
			WCHAR wc[20];
			LPWSTR s = wc;
			wsprintf(s, L"%d", len);
			WritePrivateProfileString(INIPARAM, L"Length",		s, INIFILE);
			wsprintf(s, L"%d", freq);
			WritePrivateProfileString(INIPARAM, L"Frequency",	s, INIFILE);
			wsprintf(s, L"%d", amp);
			WritePrivateProfileString(INIPARAM, L"Amplitude",	s, INIFILE);
			wsprintf(s, L"%d", cres);
			WritePrivateProfileString(INIPARAM, L"Crescendo",	s, INIFILE);
			wsprintf(s, L"%d", pitch);
			WritePrivateProfileString(INIPARAM, L"Pitch",		s, INIFILE);
			wsprintf(s, L"%d", down);
			WritePrivateProfileString(INIPARAM, L"Down",		s, INIFILE);
			// バッファのフラッシュ
			WritePrivateProfileString(NULL, NULL, NULL,		   INIFILE);
		}
		void getParameter(void)
		{
			bank[0].len   = GetPrivateProfileInt(L"Bank1", L"Length",	 70, INIFILE);
			bank[0].freq  = GetPrivateProfileInt(L"Bank1", L"Frequency", 70, INIFILE);
			bank[0].amp   = GetPrivateProfileInt(L"Bank1", L"Amplitude", 30, INIFILE);
			bank[0].cres  = GetPrivateProfileInt(L"Bank1", L"Crescendo",100, INIFILE);
			bank[0].pitch = GetPrivateProfileInt(L"Bank1", L"Pitch",	 50, INIFILE);
			bank[0].down  = GetPrivateProfileInt(L"Bank1", L"Down",		  0, INIFILE);

			bank[1].len   = GetPrivateProfileInt(L"Bank2", L"Length",	 70, INIFILE);
			bank[1].freq  = GetPrivateProfileInt(L"Bank2", L"Frequency", 70, INIFILE);
			bank[1].amp   = GetPrivateProfileInt(L"Bank2", L"Amplitude", 30, INIFILE);
			bank[1].cres  = GetPrivateProfileInt(L"Bank2", L"Crescendo",100, INIFILE);
			bank[1].pitch = GetPrivateProfileInt(L"Bank2", L"Pitch",	 50, INIFILE);
			bank[1].down  = GetPrivateProfileInt(L"Bank2", L"Down",		  0, INIFILE);

			bank[2].len   = GetPrivateProfileInt(L"Bank3", L"Length",	 70, INIFILE);
			bank[2].freq  = GetPrivateProfileInt(L"Bank3", L"Frequency", 70, INIFILE);
			bank[2].amp   = GetPrivateProfileInt(L"Bank3", L"Amplitude", 30, INIFILE);
			bank[2].cres  = GetPrivateProfileInt(L"Bank3", L"Crescendo",100, INIFILE);
			bank[2].pitch = GetPrivateProfileInt(L"Bank3", L"Pitch",	 50, INIFILE);
			bank[2].down  = GetPrivateProfileInt(L"Bank3", L"Down",		  0, INIFILE);

			bank[3].len   = GetPrivateProfileInt(L"Bank4", L"Length",	 70, INIFILE);
			bank[3].freq  = GetPrivateProfileInt(L"Bank4", L"Frequency", 70, INIFILE);
			bank[3].amp   = GetPrivateProfileInt(L"Bank4", L"Amplitude", 30, INIFILE);
			bank[3].cres  = GetPrivateProfileInt(L"Bank4", L"Crescendo",100, INIFILE);
			bank[3].pitch = GetPrivateProfileInt(L"Bank4", L"Pitch",	 50, INIFILE);
			bank[3].down  = GetPrivateProfileInt(L"Bank4", L"Down",		  0, INIFILE);

			selBank = GetPrivateProfileInt(INIPARAM, L"Bank", 0, INIFILE);

			len   = bank[selBank].len;
			freq  = bank[selBank].freq;
			amp   = bank[selBank].amp;
			cres  = bank[selBank].cres;
			pitch = bank[selBank].pitch;
			down  = bank[selBank].down;
		}


#pragma endregion
private: System::Void trackBarLen_Scroll(System::Object^  sender, System::EventArgs^  e) {
			this->len = trackBarLen->Value;
			labelLenDisp->Text = String::Concat( "", trackBarLen->Value );
			pictureBox1->Refresh();
			this->setParameter();
		 }
private: System::Void trackBarFreq_Scroll(System::Object^  sender, System::EventArgs^  e) {
			this->freq = trackBarFreq->Value;
			labelFreqDisp->Text = String::Concat( "", trackBarFreq->Value );
			pictureBox1->Refresh();
			this->setParameter();
		 }
private: System::Void trackBarAmp_Scroll(System::Object^  sender, System::EventArgs^  e) {
			this->amp = trackBarAmp->Value;
			labelAmpDisp->Text = String::Concat( "", trackBarAmp->Value );
			pictureBox1->Refresh();
			this->setParameter();
		 }
private: System::Void trackBarCres_Scroll(System::Object^  sender, System::EventArgs^  e) {
			this->cres = trackBarCres->Value;
			labelCresDisp->Text = String::Concat( "", trackBarCres->Value );
			pictureBox1->Refresh();
			this->setParameter();
		 }
private: System::Void trackBarPitch_Scroll(System::Object^  sender, System::EventArgs^  e) {
			this->pitch = trackBarPitch->Value;
			labelPitchDisp->Text = String::Concat( "", trackBarPitch->Value );
			pictureBox1->Refresh();
			this->setParameter();
		 }
private: System::Void trackBarDown_Scroll(System::Object^  sender, System::EventArgs^  e) {
			this->down = trackBarDown->Value;
			labelDownDisp->Text = String::Concat( "", trackBarDown->Value );
			pictureBox1->Refresh();
			this->setParameter();
		 }
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			Graphics^ g = e->Graphics;
//			g->Clear(System::Drawing::Color::White);

			int area_x = this->len * 3 + 100;
			int area_y = 190;

			int zx = 0;
			int zy = area_y / 2;
			int ox = zx;
			int oy = zy;
			double step = 0.02;
			double cres_min = (double)(100 - this->cres) / 100;
			double cres_max = 1 - cres_min;
			double down_max = area_y / 2 * this->down / 100;
			double area_x3 = pow(area_x, 3.0);
			double pitstep = (50 - pitch) * 0.005;
			for (int i = 0; i < area_x; i++) {
				double rad = step * i * (this->freq / 5 + 1);
				int wid = (area_y / 2) * this->amp / 100 / 2;
				double cres_wid = (double)i / (double)area_x * cres_max + cres_min;
				double j = 2 * (i - area_x / 2);
				if (j < 0) j = 0;
				int down_wid = (int)(down_max * (pow(j, 3.0) / area_x3));
				int pit = (int)(pitstep * (double)i);
				int x = zx + i;
				int y = zy - (int)(sin(rad) * cres_wid * wid) + down_wid + pit;
				g->DrawLine(System::Drawing::Pens::White, ox, oy, x, y);
				ox = x;
				oy = y;
			}
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
//			 MessageBox::Show("hello");
			 vibramouseSetHook();
		 }
private: System::Void Form1_Closing(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
//			 MessageBox::Show("bye");
			 vibramouseEndHook();
			 saveBank(selBank);
		 }

private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->radioButton1->Checked) {
				this->len   = bank[0].len;
				this->freq  = bank[0].freq;
				this->amp   = bank[0].amp;
				this->cres  = bank[0].cres;
				this->pitch = bank[0].pitch;
				this->down  = bank[0].down;
				this->displayParameters();
				this->setParameter();
				selBank = 0;
			 } else {
				// パラメータの記録
				bank[0].len = this->len;
				bank[0].freq = this->freq;
				bank[0].amp = this->amp;
				bank[0].cres = this->cres;
				bank[0].pitch = this->pitch;
				bank[0].down = this->down;
				saveBank(0);
			 }
		 }
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->radioButton2->Checked) {
				this->len   = bank[1].len;
				this->freq  = bank[1].freq;
				this->amp   = bank[1].amp;
				this->cres  = bank[1].cres;
				this->pitch = bank[1].pitch;
				this->down  = bank[1].down;
				this->displayParameters();
				this->setParameter();
				selBank = 1;
			 } else {
				// パラメータの記録
				bank[1].len = this->len;
				bank[1].freq = this->freq;
				bank[1].amp = this->amp;
				bank[1].cres = this->cres;
				bank[1].pitch = this->pitch;
				bank[1].down = this->down;
				saveBank(1);
			 }
		 }
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->radioButton3->Checked) {
				this->len   = bank[2].len;
				this->freq  = bank[2].freq;
				this->amp   = bank[2].amp;
				this->cres  = bank[2].cres;
				this->pitch = bank[2].pitch;
				this->down  = bank[2].down;
				this->displayParameters();
				this->setParameter();
				selBank = 2;
			 } else {
				// パラメータの記録
				bank[2].len = this->len;
				bank[2].freq = this->freq;
				bank[2].amp = this->amp;
				bank[2].cres = this->cres;
				bank[2].pitch = this->pitch;
				bank[2].down = this->down;
				saveBank(2);
			 }
		 }
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->radioButton4->Checked) {
				this->len   = bank[3].len;
				this->freq  = bank[3].freq;
				this->amp   = bank[3].amp;
				this->cres  = bank[3].cres;
				this->pitch = bank[3].pitch;
				this->down  = bank[3].down;
				this->displayParameters();
				this->setParameter();
				selBank = 3;
			 } else {
				// パラメータの記録
				bank[3].len = this->len;
				bank[3].freq = this->freq;
				bank[3].amp = this->amp;
				bank[3].cres = this->cres;
				bank[3].pitch = this->pitch;
				bank[3].down = this->down;
				saveBank(3);
			 }
		 }
};
}

