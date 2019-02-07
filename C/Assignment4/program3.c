#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	char *s[]= {
		"we will teach you how to ",
"Move a mountain " ,
"Level a building " ,
"Erase the past ",
"Make a million " 
	};
	int count=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<strlen(s[i]);j++)
			if(s[i][j]=='e')
				count++;
	}
	printf("number of character e is %d\n", count);
	// to stop console from closing
	system("pause");
	return 0;
}