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
				cout<<real<<(imag)<<"i"<<endl;
			}
			else
			{
				cout<<real<<"+"<<(imag)<<"i"<<endl;
			}
		}
};
Complex addComplex(const Complex &a,const Complex &b)
{
	Complex res;
	res.real=a.real+b.real;
	res.imag=a.imag+b.imag;
	return res;
}
Complex mulComplex(const Complex &a,const Complex &b)
{
	Complex res;
	res.real=(a.real*b.real)-(a.imag*b.imag);
	res.imag=(a.real*b.imag)+(a.imag*b.real);
	return res;
}
int main()
{
	Complex c1(1,2),c2(2,3),c3,c4;// creating complex class objects 
	c3=addComplex(c1,c2);//calling function to add complex objects
	c4=mulComplex(c1,c2);// calling function to multiply complex objects
	//displaying complex objects 
	cout<<"Addition of 1+2i and 2+3i is\n";
	c3.display();
	cout<<"Multiplication of 1+2i and 2+3i is\n";
	c4.display();
	//to stop console from closing
	system("pause");
	return 0;
}