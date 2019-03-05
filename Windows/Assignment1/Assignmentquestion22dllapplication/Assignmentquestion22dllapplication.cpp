// Assignmentquestion22dllapplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<windows.h>
#include "C:\Users\SANJAY KUMAR\source\repos\CDAC-NCR-Assignments\Windows\Assignment1\Assignmentquestion22dll\dllheader2.h"
#include <iostream>
using namespace std;

typedef int(*add1)(int , int );
typedef int(*sub1)(int , int );
typedef int(*mul1)(int , int );
typedef int(*division1)(int , int );
typedef int(*MYPROC)(int , int );

int main()
{
	HMODULE hDll;
	int nResult;
	MYPROC ADD, SUB, MUL, DIV;
	add1 ptr1;
	sub1 ptr2;
	mul1 ptr3;
	division1 ptr4;

	int nLeft, nRight;
	cin >> nLeft >> nRight;
	hDll = LoadLibraryEx(
		TEXT("C:\\Users\\SANJAY KUMAR\\source\\repos\\CDAC-NCR-Assignments\\Windows\\Assignment1\\Debug\\Assignmentquestion22dll.dll"),
		NULL,
		NULL
	);
	if (NULL == hDll)
	{
		cout << "Loadlibraryex failed with error " << GetLastError() << endl;
		getchar();
		return 0;
	}
	ADD = (MYPROC)GetProcAddress(hDll, (LPSTR)"add");
	if (NULL == ADD)
	{
		cout << "can't get the proc address add with error " << GetLastError() << endl;
		getchar();
		return 1;
	}
	nResult = ADD(nLeft, nRight);
	cout << "addition result is " << nResult << endl;
	ptr2 = (MYPROC)GetProcAddress(hDll, (LPSTR)"sub");
	if (NULL == ptr2)
	{
		cout << "can't get the proc address SUB with error " << GetLastError() << endl;
		getchar();
		return 1;
	}
	nResult = ptr2(nLeft, nRight);
	cout << "subtraction result is " << nResult << endl;
	ptr3 = (MYPROC)GetProcAddress(hDll, (LPSTR)"mul");
	if (NULL == ptr3)
	{
		cout << "can't get the proc address mul with error " << GetLastError() << endl;
		getchar();
		return 1;
	}
	nResult = ptr3(nLeft, nRight);
	cout << "addition result is " << nResult << endl;
	ptr4 = (MYPROC)GetProcAddress(hDll, (LPSTR)"division");
	if (NULL == ptr4)
	{
		cout << "can't get the proc address div with error " << GetLastError() << endl;
		getchar();
		return 1;
	}
	nResult = ptr4(nLeft, nRight);
	cout << "division result is " << nResult << endl;
	system("pause");
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
