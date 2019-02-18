#include<bits/stdc++.h>
using namespace std;
class person 
{
	public://public section
		string name;
		int age;
		person()
		{
			name="sanjay";
			age=21;
		}
		void displayn()
		{
			cout<<name<<"'s age is "<<age<<endl;
		}
};
///virtually deriving class
class physique : virtual public person
{
	public://public section
		int height;
		int weight;
		physique()
		{
			height=10;
			weight=50;
		}
		void displayp()
		{
			//displayn();
			cout<<"the person height and weight are "<<height<<" "<<weight<<endl;
		}
};
class family: virtual public person
{
	public://public section
		int numChildren;
		string religion;
		family()
		{
			numChildren=2;
			religion="hindu";
		}
		void displayf()
		{
			
			cout<<"the number of children are "<<numChildren<<" and religion is "<<religion<<endl;
		}
};
class employee: public physique, public family
{
	public://public section
		int emno;
		float salary;
		employee()
		{
			emno=31;
			salary=70000.0f;
		}
		void displaye()
		{
			displayn();
			displayp();
			displayf();
			cout<<"the employee number is "<<emno<<" salary is "<<salary<<endl;
		}
};
int main()
{
	employee obj1;
	// calling employee display function
	obj1.displaye();
	// to stop console from closing
	system("pause");
	return 0;
}