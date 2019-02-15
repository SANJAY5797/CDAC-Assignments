#include<iostream>
using namespace std;
class CopySituation
{
	//private section
	int a,b;
	public://public section
		CopySituation()//default constructor
		{
			a=b=0;
		}
		CopySituation(int x,int y)//parameterized constructor
		{
			a=x;
			b=y;
		}
		CopySituation(const CopySituation &x)//copy constructor
		{
			cout<<"copy constructor invoked\n";
			a=x.a;
			b=x.b;
		}
		//member functions declarations
		void display();
		~CopySituation()
		{}
};
void CopySituation::display()//displaying the valuess
{
	cout<<"a= "<<a<<"\nb= "<<b<<endl;
}
int main(int argc, char const *argv[])
{
	//creating objects
	CopySituation a(2,5);
	CopySituation b=a,c(a);
	//invoking display function through the objects
	a.display();
	b.display();
	c.display();
	// to stop console from closing
	system("pause");
	return 0;
}
