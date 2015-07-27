#define EXPORT extern "C" __declspec(dllexport)

EXPORT int vibramouseSetHook(void);
EXPORT int vibramouseEndHook(void);
EXPORT LRESULT CALLBACK vibramouseHookProc(int, WPARAM, LPARAM);

/// <summary>
/// <para>Returns path of Vibramouse INI file.</para>
/// <para>vibramouse.ini ファイルのパスを返します。</para>
/// </summary>
/// <return>
/// <para>A pointer for path.</para>
/// <para>パス文字列のポインタ</para>
/// </return>
/// <remarks>
/// <para>Caller MUST release buffer(delete[]) pointed by returned value.</para>
/// <para>呼び出し元は、戻り値を使用後、戻り値であるポインタが指すメモリ領域を必ず開放(delete[])しなければなりません。</para>
/// </remarks>
EXPORT LPCTSTR vibramouseSetupIniFilePath(void);

#define INICONFIG	L"Config"
#define INIPARAM	L"Parameter"
