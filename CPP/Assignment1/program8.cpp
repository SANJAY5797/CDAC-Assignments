#include<iostream>
using namespace std;
class Employee
{
	//public section
	public:
		int x,y;
		Employee()//default constructor
		{
			cout<<"In default constructor"<<endl;
		}
		Employee(int a,int b)//parameterized constructor
		{
			cout<<"in parameterized constructor"<<endl;
			x=a;
			y=b;
		}
		Employee(Employee &b)//copy constructor
		{
			cout<<"in copy constructor"<<endl;
			x=b.x;
			y=b.y;
		}
		~Employee()//destructor
		{
			cout<<"In destructor"<<endl;
		}
};
void func()// function to see active objects and deleted objects after the execution of function
{
	Employee e1,e2(100,200);
	// displaying sizes of objects
	cout<<sizeof(e1)<<" "<<sizeof(e2)<<endl;
	Employee e3(e2);
	cout<<sizeof(e3)<<endl;
}
int main()
{
	func();
	// to stop console from closing
	system("pause");
}