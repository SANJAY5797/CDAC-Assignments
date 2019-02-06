#include<stdio.h>
int main(int argc, char const *argv[])
{
	int size=5;
	for(int i=1;i<=size;i++)
	{
		//to print spaces before the number
		for(int j=1;j<=size-i;j++)
			printf(" ");
		// print numbers till 1
		for(int j=i;j>1;j--)
			printf("%d",j);
		// print numbers from 1
		for(int j=1;j<=i;j++)
			printf("%d",j);
		printf("\n");
	}
	// to stop console from closing
	system("pause");
	return 0;
}