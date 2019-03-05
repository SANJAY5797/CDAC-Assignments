// Assignmentquestion19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>
using namespace std;
const int COUNT = 10;
int nSharedSum = 0;
CRITICAL_SECTION g_csLock;
DWORD WINAPI FirstThread(PVOID pvParam) {
	EnterCriticalSection(&g_csLock);
	nSharedSum = 0;
	for (int n = 1; n <= COUNT; n++) {
		nSharedSum += n;
	}
	LeaveCriticalSection(&g_csLock);
	return(nSharedSum);
}
DWORD WINAPI SecondThread(PVOID pvParam) {
	EnterCriticalSection(&g_csLock);
	nSharedSum = 0;
	for (int n = 1; n <= COUNT; n++) {
		nSharedSum += n;
	}
	LeaveCriticalSection(&g_csLock);
	return(nSharedSum);
}

int main()
{
	DWORD dwThread1, dwThread2;
	HANDLE hThreadId1, hThreadId2;
	HANDLE hArrayThread[2];
	DWORD lpExitCode1, lpExitCode2;

	InitializeCriticalSectionAndSpinCount(&g_csLock, 4000);

	hThreadId1 = CreateThread(
		NULL,
		0,
		FirstThread,
		NULL,
		0,
		&dwThread1
	);
	cout << nSharedSum << endl;
	hThreadId2 = CreateThread(
		NULL,
		0,
		SecondThread,
		NULL,
		0,
		&dwThread2
	);
	cout << nSharedSum << endl;
	hArrayThread[0] = hThreadId1;
	hArrayThread[1] = hThreadId2;

	//closing handles of both the threads
	CloseHandle(hThreadId1);
	CloseHandle(hThreadId2);
	cout << nSharedSum << endl;

	///waiting for both the threads to complete
	WaitForMultipleObjects(2,hArrayThread,FALSE,5000);
	printf("waiting for user input before exiting\n");
	cout << nSharedSum << endl;
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
