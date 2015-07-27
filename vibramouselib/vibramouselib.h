#define EXPORT extern "C" __declspec(dllexport)

EXPORT int vibramouseSetHook(void);
EXPORT int vibramouseEndHook(void);
EXPORT LRESULT CALLBACK vibramouseHookProc(int, WPARAM, LPARAM);

/// <summary>
/// <para>Returns path of Vibramouse INI file.</para>
/// <para>vibramouse.ini �t�@�C���̃p�X��Ԃ��܂��B</para>
/// </summary>
/// <return>
/// <para>A pointer for path.</para>
/// <para>�p�X������̃|�C���^</para>
/// </return>
/// <remarks>
/// <para>Caller MUST release buffer(delete[]) pointed by returned value.</para>
/// <para>�Ăяo�����́A�߂�l���g�p��A�߂�l�ł���|�C���^���w���������̈��K���J��(delete[])���Ȃ���΂Ȃ�܂���B</para>
/// </remarks>
EXPORT LPCTSTR vibramouseSetupIniFilePath(void);

#define INICONFIG	L"Config"
#define INIPARAM	L"Parameter"
