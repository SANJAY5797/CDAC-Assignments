#include<stdio.h>
int main(int argc, char const *argv[])
{
	int number,size;
	printf("Enter the size of the array\n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the elements of the array\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",arr+i);
	}
	int low=0,high=size-1;
	while(low<high)
	{
		while(arr[low]<0)
			low++;
		while(arr[high]>0)
			high--;
		if(low<high)
		{
			int temp=arr[low];
			arr[low]=arr[high];
			arr[high]=temp;
			low++;
			high--;
		}
	}
	printf("Resultant array is\n");
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i] );
	}
	//to stop console from closing
	system("pause");
	return 0;
}