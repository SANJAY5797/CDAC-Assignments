/*
	This program explains the use of expandenvironmentstrings function
	and display the environment variables passed from console
*/
#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>

void DumpEnvStrings(TCHAR *envVariables[])
{
	int iCurrentPoint = 0;
	PTSTR *pElement = (PTSTR*)envVariables;
	PTSTR* pCurrentPoint = NULL;
	while (pElement != NULL)
	{
		pCurrentPoint = (PTSTR *)(*pElement);
		if (pCurrentPoint == NULL)
		{
			pElement = NULL;
		}
		else {
			_tprintf(TEXT("%u %s\n"), iCurrentPoint, pCurrentPoint);
			iCurrentPoint++;
			pCurrentPoint++;
		}
		pElement++;
	}
}
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	// printing environment variables passed to the console application using user defined function
	DumpEnvStrings(env);
	///expanding environment string using ExpandEnvironmentStrings
	TCHAR envVarString[] = TEXT("%VS140COMNTOOLS%");
	TCHAR envVarString2[] = TEXT("%OneDrive%");
	TCHAR buffer[MAX_PATH];
	DWORD dwRet;
	dwRet = ExpandEnvironmentStrings(envVarString, buffer, MAX_PATH);
	if (!dwRet)
	{
		printf("%d \n", GetLastError());
	}
	else
	{
		printf("%S\n", buffer);
	}
	dwRet = ExpandEnvironmentStrings(envVarString2, buffer, MAX_PATH);
	if (!dwRet)
	{
		printf("%d \n", GetLastError());
	}
	else
	{
		printf("%S\n", buffer);
	}

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
