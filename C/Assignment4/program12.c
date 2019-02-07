#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void delete(char s[50],char c)
{
	int k=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]==c)
			continue;
		s[k++]=s[i];
	}
	s[k]='\0';
	return ;
}
void delete2(char s[50],char b[50])
{
	for(int i=0;i<strlen(b);i++)
	{
		delete(s,b[i]);
	}
	return ;
}	
int main(int argc, char const *argv[])
{
	printf("Enter the strings\n");
	char s[50],c,b[50];
	scanf("%s",s);
	scanf("%s",b);
	delete2(s,b);
	printf("Resultant string is \n");
	printf("%s\n", s);
	//to stop console from closing
	system("pause");
	return 0;
}