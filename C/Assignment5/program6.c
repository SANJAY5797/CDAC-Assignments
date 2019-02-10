#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	FILE *fp;
	fp= fopen("file.txt","a+");
	if(fp==NULL)
	{
		perror("error to open the file\n");
		exit(-1);
	}
	char ch;
	printf("The contents of file are\n");
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	printf("\n");
	fclose(fp);
	// to stop console from closing
	system("pause");
	return 0;
}