#include<bits/stdc++.h>
using namespace std;
int binarysearch(int array[],int low,int high,int search_ele)
{
	if(low>high)
	{
		return -1;
	}
	int mid=low+(high-low)/2;
	if(array[mid]==search_ele)
	{
		return mid;
	}
	else if(array[mid]<search_ele)
	{
		return binarysearch(array,mid+1,high,search_ele);
	}
	else
	{
		return binarysearch(array,low,mid-1,search_ele);
	}
}
int main()
{
	int *array=NULL,size,search_ele;
	cout<<"enter the size of the array\n";
	cin>>size;
	array=new int[size];
	for(int i=0;i<size;i++)
		cin>>array[i];
	cout<<"enter the element you want to search\n";
	cin>>search_ele;
	sort(array,array+size);
	int find=binarysearch(array,0,size-1,search_ele);
	if(find==-1)
	{
		cout<<"no element found\n";
	}
	else
	{
		cout<<"element found at index "<<find<<endl;
	}
	return 0;
}