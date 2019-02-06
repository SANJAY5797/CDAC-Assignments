#include<stdio.h>
int main(int argc, char const *argv[])
{
	int number=-1;
	printf("Enter the number\n");
	scanf("%d",&number);
	while(number<0||number>255)
	{
		printf("Enter an 8 bit number\n");
		scanf("%d",&number);

	}
	int count=0;
	while(number>0)
	{
		count=count+(number&1);
		number>>=1;
	}
	printf("Total set bits in the given number is %d\n",count);
	//to stop console from closing
	system("pause");
	return 0;
}