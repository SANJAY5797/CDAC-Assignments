#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void findMatchingAndReplace()
{
	FILE *fp=NULL,*rp=NULL;
	// opening the file in append mode to read and write
	fp=fopen("file3.txt","a+");
	rp=fopen("output3.txt","a+");
	// check if file is opened correctly
	if(fp==NULL)
	{
		perror("error while opening the file\n");
		exit(-1);// returning and telling os of the abnormal exit
	}
	if(rp==NULL)
	{
		perror("error while opening the file\n");
		exit(-1);
	}
	// taking the word as input from the user and storing in character array
	printf("Enter the word you want to rotate\n");
	char str[20];
	scanf("%s",str);
	printf("%s\n",str );
	char ch;
	while((ch=fgetc(fp))!=EOF)  // reading each character until end of file is reached
	{
		if(ch==str[0]) ///check if the first occurence of word is matched
		{
			int store=ftell(fp);// use this positon later to store the string
			int i=1,size=strlen(str);
			while(i<size&&((ch=fgetc(fp))!=EOF)&&ch==str[i])
			{
				i++; // checking the match of word with the file contents
			}
			if(i==size) // found a match
			{
				i=size-1;
				while(i>=0)
				{
					fputc(str[i],rp);
					i--;
				}
				//fputc(ch,rp);
			}
			else // mismatch so storing only first character
			{
				fputc(ch,rp);
				fseek(fp,store+1,SEEK_SET);//setting position to be the next position to the first match
			}
		}
		else
		{
			fputc(ch,rp);
		}
	}
	// closing the files
	fclose(rp);
	fclose(fp);

	// opening the files to reflect the changes in original text file
	rp=fopen("temp3.txt","r");
	fp=fopen("file3.txt","w+");
	while((ch=fgetc(rp))!=EOF)
	{
		fputc(ch,fp);
	}
	fclose(rp);
	fclose(fp);
}