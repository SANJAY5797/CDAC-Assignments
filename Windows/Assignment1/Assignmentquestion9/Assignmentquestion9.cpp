// Assignmentquestion9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<windows.h>
#include <iostream>
#include<tchar.h>

int main()
{
	BOOL bProcess;
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	TCHAR szCommandLine[] = TEXT("Notepad");
	bProcess = CreateProcess(
		NULL,
		szCommandLine,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	);
	if (!bProcess)
	{
		_tprintf(TEXT("process creation error\n"));
		_tprintf(TEXT("the error number is %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(TEXT("handle of the process is %d\n"),pi.hProcess );
	_tprintf(TEXT("process id of the process is %d\n"),pi.dwThreadId );


	_tprintf(TEXT("using GetprocessId : process id is %d\n"),GetProcessId(pi.hProcess));
	_tprintf(TEXT("using GetThreadId : thread id is %d\n"), GetThreadId(pi.hProcess));

	_tprintf(TEXT("using GetCurrentprocessId of calling process(main) : current process id is %d\n"), GetCurrentProcessId());
	_tprintf(TEXT("using GetCurrentthreadId of calling process(main) : current thread id is %d\n"), GetCurrentThreadId());


	DWORD dwRet = WaitForSingleObject(pi.hProcess, INFINITE);
	_tprintf(TEXT("waiting for single object output %d\n"), dwRet);
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
