#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int _tmain(int argc, char *argv[])
{
	printf("\n In child process");
	printf("%s\n", argv[0]);
	HANDLE hFile = (HANDLE)(*argv[0]);
	TCHAR buffer[] = TEXT("Hi the control is in child process");
	DWORD nbw;
	printf("Handle of the file is \n");
	printf("%s\n", hFile);
	BOOL ret = WriteFile(hFile, buffer, sizeof(buffer), &nbw, NULL);
	if (ret == 0)
	{
		printf("\ncannot write into the file");
		getchar();
		return FALSE;
	}
	printf("written succesfully");
	system("pause");
	return 0;
}
