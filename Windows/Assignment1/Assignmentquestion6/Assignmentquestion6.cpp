// Assignmentquestion6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<windows.h>
#include <iostream>
#include<tchar.h>

int _tmain(int argc,TCHAR *argv[],TCHAR *env[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (argc != 2)
	{
		_tprintf(TEXT("number of arguments are not enough\n"));
		_tprintf(TEXT("the error number is %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	if (!CreateProcess(
		NULL,
		argv[1],
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	)){
		_tprintf(TEXT("process creation error\n"));
		_tprintf(TEXT("the error number is %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf_s(TEXT("handle of the process is %d \n"), pi.hProcess);
	_tprintf_s(TEXT("process ID of the process is %d \n"), pi.dwProcessId);
	DWORD dwRet = WaitForSingleObject(
		pi.hProcess,
		INFINITE
	);
	_tprintf_s(TEXT("wait for single object output %d \n"),dwRet);
	getchar();
	system("pause");
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
