#include<stdio.h>
int main(int argc, char const *argv[])
{
	int number;
	printf("Enter any number\n");
	scanf("%d",&number);
	if(number<0)
		number=-number;
	int digit_sum=0,temp=number;
	while(temp>0)
	{
		digit_sum+=(temp%10);
		temp=temp/10;
	}
	printf("the sum of digits of %d is %d\n",number,digit_sum);
	// to stop console from closing
	system("pause");
	return 0;
}