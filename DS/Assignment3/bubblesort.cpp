#include<iostream>
using namespace std;
void bubblesort(int arr[],int n)
{
	bool flag=true;
	for(int i=0;i<n-1&&flag;i++)
	{
		flag=false;
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=true;
			}
		}
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
	bubblesort(arr,n);
	cout<<"sorted array elements are"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}