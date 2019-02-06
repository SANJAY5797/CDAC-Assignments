#include<stdio.h>
#include<string.h>

int main()
{
	char input[80];
	printf("Enter the string\n");
	scanf("%[^\n]s",input);
	int letter_count=0,digit_count=0,space_count=0,tab_count=0;
	for(register int i=0;i<strlen(input);i++)
	{
		if(input[i]==' ')
		{
			space_count++;
		}
		else if(input[i]=='\t')
		{
			tab_count++;
		}
		else if(input[i]>='0'&&input[i]<='9')
		{
			digit_count++;
		}
		else
		{
			letter_count++;
		}
	}
	printf("There are %d letters, %d digits, %d blanks %d tabs in the input string\n",letter_count,digit_count,space_count,tab_count);
	// to stop console from closing
	system("pause");
	return 0;
}