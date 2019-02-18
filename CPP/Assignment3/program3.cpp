#include<iostream> 
using namespace std; 
  
class shape // base class
{ 
public: 
    virtual void display_area () 
    { 
    	cout<< "print area of shape class" <<endl; 
    } 
}; 
  
class Triangle:public shape 
{ 
public: 
    void display_area () 
    { 
    	cout<< "print area of Triangle class" <<endl; 
    } 
}; 
  
class Rectangle:public shape 
{ 
public: 
    void display_area () 
    { 
    	cout<< "print area of Rectangle class" <<endl; 
    } 
};

class Square:public shape 
{ 
public: 
    void display_area () 
    { 
    	cout<< "print area of Square class" <<endl; 
    } 
};

int main() 
{ 
	// creating a pointer variable to shape class
    shape *bptr; 
    Triangle T; 
    bptr = &T;   // storing triangle object into the pointer
    //virtual function, binded at runtime 
    bptr->display_area();
    Square S;
    bptr = &S;    // storing square object into the pointer
   	//virtual function, binded at runtime 
    bptr->display_area();
    Rectangle R;
    bptr = &R;    // storing rectangle object into the pointer
   	//virtual function, binded at runtime 
    bptr->display_area();
    // to stop console from closing
    system("pause");
} 