#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int any(char s[50],char b[10])
{
	int i,j;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==b[0])
		{
			int index=i;
			for(j=0;j<strlen(b)&&i<strlen(s);i++,j++)
			{
				if(s[i]!=b[j])break;
			}
			if(j==strlen(b))
				return index;
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	printf("Enter the strings\n");
	char s[50],c,b[10];
	scanf("%[^\n]s",s);
	scanf("%s",b);
	int res=any(s,b);
	if(res==-1)
		printf("Not found\n");
	else
	printf("result is %d\n", res);
	//to stop console from closing
	system("pause");
	return 0;
}