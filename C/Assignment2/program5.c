#include<stdio.h>
int reverse(int number)
{
	int ans=0;
	while(number>0)
	{
		ans=ans*10+(number%10);
		number/=10;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int number;
	printf("Enter a number\n");
	scanf("%d",&number);
	int reverse_number=reverse(number);
	printf("%d\n",reverse_number );
	//to stop console from closing
	system("pause");
	return 0;
}