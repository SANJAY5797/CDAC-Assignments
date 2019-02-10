#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	FILE *fp;
	fp=fopen("file2.txt","r");
	char line[50];
	size_t read;
	size_t len=0;
	if(fp==NULL)
	{
		perror("error while opening the file");
		exit(-1);
	}
	int k=0;
	char ch,capital[5][20],country[5][20];
	while((fgets(line,sizeof(line),fp)))
	{
		int i;
		read=strlen(line);
		for(i=0;i<read&&line[i]!='-';i++)
		{
			country[k][i]=line[i];
		}
		country[k][i]='\0';
		i++;
		int j=0;
		for(;i<read;i++)
		{
			capital[k][j]=line[i];
			j++;
		}
		country[k][j]='\0';
		k++;
	}
	fclose(fp);
	while(1)
	{
		printf("1) Determine the capital of a specified country\n");
		printf("2) Determine the country of specified capital\n");
		printf("3) exit\n");
		int choice;
		printf("Enter your choice\n");
		scanf("%d",&choice);
		char st[20];
		char en[20];
		switch(choice)
		{
			case 1:
				scanf("%s",st);
				if(st[0]=='i')
				{
					printf("the capital of %s is %s\n",st, capital[0]);
				}
				else if(st[0]=='b')
				{
					printf("the capital of %s is %s\n",st, capital[2]);
				}
				else if(st[0]=='c')
				{
					printf("the capital of %s is %s\n",st, capital[3]);
				}
				else if(st[0]=='a')
				{
					printf("the capital of %s is %s\n",st, capital[1]);
				}
				break;
			case 2:
			   scanf("%s",en);
				if(en[1]=='e'&&en[0]=='d')
				{
					printf("the country of %s is %s\n",en, country[0]);
				}
				else if(en[0]=='b'&&en[1]=='e')
				{
					printf("the country of %s is %s\n",en, country[2]);
				}
				else if(en[0]=='d'&&en[1]=='h')
				{
					printf("the country of %s is %s\n",en, country[3]);
				}
				else if(en[0]=='n'&&en[1]=='e')
				{
					printf("the country of %s is %s\n",en, country[1]);
				}
				break;
			case 3: exit(0);
		}
	}
	// to stop console from closing
	system("pause");
	return 0;
}