#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int replace(char s[50])
{
	int count=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]==' ')
		{
			s[i]='-';
			count++;
		}
	}
	return count;
}
int main(int argc, char const *argv[])
{
	char s[50];
	printf("Enter the string\n");
	scanf("%[^\n]s",s);
	int res=replace(s);
	printf("result is\n");
	printf("%s\n", s);
	printf("%d\n",res );
	//to stop console from closing
	system("pause");
	return 0;
}