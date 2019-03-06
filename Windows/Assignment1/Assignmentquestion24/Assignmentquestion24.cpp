// Assignmentquestion24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>
using namespace std;
DWORD WINAPI ThreadEntryPoint1(LPVOID param)
{
	cout << "thread one is being created successfully\n";
	cout << "here is the second line\n";
	return 0;
}
DWORD WINAPI ThreadEntryPoint2(LPVOID param)
{
	cout << "thread two is being created successfully\n";
	cout << "here is the second line\n";
	return 0;
}
DWORD WINAPI ThreadEntryPoint3(LPVOID param)
{
	cout << "thread three is being created successfully\n";
	Sleep(2000);
	cout << "here is the second line\n";
	return 0;
}
int main()
{
	HANDLE hThreadStatus1,hThreadStatus2,hThreadStatus3;
	DWORD dwThread1,dwThread2,dwThread3;
	hThreadStatus1 = CreateThread(
		NULL,
		0,
		ThreadEntryPoint1,
		NULL,
		0,
		&dwThread1
	);
	if (INVALID_HANDLE_VALUE == hThreadStatus1)
	{
		cout << "thread creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}
	DWORD dwWaitStatus = WaitForSingleObject(hThreadStatus1, INFINITE);
	if (0 != dwWaitStatus)
	{
		cout << "wait for single object failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}
	//closing first thread handle
	CloseHandle(hThreadStatus1);

	//creation of second thread


	hThreadStatus2 = CreateThread(
		NULL,
		0,
		ThreadEntryPoint2,
		NULL,
		0,
		&dwThread2
	);
	if (INVALID_HANDLE_VALUE == hThreadStatus2)
	{
		cout << "thread two creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}
	DWORD dwWaitStatus2 = WaitForSingleObject(hThreadStatus2, 1000);
	if (0 != dwWaitStatus2)
	{
		cout << "wait for single object failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}
	//closing second thread handle
	CloseHandle(hThreadStatus2);
	//creation of third thread

	hThreadStatus3 = CreateThread(
		NULL,
		0,
		ThreadEntryPoint3,
		NULL,
		0,
		&dwThread3
	);
	if (INVALID_HANDLE_VALUE == hThreadStatus3)
	{
		cout << "thread three creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}
	DWORD dwWaitStatus3 = WaitForSingleObject(hThreadStatus3, 1000);
	if (0 != dwWaitStatus3)
	{
		cout << "wait for single object failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}
	//closing third thread handle
	CloseHandle(hThreadStatus3);

	//printing something before all threads are completed
	cout << "all threads handles have been closed\n";
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
