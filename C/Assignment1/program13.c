#include<stdio.h>
int invertponwards(int number,int position,int bits)
{
	int ans=0;
	int binary[64]={0},i=0;
	while(number>0)
	{
		binary[i]=number%2;
		number>>=1;
		i++;
	}
	i--;
	int k=i-position;
	for(int temp=0;temp<bits;temp++,k--)
	{
		binary[k]=((binary[k]==1)?0:1);
	}
	int j=0;
	while(i>=0)
	{
		ans=ans*2+binary[i];
		j++;i--;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int number;
	printf("Enter any number\n");
	scanf("%d",&number);
	int position,bits;
	printf("Enter the position to invert\n");
	scanf("%d",&position);
	printf("Enter the number of bits to invert\n");
	scanf("%d",&bits);
	int res=invertponwards(number,position-1,bits);
	printf("%d\n", res);
	// to stop console from closing
	system("pause");
	return 0;
}