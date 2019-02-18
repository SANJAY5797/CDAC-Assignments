#include<bits/stdc++.h>
using namespace std;
template<class T=int>// template declaration
int linear_search(T arr[],int size,T ele)// template function to implement search
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==ele)
			return i;
	}
	return -1;
}
class Complex
{
	// private section
	int real,imag;
	public://public section
		Complex()//default constructor
		{
			real=imag=0;
		}
		Complex(int x,int y)// parameterized constructor
		{
			real=x;
			imag=y;
		}
		Complex(const Complex &b)//copy constructor
		{
			real=b.real;
			imag=b.imag;
		}
		~Complex()//destructor
		{}
		bool operator==(const Complex &a)// overloading ==
		{
			if(real==a.real&&imag==a.imag)
				return true;
			else
				return false;
		}
		friend istream& operator>>(istream& cin,Complex &b);//overloading cin
};
istream& operator>>(istream& cin,Complex &x)
{
	cin>>x.real>>x.imag;
	return cin;
}
int linear_search(const char *arr[],int size,char eles[20])//search function for char * type data
{
	for(int i=0;i<size;i++)
	{
		if(strcmp(arr[i],eles)==0)
			return i;
	}
	return -1;
}
int main()
{
	// passing integeres
	int arrInt[]={1,2,3,4,5,6,7,8,9,10};
	int pos=linear_search(arrInt,10,6);
	if(pos==-1)
	{
		cout<<"element not found\n";
	}
	else
	{
		cout<<"Element found at "<<pos<<endl;
	}
	//passing floats
	float arrFloat[]={1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f,10.0f};
	int posF=linear_search(arrFloat,10,10.0f);
	if(posF==-1)
	{
		cout<<"element not found\n";
	}
	else
	{
		cout<<"Element found at "<<posF<<endl;
	}
	// passing doubles
	double arrDouble[]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
	int posd=linear_search(arrDouble,10,5.0);
	if(posd==-1)
	{
		cout<<"element not found\n";
	}
	else
	{
		cout<<"Element found at "<<posd<<endl;
	}
	//passing char* arrray
	const char *arr[4]={"sanjay","kumar","anumandla","here"};
	char eles[20]="sanjay";
	int posc=linear_search(arr,4,eles);
	if(posc==-1)
	{
		cout<<"element not found\n";
	}
	else
	{
		cout<<"Element found at "<<posc<<endl;
	}
	// passing complex objects
	Complex c(10,5),ar[5];
	cout<<"enter the complex objects \n";
	for(int i=0;i<5;i++)
	{
		cin>>ar[i];
	}
	int posco=linear_search(ar,5,c);
	if(posco==-1)
	{
		cout<<"element not found\n";
	}
	else
	{
		cout<<"Element found at "<<posco<<endl;
	}
	// to stop console from closing
	system("pause");
	return 0;
}