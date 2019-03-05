// Assignmentquestion20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include<windows.h>
#include<cstdlib>
#include <queue>

using namespace std;

SRWLOCK g_srwLock;
CONDITION_VARIABLE g_cvReadyToConsume;
CONDITION_VARIABLE g_cvReadyToProduce;

volatile LONG isRunning = TRUE;

//handles to all reader/writer threads
HANDLE g_hThreads[MAXIMUM_WAIT_OBJECTS];

//number of reader/writer threads
int g_nNumThreads = 0;

// size limit of shared queue
#define	QSIZELIMIT 5

//object
struct object {
	int threadNo;
	int element;
};

//shared queue of integer variables
queue<object> gSharedQ;

DWORD WINAPI WriterThread(LPVOID lparam)
{
	int threadNo = PtrToUlong(lparam);

	for (int element = 1; isRunning; element++)
	{
		object obj = { threadNo,element };

		AcquireSRWLockExclusive(&g_srwLock);

		//check if Q is full
		if (gSharedQ.size() >= QSIZELIMIT && isRunning) {
			cout << "writer thread " << threadNo << " Q is full can't write to the queue "<<endl;
			//wait for element to be consumed by reader thread
			SleepConditionVariableSRW(&g_cvReadyToProduce, &g_srwLock, INFINITE, 0);
		}
		if (!isRunning) {
			cout << "writer thread " << threadNo << "bye" << endl;
			ReleaseSRWLockExclusive(&g_srwLock);

			WakeAllConditionVariable(&g_cvReadyToProduce);

			return 0;
		}
		else {
			// add to Q
			gSharedQ.push(obj);

			cout << "writer thread " << threadNo << " produced " << element << endl;

			ReleaseSRWLockExclusive(&g_srwLock);

			WakeAllConditionVariable(&g_cvReadyToConsume);

			Sleep(1500);
		}
	}
	cout << "writer thread " << threadNo << "bye " << endl;

	return 1;
}

DWORD WINAPI ReaderThread(LPVOID param)
{
	int threadNo = PtrToUlong(param);

	for (int element = 1; isRunning; element++)
	{
		AcquireSRWLockShared(&g_srwLock);

		if (gSharedQ.empty() && isRunning)
		{
			cout << "reader thread " << threadNo << " Nothing to consume " << endl;
			//wait till something is there to consume
			SleepConditionVariableSRW(&g_cvReadyToConsume, &g_srwLock, INFINITE, CONDITION_VARIABLE_LOCKMODE_SHARED);
		}
		if (!isRunning) {
			cout << "reader thread " << threadNo << "bye " << endl;


			ReleaseSRWLockShared(&g_srwLock);

			WakeConditionVariable(&g_cvReadyToConsume);

			return 0;
		}
		else {
			//read from Q
			object obj = gSharedQ.front();

			//cout<<"reader thread "<<threadNo <<" consumed "<<obj.e<<endl;
			cout << "reader thread consumed\n";
			gSharedQ.pop();
			ReleaseSRWLockShared(&g_srwLock);
			WakeConditionVariable(&g_cvReadyToProduce);
		}
		Sleep(2500); //wait before reading another element
	}
	return 0;
}
BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)
{
		
	switch(dwCtrlType)
		{ 
		case CTRL_C_EVENT:
			cout << "[CTRL]+C\n";
			InterlockedExchange(&isRunning, FALSE);

			// free all threads waiting on conditon variables
			WakeAllConditionVariable(&g_cvReadyToConsume);
			WakeAllConditionVariable(&g_cvReadyToProduce);
			return TRUE;
		default:
			// pass signal on to the next handler
			return FALSE;
	}
}

int main()
{
	SetConsoleCtrlHandler(HandlerRoutine, TRUE);
	//initialize slim reader writer lock
	InitializeSRWLock(&g_srwLock);
	//cout << "hi" << endl;
	//init producer and consumer condition variables
	InitializeConditionVariable(&g_cvReadyToConsume);
	InitializeConditionVariable(&g_cvReadyToProduce);

	DWORD dwThreadId;
	for (int i = 0; i < 4; i++)
	{
		g_hThreads[g_nNumThreads++] = CreateThread(NULL, 0, WriterThread, (PVOID)(INT_PTR)i, 0, &dwThreadId);

	}
	for (int i = 0; i < 4; i++)
	{
		g_hThreads[g_nNumThreads++] = CreateThread(NULL, 0, ReaderThread, (PVOID)(INT_PTR)i, 0, &dwThreadId);

	}
	WaitForMultipleObjects(g_nNumThreads, g_hThreads, TRUE, INFINITE);
	while(g_nNumThreads--)
	{
		CloseHandle(g_hThreads[g_nNumThreads]);
	}
	getchar();

	return 1;
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
