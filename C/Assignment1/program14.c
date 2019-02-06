#include <stdio.h>
#include<string.h>
void reverse(char s[])
{
	int i,j,c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
        c=s[i],s[i]=s[j],s[j]=c;
}
void itob(int number,char s[])
{
	int i=0;
	while(number>0)
	{
		if(number&1)
			s[i]='1';
		else
			s[i]='0';
		number=number/2;
		i++;
	}
	s[i]='\0';
	reverse(s);
	return ;
}
void itoh(int number,char s[])
{
	int i=0;
	while(number>0)
	{
		if((number%16)<=9)
		s[i]=((number%16)+'0');
		else
		{
			s[i]=(((number%16)-10)+'A');
		}
		number=number/16;
		i++;
	}
	s[i]='\0';
	reverse(s);
	return ;
}
int main(int argc, char const *argv[])
{
	char res1[100],res2[100];	
	int number1,number2;
	printf("enter the number\n");
	scanf("%d",&number1);
	itob(number1,res1);
	printf("%s\n", res1);
	printf("enter the number\n");
	scanf("%d",&number2);
	itoh(number2,res2);
	printf("%s\n", res2);
	// to stop console from closing
	system("pause");
	return 0;
}