#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<iostream>
using namespace std;
DWORD WINAPI thread_func(LPVOID lppar)
{
	printf("entered into the thread");
	return 0;
}
int main()
{
	DWORD dwThId;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThId);
	SetThreadPriority(hThread, THREAD_PRIORITY_LOWEST);
	if (INVALID_HANDLE_VALUE == hThread)
	{
		cout << "thread creation error" << endl;
		cout << GetLastError() << endl;
		//printf_s("Thread creation error");
		//printf_s("\n the error number is: %d", GetLastError());
		getchar();
		return FALSE;
	}
	WaitForSingleObject(hThread, INFINITE);
	getchar();
	return 0;
}