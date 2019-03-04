// Assignmentquestion5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<windows.h>
#include <iostream>
#include<tchar.h>
#define BUFFER_SIZE 10000
int main(int argc,char* argv[])
{
	HANDLE hFile;
	hFile = CreateFileA(
		argv[1],
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		_tprintf(TEXT("file creation failed"));
		_tprintf(TEXT("the error number is %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	else
	{
		TCHAR buffer[BUFFER_SIZE]=TEXT("this content ");
		BOOL bWrite = WriteFile(
			hFile,
			buffer,
			_countof(buffer)+1,
			NULL,
			NULL
		);
		if (0 == bWrite)
		{
			_tprintf(TEXT("Write operation failed\n"));
			_tprintf(TEXT("the error number is %d\n"), GetLastError());
		}
	}
	getchar();
	return TRUE;
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
