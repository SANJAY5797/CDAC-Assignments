#include <iostream>
using namespace std;
class Sample
{
	public:
		virtual void display()
		{

		}
		Sample()
		{
			x = 2;
			y = 3;
			z = 4;
		}
		int x;
	protected:
		int y;
	private:
		int z;
};

class PubDer : public Sample
{
	public:
		void display()
		{
			cout << "\n\tX = " << x;
			cout << "\n\tY = " << y;
			cout << "\n";
			//-------Private member Cannot be accessed-----------//
			//cout << "\nZ = " << z;
		}
};
class proDer: protected Sample
{
public:
	void display()
	{
		//---------X and Y are Protected-----------//
		cout << "\nX = " << x;
		cout << "\nY = " << y;
		//-------Private member Cannot be accessed-----------//
		//cout << "\nZ = " << z;
	}
};

class priDer : private Sample
{
public:
	void display()
	{
		//------------X and Y are Private------------------//
		cout << "\nX = " << x;
		cout << "\nY = " << y;
		//-------Private member Cannot be accessed-----------//
		//cout << "\nZ = " << z;
		cout << "\n\n";
	}
};
int main()
{
	Sample obj;
	cout << "Creating an object for base class and trying to access members\n";
	cout<<"\tX = " << obj.x<<"\n";
	cout << "\tY and Z cannot be accessed as Y is Protected and Z is Private\n\n";
	//-----------Y and Z cannot be accessed as Y is Protected and Z is Private--------------
	//cout << obj.y<< "\n";
	//cout << obj.z << "\n";
	cout << "Creating an object for Derived classes and trying to access members of base classes\n\n";
	Sample *ob;
	PubDer pu;
	priDer pri;
	proDer pro;
	cout << "  -> If Derived class is Public";
	ob = &pu;
	ob->display();
	cout << "\tCannot access Z as it is Private (But can access Y as it is protected and so can be used in derived classes)\n\n";
	cout << "  -> If Derived classes are Protected or Private we Cannot Access any Members\n\n";
	//Classes Which are inherited as Private or Public cannot be accessed
	/*ob = &pri;           
	ob->display();
	ob = &pro;
	ob->display();*/
	// to stop console from closing
	system("pause");
}
