#include<iostream>
using namespace std;
class Complex
{
	// private section
	float real;
	float imag;
	public:// public section
		Complex()// default constructor which initializes to zero
		{
			real=imag=0.0f;
		}
		Complex(float val)// parameterized constructor which uses one arguement to  initialize
		{
			real=imag=val;
		}
		Complex(float r,float im) //parameterized constructor
		{
			real=r;
			imag=im;
		}
		// friend function
		friend Complex addComplex(const Complex &a,const Complex &b);
		friend Complex mulComplex(const Complex &a,const Complex &b);
		void display()// function to display complex numbers
		{
			if(imag<0)
			{
				cout<<real<<(imag)<<"i";
			}
			else
			{
				cout<<real<<"+"<<(imag)<<"i";
			}
		}
};
//addition of complex numbers
Complex addComplex(const Complex &a,const Complex &b)
{
	Complex res;
	res.real=a.real+b.real;
	res.imag=a.imag+b.imag;
	return res;
}
// multiplication of two complex numbers
Complex mulComplex(const Complex &a,const Complex &b)
{
	Complex res;
	res.real=(a.real*b.real)-(a.imag*b.imag);
	res.imag=(a.real*b.imag)+(a.imag*b.real);
	return res;
}
int main()
{
	float a,b;
	cout<<"enter first complex number\n";
	cin>>a>>b;
	Complex c1(a,b);
	cout<<"enter second complex number\n";
	cin>>a>>b;
	Complex c2(a,b);
	Complex c3,c4;// creating complex class objects 
	c3=addComplex(c1,c2);//calling function to add complex objects
	c4=mulComplex(c1,c2);// calling function to multiply complex objects
	//displaying complex objects 
	cout<<"Addition of ";
	c1.display();
	cout<<" and ";
	c2.display();
	cout<<" is ";
	c3.display();
	cout<<endl;
	cout<<"Multiplication of ";
	c1.display();
	cout<<" and ";
	c2.display();
	cout<<" is ";
	c4.display();
	cout<<endl;
	//to stop console from closing
	system("pause");
	return 0;
}