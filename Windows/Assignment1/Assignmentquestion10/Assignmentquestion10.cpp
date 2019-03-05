// Assignmentquestion10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<windows.h>
#include <iostream>
#include<tchar.h>
using namespace std;

int main()
{
	HANDLE hFile=NULL;
	LPCWSTR lpFile = L"newF.txt";
	SECURITY_ATTRIBUTES secProcess;
	secProcess.bInheritHandle = TRUE;
	secProcess.lpSecurityDescriptor = NULL;
	secProcess.nLength = sizeof(secProcess);
	hFile = CreateFileW(
		lpFile,
		GENERIC_READ,
		0,
		&secProcess,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (NULL == hFile)
	{
		cout << "error in creating the file with error " << GetLastError() << endl;
		getchar();
		return 0;
	}
	cout << "file created successfully\n";
	STARTUPINFO siProcess;
	
	PROCESS_INFORMATION piProcess;
	siProcess.cb = sizeof(siProcess);
	ZeroMemory(&siProcess, sizeof(siProcess));
	ZeroMemory(&piProcess, sizeof(piProcess));
	BOOL bCreateProc = CreateProcess(
		TEXT("C:\\WINDOWS\\system32\\notepad.exe"),
		NULL,
		NULL,
		NULL,
		TRUE,//setting inheritable property to true
		0,
		NULL,
		NULL,
		&siProcess,
		&piProcess
	);
	if (0 == bCreateProc)
	{
		cout << "create process failed with error " << GetLastError() << endl;
		getchar();
		return 0;
	}
	cout << "process created with handles inherited\n";
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
