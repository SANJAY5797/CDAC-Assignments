#include<iostream>
using namespace std;
void swap_value(int x,int y)//call by value
{
	x=x+y;
	y=x-y;
	x=x-y;
}
void swap_reference(int &x,int &y)//call by reference
{
	x=x^y;
	y=x^y;
	x=x^y;
}
int main()
{
	cout<<"enter the two numbers to swap\n";
	int a,b;
	cin>>a>>b;
	while(1)
	{
		cout<<"enter the choice\n";
		cout<<"1. Swap using call by value\n2. Swap using call by reference\n";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"value of a and b before swapping using call by value\n"<<a<<" " <<b<<endl;
				swap_value(a,b);
				cout<<"value of a and b after swapping using call by value\n"<<a<<" " <<b<<endl;
				break;
			case 2:
				cout<<"value of a and b after swapping using call by reference\n"<<a<<" " <<b<<endl;
				swap_reference(a,b);
				cout<<"value of a and b after swapping using call by reference\n"<<a<<" " <<b<<endl;
				break;
			case 3:exit(0);
			default: cout<<"Enter the correct choice\n";
		}	
	}
	// to stop console from closing
	system("pause");
	return 0;
}