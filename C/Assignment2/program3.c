#include<stdio.h>
long int factorial(int number)
{
	if(number<=1)
		return 1;
	return number*factorial(number-1);
}
int main(int argc, char const *argv[])
{
	int number;
	printf("Enter a number\n");
	scanf("%d",&number);
	long int ans=factorial(number);
	printf("%ld\n", ans);
	//to stop console from closing
	system("pause");
	return 0;
}