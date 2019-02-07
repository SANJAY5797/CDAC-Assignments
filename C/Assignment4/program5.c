#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char const *argv[])
{
	char s[20];
	int num;
	printf("Enter the string\n");
	/*scanf("%d",&num);
	printf("%d\n", num);*/
	scanf("%s",s);
	printf("%d\n", strlen(s));
	for(int i=0;i<strlen(s);i++)
	{
		if(islower(s[i]))
		{
			s[i]=(char)toupper(s[i]) ;
		}
		else if(isupper(s[i]))
		{
			s[i]=(char)tolower(s[i]); 
		}
	}
	printf("resultant string is\n");
	printf("%s\n",s );
	// to stop console from closing
	system("pause");
	return 0;
}