#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char const *argv[])
{
	FILE *fp;
	char ch;
	fp=fopen("file.txt","r");
	if(fp==NULL)
	{
		// to print some error message to console
		perror("error while opening file");
		exit(-1);
	}
	char store[500];
	int i=0;
	while((ch=fgetc(fp))!=EOF)
	{
		if(islower(ch))
			store[i]=(char)toupper(ch);
		else
			store[i]=(char)tolower(ch);
		if(ftell(fp)==5)
		{
			//skipping 10 characters from now in storing
			fseek(fp,10,SEEK_CUR);
		}
		//store[i]=(islower(ch))?((char)toupper(ch)):((char)tolower(ch));
		i++;
	}
	printf("the contents of text file are\n");
	printf("%s\n",store);
	fclose(fp);
	// to stop console from closing
	system("pause");
	return 0;
}