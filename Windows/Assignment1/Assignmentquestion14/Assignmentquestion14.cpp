// Assignmentquestion12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<windows.h>
#include<tchar.h>
#include <iostream>
DWORD WINAPI Thread_func(LPVOID param)
{
	_tprintf(TEXT("secondary thread here\n"));
	DWORD dwExitCode = 31;
	ExitThread(dwExitCode);
	_tprintf(TEXT("last line in secondary thread\n"));
	return 0;
}
int main()
{
	DWORD dwThread;
	HANDLE hThread;
	hThread = CreateThread(
		NULL,//default security
		0,
		Thread_func,// entry point for the function
		NULL,
		0,
		&dwThread
	);
	if (NULL == hThread)
	{
		_tprintf(TEXT("unable to create the thread error is %d\n"), GetLastError());
		getchar();
		return 0;
	}
	DWORD dwExit;
	GetExitCodeThread(hThread, &dwExit);
	_tprintf(TEXT("secondary thread exit code using Getexitthread api is %u\n"), dwExit);
	DWORD dwRe = WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
	_tprintf(TEXT("thread handle has been closed\n"));
	system("pause");
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
