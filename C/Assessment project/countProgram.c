#include<stdio.h>
#include<stdlib.h>
void count()
{
	FILE *fp=NULL;
	// opening the file in read mode
	fp=fopen("file1.txt","r");
	if(fp==NULL)
	{
		perror("error while opening the file\n");
		exit(-1);
	}
	int count_alpha=0,count_digit=0,count_spaces=0,count_special=0;
	char ch;
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch>='0'&&ch<='9')// all digits
			count_digit++;
		else if(ch==' ') // all spaces
			count_spaces++;
		else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) //all alphabets
			count_alpha++;
		else  // all special characters
			count_special++;
	}
	fclose(fp);
	printf("The total number of alphabets are %d\n",count_alpha);
	printf("The total number of digits are %d\n",count_digit);
	printf("The total number of spaces are %d\n",count_spaces);
	printf("The total number of special characters are %d\n",count_special);
	printf("**************\n\n\n");
}