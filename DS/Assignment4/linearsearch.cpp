#include<bits/stdc++.h>
using namespace std;
int linearsearch(int array[],int size,int search_ele)
{
	for(int i=0;i<size;i++)
		if(array[i]==search_ele)
			return i;
	return -1;
}
int main()
{
	int *array=NULL,size,search_ele;
	cout<<"enter the size of the array\n";
	cin>>size;
	array=new int[size];
	cout<<"enter the elements in the array\n";
	for(int i=0;i<size;i++)
		cin>>array[i];
	cout<<"enter the element you want to search\n";
	cin>>search_ele;
	int find=linearsearch(array,size,search_ele);
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