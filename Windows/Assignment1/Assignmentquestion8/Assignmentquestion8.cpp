// Assignmentquestion8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>

int main(int argc,char *argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	/*if (argc != 2)
	{
		_tprintf(TEXT("number of arguments are not enough\n"));
		_tprintf(TEXT("the error number is %d\n"), GetLastError());
		getchar();
		return FALSE;
	}*/	
	WCHAR var[50] ;
	wcscpy_s(var, L"calc.exe");
	BOOL bProcess = CreateProcessW(
		NULL,
		var,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	);
	if (bProcess==0) {
		_tprintf(TEXT("process creation error\n"));
		_tprintf(TEXT("the error number is %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf_s(TEXT("handle of the process is %d \n"), pi.hProcess);
	_tprintf_s(TEXT("process ID of the process is %d \n"), pi.dwProcessId);
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
