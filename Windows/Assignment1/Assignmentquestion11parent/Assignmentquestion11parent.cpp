// Assignmentquestion11parent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	HANDLE hFile;
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	if (argc != 2)
	{
		_tprintf(_T("less number of arguments to main function \n sample argumnets: filename.exe filename"));
		getchar();
		return FALSE;
	}
	struct _SECURITY_ATTRIBUTES secAtt;
	secAtt.nLength = 0;
	secAtt.lpSecurityDescriptor = NULL;
	secAtt.bInheritHandle = TRUE;
	hFile = CreateFile(argv[1], GENERIC_ALL, 0, &secAtt, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		_tprintf(_T("cannot open the file error number:%d"), GetLastError());
		_tprintf(_T("for more info refer ERROR LOOKUP"));
		getchar();
		return FALSE;
	}
	//printf("%S\n", hFile);
	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	if (!CreateProcess(_T("C:/Users/SANJAY KUMAR/source/repos/CDAC-NCR-Assignments/Windows/Assignment1/Assignmentquestionchild11/a.exe"), (LPTSTR)&hFile, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		_tprintf(_T("cannot create process error number:%d"), GetLastError());
		_tprintf(_T("for more info refer ERROR LOOKUP"));
		getchar();
		return FALSE;
	}
	printf("\n process created succesfully");
	getchar();
	return 0;
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
