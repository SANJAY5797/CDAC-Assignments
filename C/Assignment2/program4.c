#include <stdio.h>
#include <math.h>
int prime(int number)
{
	for(int i=2;i<=sqrt(number);i++)
	{
		if(number%i==0)
			return 0;
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	int left,right;
	printf("Enter the left and right most values of the range\n");
	scanf("%d %d",&left,&right);
	int ans=-1;
	for(int i=left;i<=right;i++)
	{
		if(prime(i))
		{
			ans=i;
			break;
		}
	}
	if(ans==-1)
	printf("No prime number in the range\n");
	else
		printf("prime number in the range is %d\n", ans);
	//to stop console from closing
	system("pause");
	return 0;
}