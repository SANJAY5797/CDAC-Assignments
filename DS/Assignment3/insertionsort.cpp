#include<iostream>
using namespace std;
void insertionsort(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int num=arr[i];
		while(j>=0&&num<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=num;
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
	insertionsort(arr,n);
	cout<<"sorted array elements are"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}