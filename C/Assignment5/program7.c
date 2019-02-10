#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	if(argc<2)
	{
		perror("Insufficient command line arguements\n");
		exit(-1);
	}
	FILE *fp;
	char store[500],actual[500],ch;
	fp=fopen(argv[1],"r");
	int i=0;
	while((ch=fgetc(fp))!=EOF)
	{
		actual[i]=ch;
		//converting char to int and then taking ones complement and then converting to character
		store[i]=(char)(~((int)ch));
		i++;
	}
	actual[i]='\0';
	store[i]='\0';
	printf("The actual content is\n");
	printf("%s\n\n\n",actual);
	printf("the ones complement of the file read is \n\n\n");
	printf("%s\n",store);
	fclose(fp);
	// to stop console from closing
	system("pause");
	return 0;
}