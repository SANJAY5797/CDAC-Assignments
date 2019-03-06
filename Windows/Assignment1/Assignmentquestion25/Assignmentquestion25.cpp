// Assignmentquestion25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>
using namespace std;

DWORD WINAPI ThreadEntryPoint1(LPVOID param)
{
	cout << "thread one is being created successfully\n";
	cout << "here is the second line of thread 1\n";
	return 0;
}
DWORD WINAPI ThreadEntryPoint2(LPVOID param)
{
	cout << "thread two is being created successfully\n";
	cout << "here is the second line of thread 2\n";
	return 0;
}
DWORD WINAPI ThreadEntryPoint3(LPVOID param)
{
	cout << "thread three is being created successfully\n";
	Sleep(4000);
	cout << "here is the second line of thread 3\n";
	return 0;
}
DWORD WINAPI ThreadEntryPoint4(LPVOID param)
{
	cout << "thread 4 is being created successfully\n";
	Sleep(3000);
	cout << "here is the second line of thread 4\n";
	return 0;
}

DWORD WINAPI ThreadEntryPoint5(LPVOID param)
{
	cout << "thread 5 is being created successfully\n";
	Sleep(2000);
	cout << "here is the second line of thread 5\n";
	return 0;
}
DWORD WINAPI ThreadEntryPoint6(LPVOID param)
{
	cout << "thread 6 is being created successfully\n";
	Sleep(3000);
	cout << "here is the second line of thread 6\n";
	return 0;
}

DWORD WINAPI ThreadEntryPoint7(LPVOID param)
{
	cout << "thread 7 is being created successfully\n";
	Sleep(4000);
	cout << "here is the second line of thread 7\n";
	return 0;
}
DWORD WINAPI ThreadEntryPoint8(LPVOID param)
{
	cout << "thread 8 is being created successfully\n";
	Sleep(3000);
	cout << "here is the second line of thread 8\n";
	return 0;
}
int main()
{
	HANDLE hArrayThread[2];
	HANDLE hThreadStatus1, hThreadStatus2, hThreadStatus3, hThreadStatus4,
		hThreadStatus5, hThreadStatus6,hThreadStatus7,hThreadStatus8;
	DWORD dwThread1, dwThread2, dwThread3, dwThread4, dwThread5, dwThread6,dwThread7,dwThread8;
	
	

	//FIRST TASK
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

	hArrayThread[0] = hThreadStatus1;
	hArrayThread[1] = hThreadStatus2;

	WaitForMultipleObjects(2, hArrayThread, TRUE, INFINITE);
	CloseHandle(hThreadStatus1);
	CloseHandle(hThreadStatus2);

	//second TASK

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
		cout << "thread creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}

	//creation of 4 thread
	hThreadStatus4 = CreateThread(
		NULL,
		0,
		ThreadEntryPoint4,
		NULL,
		0,
		&dwThread4
	);
	if (INVALID_HANDLE_VALUE == hThreadStatus4)
	{
		cout << "thread four creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}

	hArrayThread[0] = hThreadStatus3;
	hArrayThread[1] = hThreadStatus4;

	
	WaitForMultipleObjects(2, hArrayThread, FALSE, INFINITE);
	CloseHandle(hThreadStatus3);
	CloseHandle(hThreadStatus4);


	///third task

	//creation of 5th thread
	hThreadStatus5 = CreateThread(
		NULL,
		0,
		ThreadEntryPoint5,
		NULL,
		0,
		&dwThread5
	);
	if (INVALID_HANDLE_VALUE == hThreadStatus5)
	{
		cout << "thread creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}

	//creation of 6 thread
	hThreadStatus6 = CreateThread(
		NULL,
		0,
		ThreadEntryPoint6,
		NULL,
		0,
		&dwThread6
	);
	if (INVALID_HANDLE_VALUE == hThreadStatus6)
	{
		cout << "thread six creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}

	hArrayThread[0] = hThreadStatus5;
	hArrayThread[1] = hThreadStatus6;


	WaitForMultipleObjects(2, hArrayThread, FALSE, INFINITE);
	CloseHandle(hThreadStatus5);
	CloseHandle(hThreadStatus6);

	//4th task


	//creation of 7th thread
	hThreadStatus7 = CreateThread(
		NULL,
		0,
		ThreadEntryPoint7,
		NULL,
		0,
		&dwThread7
	);
	if (INVALID_HANDLE_VALUE == hThreadStatus7)
	{
		cout << "thread creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}

	//creation of 8 thread
	hThreadStatus8 = CreateThread(
		NULL,
		0,
		ThreadEntryPoint8,
		NULL,
		0,
		&dwThread8
	);
	if (INVALID_HANDLE_VALUE == hThreadStatus8)
	{
		cout << "thread six creation failed with error " << GetLastError() << endl;
		getchar();
		return 1;
	}

	hArrayThread[0] = hThreadStatus7;
	hArrayThread[1] = hThreadStatus8;


	WaitForMultipleObjects(2, hArrayThread, FALSE, INFINITE);
	CloseHandle(hThreadStatus7);
	CloseHandle(hThreadStatus8);
	system("pause");
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
