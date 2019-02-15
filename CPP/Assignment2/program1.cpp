#include<iostream>
using namespace std;
class polar
{
	float angle,radius;
public:
	static int count;
	polar()//default constructor
	{
		count++;//incrementing when an object is created
		angle=radius=0.0;
	}
	polar(float a,float r)//parameterized constructor
	{
		count++;//incrementing when an object is created
		angle=a;
		radius=r;
	}
	~polar()//destructor
	{
		//decrementing count when scope of object is lost
		count--;
	}
};
int polar::count;//declaration for static data member
int main()
{
	polar a,b,c,d,e,f(1.0,2.5),g(2.3,5.4);//creation of objects
	cout<<"number of active objects are\n";
	cout<<polar::count<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}