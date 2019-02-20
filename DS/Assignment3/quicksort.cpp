#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
	return ;
}
int findPivot(int arr[],int low,int high)
{
	int pivot=arr[low];
	int i=low+1;
	for(int j=low+1;j<=high;j++)
	{
		if(arr[j]<pivot)
		{
			if(i!=j)
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	arr[low]=arr[i-1];
	arr[i-1]=pivot;
	return i-1;
}
void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pivot=findPivot(arr,low,high);
		quicksort(arr,low,pivot-1);
		quicksort(arr,pivot+1,high);
	}
}
int main()
{
	int *arr=NULL,n;
	cout<<"Enter the size of the elements\n";
	cin>>n;
	arr=new int[n];
	cout<<"enter the elements"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	quicksort(arr,0,n-1);
	cout<<"sorted array elements are"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}