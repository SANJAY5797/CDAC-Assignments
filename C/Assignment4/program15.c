#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char rev[200];
int strcomp(char s[100],char t[100])
{
	int i=0;
	//running the loop till the characters do not match or reach the end of loop
	while(s[i]==t[i])
	{
		if(s[i]=='\0')
			return 0;
		i++;
	}
	//returning difference
	return s[i]-t[i];
}
char *strev(char s[100])
{
	int i=0,j=strlen(s)-1;
	while(i<strlen(s))
	{
		//storing the each character in reverse order
		rev[i]=s[j];
		i++;j--;
	}
	//returning the address
	return rev;
}
char *strconcat(char *src,char *dest)
{
	int i,j;
	//running till the end of the destination string
	for (i = 0; dest[i] != '\0'; i++)
        ;
	//storing the character next to the last character of the original destination string
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
	//putting a null character to mark the end
    dest[i+j] = '\0';
    return dest;
}
void strcopy(char *a,char *b)
{
	int i=0;
	//copying character by character till the null character is encountered
	while((a[i]=b[i])!='\0')
	i++;
	return ;
}
int main(int argc, char const *argv[])
{
	char s[100],t[200],*cat;
	printf("Enter the strings to compare\n");
	scanf("%s",s);
	scanf("%s",t);
	if(strcomp(s,t)==0)
	{
		printf("The strings are equal\n");
	}
	else
	{
		printf("The strings are unequal\n");
	}
	printf("enter the string to reverse\n");
	scanf("%s",s);
	char *rev=strev(s);
	printf("reverse of string %s is\n", s);
	printf("%s\n", rev);
	printf("enter the strings to concatenate\n");
	scanf("%s",s);
	scanf("%s",t);
	cat=strconcat(s,t);
	printf("Concatenated string is\n");
	printf("%s\n", cat);
	strcopy(cat,"sanjay kumar");
	printf("copied string is\n");
	printf("%s\n", cat);
	/// to stop console from closing
	system("pause");
	return 0;
}
