#include <iostream>
#include <Windows.h>
#include <cassert>
#include <locale>
constexpr char AAA[] = "AAA";
constexpr wchar_t WAAA[] = L"AAA";
// need C++17
// static_assert(sizeof(AAA) == 4);

constexpr char HELLOWORLD[] = "Hello World!\n";
constexpr wchar_t UTF16JAPANESE[] = L"これはwcoutです\n";

using namespace std;

#define STRINGBYTECOUNT(s) ((_countof(s) - 1) * sizeof(s[0]))
void outApi()
{
	assert(STRINGBYTECOUNT(AAA) == strlen(AAA));
	assert(STRINGBYTECOUNT(WAAA) == (wcslen(WAAA) * sizeof(WAAA[0])));
	DWORD dwWritten;
	WriteFile(
		GetStdHandle(STD_OUTPUT_HANDLE),
		HELLOWORLD,
		STRINGBYTECOUNT(HELLOWORLD),
		&dwWritten,
		NULL);
	WriteFile(
		GetStdHandle(STD_OUTPUT_HANDLE),
		UTF16JAPANESE,
		STRINGBYTECOUNT(UTF16JAPANESE),
		&dwWritten,
		NULL);
}
int main()
{
	try
	{
        locale loc1("ja-JP");
		locale loc2 = locale::global(loc1);
		cout << "The name of the previous locale is: " << loc2.name()
			<< "." << endl;
		cout << "The name of the current locale is: " << loc1.name()
			<< "." << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
		return 1;
	}

	outApi();
	cout << HELLOWORLD;
	wcout << L"This is wcout utf8\n";

	cout << "これはcoutです\n";
	wcout << UTF16JAPANESE;
	cout << u8"これはcout utf8です\n";
}
