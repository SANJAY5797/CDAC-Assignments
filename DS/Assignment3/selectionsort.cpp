#include<iostream>
using namespace std;
void selectionsort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min_index=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[min_index]>arr[j])
			{
				min_index=j;
			}
		}
		if(min_index!=i)
		{
			int temp=arr[min_index];
			arr[min_index]=arr[i];
			arr[i]=temp;
		}
	}
	return ;
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
	selectionsort(arr,n);
	cout<<"sorted array elements are"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}