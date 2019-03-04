/*
	This program explains the usage of commandlinetoargvw function to read the command line arguments
*/
//

#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>

int main()
{
	LPWSTR *szArgList;
	int iNumberArgs;
	int iItr;
	szArgList = CommandLineToArgvW(GetCommandLine(), &iNumberArgs);
	if (NULL == szArgList)
	{
		//use of wprintf to print widechar strings
		wprintf(L"commandlineargw failed\n");
		return 0;
	}
	else
	{
		for (iItr = 1; iItr < iNumberArgs; iItr++)
		{
			printf("%d: %ws\n", iItr, szArgList[iItr]);
		}
	}
	LocalFree(szArgList);
	getchar();
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
