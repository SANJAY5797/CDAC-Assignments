// Assignmentquestion21app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<windows.h>
#include <iostream>
#include "C:\Users\SANJAY KUMAR\source\repos\CDAC-NCR-Assignments\Windows\Assignment1\Assignmentquestion21dllsource\dllheader.h"
using namespace std;

int main()
{
	int nNum1, nNum2;
	cout << "enter the numbers\n";
	cin >> nNum1 >> nNum2;
	int nResult = add(nNum1, nNum2);
	cout << nResult << endl;
	nResult = sub(nNum1, nNum2);
	cout << nResult << endl;
	 nResult = mul(nNum1, nNum2);
	cout << nResult << endl;
	 nResult = division(nNum1, nNum2);
	cout << nResult << endl;
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
