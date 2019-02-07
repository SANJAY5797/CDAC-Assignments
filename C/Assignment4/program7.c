#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int n;
	printf("enter the value of n\n");
	scanf("%d",&n);
	char s[n][20];
	for(int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	/* logic to implement sort*/
	for(int i=0;i<n-1;i++)
	{
		int min_index=i;
		char temp[20];
		strcpy(temp,s[i]);
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(temp,s[j])>0)
			{
				strcpy(temp,s[j]);
				min_index=j;
			}
		}
		if(min_index!=i)
		{
			char temp2[20];
			strcpy(temp2,s[i]);
			strcpy(s[i],s[min_index]);
			strcpy(s[min_index],temp2);
		}
	}
	/* printing the sorted list of strings*/
	printf("\nSorted string are \n\n");
	for(int i=0;i<n;i++)
		printf("%s  ", s[i]);
	printf("\n");
	
	// to stop console from closing
	system("pause");
	return 0;
}