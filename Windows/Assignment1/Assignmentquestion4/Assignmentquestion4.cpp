// program4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>
#define BUFFER_SIZE 100
int main(int argc, TCHAR* argv[])
{
	HANDLE hFile;
	TCHAR buffer[BUFFER_SIZE];
	//CONST TCHAR *lpString = TEXT("file.txt");
	std::cout << argc << " "<<argv[1];
	if (argc != 2)
	{
		_tprintf(TEXT("number of arguments"));
		system("pause");
		return FALSE;
	}
	hFile = CreateFile(
		argv[1],
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		_tprintf(TEXT("File doesn't exist error: %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	else
	{
		int numberOfBytes = 0;
		ZeroMemory(buffer, BUFFER_SIZE);
		BOOL bRet = ReadFile(hFile, buffer, BUFFER_SIZE, NULL, NULL);
		if (0 == bRet)
		{
			_tprintf(TEXT("Can't read File error status %d\n"), GetLastError());
		}
		else
		{
			
			for (int i = 0; i < _tcslen(buffer); i++)
			{
				printf("%c", buffer[i]);
			}
			_tprintf(TEXT("\n"));
		}
	}
	getchar();
	system("pause");
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
