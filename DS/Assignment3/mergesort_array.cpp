#include<iostream>
using namespace std;
void merge(int arr[],int low ,int mid,int high)
{
	int res[high-low+1];
	int k=0;
	int i=low,j=mid+1;
	while(i<=mid&&j<=high)
	{
		if(arr[i]<=arr[j])
		{
			res[k++]=arr[i++];
		}
		else
		{
			res[k++]=arr[j++];
		}
	}
	while(i<=mid)
	{
		res[k++]=arr[i++];
	}
	while(j<=high)
	{
		res[k++]=arr[j++];
	}
	j=low;
	for(i=0;i<k;i++)
	{
		arr[j++]=res[i];
	}
	return ;
}
void mergesort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid=low+(high-low)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
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
	mergesort(arr,0,n-1);
	cout<<"sorted array elements are"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}