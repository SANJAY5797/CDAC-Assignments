/*
	This program explains the conversion from unicode to multibyte and viceversa
	it also uses isunicode api to check if the string is unicode or not
*/
//

#include "pch.h"
#include<windows.h>
#include <iostream>
#include<tchar.h>
using namespace std;
int main()
{
	// tchar implementation
	//TCHAR var = TEXT("sanh");
	//cout << var << endl;

	// usage of multibytetowidechar
	CHAR cAnsiString[] = "ansi string";
	WCHAR wUnicodeString[] = L"unicode string";
	int iReq = MultiByteToWideChar(CP_UTF8, 0, cAnsiString, -1, NULL, 0);
	if (0 == iReq)
	{
		printf_s("multibytetowidechar failed with error %u", GetLastError);
	}
	WCHAR *wMulti = new WCHAR[iReq];

	MultiByteToWideChar(CP_UTF8, 0, cAnsiString, -1, wMulti, iReq);
	//cout << strlen(cAnsiString) * sizeof(CHAR) << " " << wcslen(wMulti) * ans << endl;


	printf_s("wide char string is %S\n", wMulti);

	//converting wide characters to multibyte characters

	int iReqMulti = WideCharToMultiByte(CP_UTF8, 0, wUnicodeString, -1, NULL, 0, NULL, NULL);
	if (0 == iReqMulti)
	{
		printf_s("WideCharToMultiByte failed with error %u", GetLastError);
	}
	CHAR *cAnsi = new CHAR[iReqMulti];
	WideCharToMultiByte(CP_UTF8, 0, wUnicodeString, -1, cAnsi, iReqMulti, NULL, NULL);
	printf_s("ansi char string is %s\n", cAnsi);
	BOOL bTest = IsTextUnicode(wUnicodeString, wcslen(wUnicodeString), NULL);
	if (bTest)
	{
		cout << "it is unicode" << endl;
	}
	else
	{
		cout << "it is ansi" << endl;
	}
	system("pause");
	delete wMulti;
	delete cAnsi;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
