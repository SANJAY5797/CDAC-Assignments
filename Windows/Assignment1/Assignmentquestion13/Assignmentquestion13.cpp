/* Assignmentquestion12.cpp : This file contains the 'main' function.
Program  create a thread in suspended state. Resume the thread after
5 seconds wait. The thread should print integers from 1 to 1000 and 
return normally. Use getchar() in process’s primary thread to wait for user input
and allow time for thread to return.

*/

#include "pch.h"
#include<windows.h>
#include<tchar.h>
#include <iostream>
DWORD WINAPI Thread_func(LPVOID param)
{
	int i = 0;
	for (; i <= 1000; i++)
	{
		_tprintf(TEXT("%d "), i);
	}
	_tprintf(TEXT("\n"));
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
		CREATE_SUSPENDED,
		&dwThread
	);
	if (NULL == hThread)
	{
		_tprintf(TEXT("unable to create the thread error is %d\n"), GetLastError());
		getchar();
		return 0;
	}
	Sleep(5000);
	DWORD dwRet =ResumeThread(hThread);
	DWORD dwRet2 = WaitForSingleObject(hThread, INFINITE);
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
