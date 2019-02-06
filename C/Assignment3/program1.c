#include<stdio.h>
int main(int argc, char const *argv[])
{
	int size;
	printf("Enter the size of array\n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the elements of the array\n");
	for(int i=0;i<size;i++)
		scanf("%d",arr+i);
	int sum;
	printf("Enter the sum\n");
	scanf("%d",&sum);
	int start=0,end=-1;
	int temp=arr[0];
	int i;
	for(i=1;i<=size;i++)
	{
		while(temp>sum&&start<i-1)
		{
			temp-=arr[start];
			start++;
		}
		if(temp==sum)
		{
			end=i-1;
			break;
		}
		if(i<size)
			temp=temp+arr[i];
	}
	if(end==-1)
	{
		printf("No such range found for the given sum\n");
	}
	else
	{
		printf("the sum is found in the indices range %d and %d\n", start,end);
	}
	//to stop console from closing
	system("pause");
	return 0;
}