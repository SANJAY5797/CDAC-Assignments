// Assignmentquestion17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>
long g_x=0;
DWORD WINAPI Threadfun1(LPVOID param)
{
	InterlockedExchangeAdd(&g_x, 1);
	//g_x++;
	return 0;
}
DWORD WINAPI Threadfun2(LPVOID param)
{
	InterlockedExchangeAdd(&g_x, 1);
	//g_x++;
	return 0;
}
int main()
{
	DWORD dwThreadId1, dwThreadId2;
	HANDLE hThread1, hThread2;
	HANDLE hArrayThread[2];
	while (1)
	{
		g_x = 0;
		hThread1 = CreateThread(
			NULL,
			0,
			Threadfun1,
			NULL,
			0,
			&dwThreadId1
		);
		if (hThread1 == NULL)
		{
			printf("unable to create thread\n");
			return 1;
		}
		hThread2 = CreateThread(
			NULL,
			0,
			Threadfun2,
			NULL,
			0,
			&dwThreadId2
		);
		if (hThread2 == NULL)
		{
			printf("unable to create thread\n");
			return 1;
		}
		hArrayThread[0] = hThread1;
		hArrayThread[1] = hThread2;
		WaitForMultipleObjects(2, hArrayThread, TRUE, INFINITE);
		CloseHandle(hThread1);
		CloseHandle(hThread2);
		printf("g_x value is %ld\n", g_x);
		if (g_x == 1)
		{
			break;
		}
	}
	printf("waiting for user input\n");
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
