#define WINVER 0x0A00
#define _WIN32_WINNT 0x0A00

// https://stackoverflow.com/a/27615711
#include <Windows.h>
#include <tchar.h>
#include <winnls.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iterator>
#include <locale>

using namespace std;

vector<wstring> locals;

BOOL CALLBACK MyFuncLocaleEx(LPWSTR pStr, DWORD dwFlags, LPARAM lparam)
{
    UNREFERENCED_PARAMETER(dwFlags);
    UNREFERENCED_PARAMETER(lparam);

    locals.push_back(pStr);
    return TRUE;
}

int main()
{
    EnumSystemLocalesEx(MyFuncLocaleEx, LOCALE_ALL, NULL, NULL);

    for (vector<wstring>::const_iterator str = locals.begin(); str != locals.end(); ++str)
        wcout << *str << endl;

    wcout << "Total " << locals.size() << " locals found." << endl;

    return 0;
}
