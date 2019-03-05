// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "dllheader2.h"
#include<iostream>
using namespace std;
int add(int nLeft, int nRight)
{
	return nLeft + nRight;
}
int sub(int nLeft, int nRight)
{
	return nLeft - nRight;
}
int mul(int nLeft, int nRight)
{
	return nLeft * nRight;
}
int division(int nLeft, int nRight)
{
	return nLeft / nRight;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		cout << "process is attached\n";
		break;
    case DLL_THREAD_ATTACH:
		cout << "thread is attached\n";
		break;
    case DLL_THREAD_DETACH:
		cout << "thread is detached\n";
		break;
    case DLL_PROCESS_DETACH:
		cout << "process is detached\n";
        break;
    }
    return TRUE;
}

