// Assignmentquestion28.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<Windows.h>
#include<iostream>
using namespace std;

#define THREAD_COUNT 8
HANDLE ghMutex;
DWORD WINAPI ThreadProc(LPVOID);
int main()
{
	HANDLE aThread[THREAD_COUNT];
	DWORD dwThID;

	ghMutex = CreateMutex(NULL, FALSE, NULL);
	if (NULL == ghMutex)
	{
		cout << "mutex creation failed with error no " << GetLastError() << endl;
		getchar();
		return FALSE;
	}
	for (int i = 0; i < THREAD_COUNT; i++)
	{
		aThread[i] = CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwThID);
		if (NULL == aThread[i])
		{
			printf("\n thread %d creation error %d", i, GetLastError());
			getchar();
			return FALSE;
		}
	}
	WaitForMultipleObjects(THREAD_COUNT, aThread, TRUE, INFINITE);
	for (int i = 0; i < THREAD_COUNT; i++)
	{
		CloseHandle(aThread[i]);
	}
	CloseHandle(ghMutex);
	getchar();
	return 0;
}
DWORD WINAPI ThreadProc(LPVOID lppar)
{
	UNREFERENCED_PARAMETER(lppar);
	DWORD dwRes=0, dwCount = 0;
	BOOL bReleaseStatus = 0;
	while (dwCount < 5)
	{
		dwRes = WaitForSingleObject(ghMutex, INFINITE);
		switch (dwRes)
		{
		case WAIT_OBJECT_0:
			printf("\n the thread %d wait is sucessful", GetCurrentThreadId());
			dwCount++;
			Sleep(1000);
			bReleaseStatus = ReleaseMutex(ghMutex);
			if (0==bReleaseStatus)
			{
				cout << "ReleaseMutex failed with error " << GetLastError() << endl;
				getchar();
				return FALSE;
			}
			break;
		case WAIT_ABANDONED:
			printf("\n thread %d wait timeout ", GetCurrentThreadId());
			return FALSE;
			break;

		}
	}
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
