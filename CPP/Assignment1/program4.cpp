#include<iostream>
using namespace std;
inline void add(int a,int b)
{
	cout<<"sum of two numbers is ";
	cout<<a+b<<endl;
}
inline void sub(int a,int b)
{
	cout<<"Difference of 2 numbers is ";
	cout<<a-b<<endl;
}
inline void mul(int a,int b)
{
	cout<<"Multiplication of 2 numbers ";
	cout<<a*b<<endl;
}
inline void div(int a,int b)
{
	try
	{
		if(b==0)
			throw "Division by zero not allowed";
		cout<<"Division of 2 numbers ";
		cout<<a/b;
	}
	catch(const char *msg)
	{
		cerr<<msg<<endl;
	}
	
}
inline void mod(int a,int b)
{
	try
	{
		if(b==0)
			throw "modulus by zero not allowed";
		cout<<"remainder obtained after Division is ";
		cout<<a%b;
	}
	catch(const char *msg)
	{
		cerr<<msg<<endl;
	}
}
int main()
{
	int a,b;
	while(1)
	{
		cout<<"enter the numbers\n";
		cin>>a>>b;
		cout<<"Enter the operation you want\n";
		cout<<"1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Modulus\n6.exit\n";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1: 
				add(a,b);
				break;
			case 2:	
				sub(a,b);
				break;
			case 3:	
				mul(a,b);
				break;
			case 4: 
				div(a,b);
				break;
			case 5:	
				mod(a,b);
				break;
			case 6: 
				exit(0);
		}
	}
	return 0;
}