// Assignmentquestion26.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>
#define MAX_THREADS 3

using namespace std;
HANDLE hEvent;

DWORD WINAPI WordCount(PVOID param)
{
	//wait till one event becomes signalled
	WaitForSingleObject(hEvent, INFINITE);
	Sleep(2000);

	cout << "counting words\n";

	//to change event to signalled
	SetEvent(hEvent);

	return 1;
}
DWORD WINAPI SpellCheck(PVOID param)
{
	WaitForSingleObject(hEvent, INFINITE);
	Sleep(3000);

	cout << "checking spellings\n";

	//to change event to signalled
	SetEvent(hEvent);

	return 1;
}

DWORD WINAPI GrammarCheck(PVOID param)
{
	WaitForSingleObject(hEvent, INFINITE);
	Sleep(4000);
	cout << "checking grammar\n";

	SetEvent(hEvent);
	return 1;
}

int main(int argc,char *argv[])
{
	hEvent = CreateEvent(
		NULL,
		TRUE,//MANUAL RESET EVENT WILL BE CREATED
		FALSE, //INITIAL STATE NON SIGNALLED
		NULL
	);
	HANDLE hThread[MAX_THREADS];
	DWORD dwThread[MAX_THREADS];

	unsigned int i = 0;
	hThread[i] = CreateThread(
		NULL,
		0,
		WordCount,
		NULL,
		0,
		&dwThread[i]
	);

	if (INVALID_HANDLE_VALUE == hThread[i])
	{
		cout << "thread creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}


	i++;
	hThread[i] = CreateThread(
		NULL,
		0,
		SpellCheck,
		NULL,
		0,
		&dwThread[i]
	);

	if (INVALID_HANDLE_VALUE == hThread[i])
	{
		cout << "thread creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}

	i++;

	hThread[i] = CreateThread(
		NULL,
		0,
		GrammarCheck,
		NULL,
		0,
		&dwThread[i]
	);

	if (INVALID_HANDLE_VALUE == hThread[i])
	{
		cout << "thread creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}

	cout << "opening the file\n";
	Sleep(5000);

	SetEvent(hEvent);

	WaitForMultipleObjects(MAX_THREADS, hThread, TRUE,INFINITE );
	cout << "waiting for user input before exiting\n";
	
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
