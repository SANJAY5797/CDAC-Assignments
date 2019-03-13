// Assignmentquestion16parent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
using namespace std;
int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (!CreateProcess(TEXT("C:/Users/SANJAY KUMAR/source/repos/CDAC-NCR-Assignments/Windows/Assignment1/Assignmentquestion16child/a.exe"), (LPWSTR)(&pi.hProcess), NULL, NULL, TRUE, HIGH_PRIORITY_CLASS, NULL, NULL, &si, &pi))
	{

		printf(" \n process creation error");
		printf("\n the error number is: %d", GetLastError());
		getchar();
		return FALSE;
	}
	SetPriorityClass(pi.hProcess, BELOW_NORMAL_PRIORITY_CLASS);
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
