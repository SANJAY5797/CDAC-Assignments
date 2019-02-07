#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int n;
	printf("enter the value of n\n");
	scanf("%d",&n);
	char *s[n];
	for(int i=0;i<n;i++)
	{
		s[i]=(char *)malloc(sizeof(char)*10);
		scanf("%s",s[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("%s\n",s[i] );
	}
	/*to free the memory allocated*/
	for(int i=0;i<n;i++)
	{
		free(s[i]);
	}
	free(s);
	//to stop console from closing
	system("pause");
	return 0;
}