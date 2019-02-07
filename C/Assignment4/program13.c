#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void expand(char s1[50],char s2[100])
{
	int i=0,k=1;
	while(k<strlen(s1))
	{
		if(s1[k]=='-')
		{
			char temp=s1[k+1];
			char start=s1[k-1];
			while(start!=temp)
			{
				s2[i++]=start;
				start++;
			}
			s2[i++]=start;
			k++;
		}
		else
		{
			if(s1[k-2]!='-')
			s2[i++]=s1[k-1];
		}
		k++;
	}
	if(s1[strlen(s1)-2]!='-')
		s2[i++]=s1[strlen(s1)-1];
	s2[i]='\0';
}
int main(int argc, char const *argv[])
{
	char s1[50],s2[100];
	printf("Enter the string\n");
	scanf("%[^\n]s",s1);
	expand(s1,s2);
	printf("resultant string is\n");
	printf("%s\n",s2 );
	// to stop console from closing
	system("pause");
	return 0;
}