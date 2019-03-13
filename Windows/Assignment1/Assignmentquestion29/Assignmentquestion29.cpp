// Assignmentquestion29.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
/*Write a program where only 2 out of 4 threads at a time are allowed to access shared resources.
Use semaphore object to count the no of allowed threads to access shared resources.
Use the shared resource for 200 ms with Sleep(200). Use WaitForSingleObject to get the ownership of semaphore object.
*/
#include<Windows.h>
#include<stdio.h>
#include<iostream>
#define MAX_SEM_COUNT 1
#define THREAD_COUNT 4
using namespace std;
HANDLE ghSemaphore;
DWORD WINAPI ThreadProc(LPVOID);
int main()
{
	HANDLE aThread[THREAD_COUNT];
	DWORD dwThID;

	ghSemaphore = CreateSemaphore(NULL, MAX_SEM_COUNT, MAX_SEM_COUNT, NULL);
	if (NULL == ghSemaphore)
	{
		printf("\n semaphore creation error %d", GetLastError());
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
	CloseHandle(ghSemaphore);
	getchar();
	return 0;
}
DWORD WINAPI ThreadProc(LPVOID lppar)
{
	UNREFERENCED_PARAMETER(lppar);
	DWORD dwRes;
	BOOL b = TRUE;
	BOOL bReleaseStatus = 0;
	while (b)
	{
		dwRes = WaitForSingleObject(ghSemaphore, INFINITE);
		switch (dwRes)
		{
		case WAIT_OBJECT_0:
			printf("\n the thread %d wait is sucessful", GetCurrentThreadId());
			b = FALSE;
			Sleep(20000);
			bReleaseStatus = ReleaseMutex(ghSemaphore);
			if (0 == bReleaseStatus)
			{
				cout << "ReleaseMutex failed with error " << GetLastError() << endl;
				getchar();
				return FALSE;
			}
			break;
		case WAIT_TIMEOUT:
			printf("\n thread %d wait timeout ", GetCurrentThreadId());
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
