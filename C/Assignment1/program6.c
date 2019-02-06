#include<stdio.h>
int main(int argc, char const *argv[])
{
	int num=-1;
	printf("enter any number in the range 0 and 32 exclusive\n");
	while(num<=0||num>31)
		scanf("%d",&num);
	int arr[5]={0,0,0,0,0};
	int index=4;
	while(num>0)
	{
		arr[index]=(num&1)?1:0;
		num>>=1;
		index--;
	}
	index++;
	printf("Binary representation of given number is \n");
	for(;index<5;index++)
	{
		printf("%d",arr[index]);
	}
	printf("\n");
	// to stop console from closing
	system("pause");
	return 0;
}