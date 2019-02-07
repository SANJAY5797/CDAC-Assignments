#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	char s[50];
	printf("Enter the strings\n");
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
	{
		printf("%s",s+i);
		for(int j=0;j<i;j++)
			printf("%c",s[j]);
		printf("\n");
	}
	// to stop console from closing
	system("pause");
	return 0;
}