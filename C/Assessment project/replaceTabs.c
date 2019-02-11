#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<stdlib.h>
void replaceTabs()
{
	FILE *fp=NULL,*rp=NULL;
	// opening the file in append mode to read and write
	fp=fopen("file4.txt","a+");
	rp=fopen("output4.txt","a+");
	// check if file is opened correctly
	if(fp==NULL)
	{
		perror("error while opening the file\n");
		exit(-1);
	}

	if(rp==NULL)
	{
		perror("error while opening the file\n");
		exit(-1);
	}
	char ch;
	while((ch=fgetc(fp))!=EOF)// reading each character until end of file is reached
	{
		if(ch=='\t') /// to check if a tab character is encountered
		{
			// replacing \t with two letters '\' and 't'
			char x='\\';
			fputc(x,rp);
			x='t';
			fputc(x,rp);
		}
		else
			fputc(ch,rp);
	}
	// closing fp files
	fclose(fp);
	fp=fopen("file4.txt","w");
	//setting the position to read
	fseek(rp,0,SEEK_SET);
	// making the changes to get reflected in the original file
	while((ch=fgetc(rp))!=EOF)
	{
		if(ch=='\t')
		{
			char x='\\';
			//printf("%d",ftell(fp));
			fputc(x,fp);
			x='t';
			fputc(x,fp);
		}
		else
			fputc(ch,fp);
	}
	// closing the files
	fclose(rp);
	fclose(fp);
}