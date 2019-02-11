#include<stdio.h>
#include<stdlib.h>
void removeComments()
{
	FILE *fp=NULL,*rp=NULL;
	// opening the files in append mode
	fp=fopen("file2.txt","a+");
	rp=fopen("output2.txt","a+");
	// check if files are opened correctly
	if(fp==NULL)
	{
		perror("Error while opening the file\n");
		exit(-1);
	}
	if(rp==NULL)
	{
		perror("error while opening the file\n");
		exit(-1);
	}
	char ch;
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='/')
		{
			char ch2;
			ch2=fgetc(fp);
			if(ch2!=EOF)
			{
				if(ch2=='/')// to check if comment is single line comment
				{
					char ch3;
					while(((ch3=fgetc(fp))!=EOF)&&(ch3!='\n'))
					{

					}
				}
				else if(ch2=='*')// to check if comment is multiline comment
				{
					char ch4;
					while(((ch4=fgetc(fp))!=EOF)&&(ch4!='*'))
					{
						//nothing goes here
						// checking until we encounter closing multiline comment
					}
					ch4=fgetc(fp);
					if(ch=='/')
					{
						//DO NOTHING
						//encountered end of the multiline comment
					}
				}
				else
				{
					// storing the characters in another file
					fputc(ch2,rp);
				}
			}
		}
		else
		{
			fputc(ch,rp);
		}
	}
	// closing the files
	fclose(fp);
	fclose(rp);
	return ;
}