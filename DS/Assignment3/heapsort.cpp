#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void heapify(int arr[],int n,int i)
{
	int large=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n&&arr[l]>arr[large])
	{
		large=l;
	}
	if(r<n&&arr[r]>arr[large])
	{
		large=r;
	}
	if(large!=i)
	{
		swap(arr+i,arr+large);
		heapify(arr,n,large);
	}
}
void heapsort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
	for(int i=n-1;i>=0;i--)
	{
		swap(arr,arr+i);
		heapify(arr,i,0);
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
	heapsort(arr,n);
	cout<<"sorted array elements are"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}