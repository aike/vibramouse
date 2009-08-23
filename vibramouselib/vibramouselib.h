#define EXPORT extern "C" __declspec(dllexport)

EXPORT int vibramouseSetHook(void);
EXPORT int vibramouseEndHook(void);
EXPORT LRESULT CALLBACK vibramouseHookProc(int, WPARAM, LPARAM);

#define INIFILE		L"vibramouse.ini"
#define INICONFIG	L"Config"
#define INIPARAM	L"Parameter"
