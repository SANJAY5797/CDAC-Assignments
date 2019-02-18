#include<iostream>
using namespace std;
#define SIZE 10
template<class T>// template declaration
class Stack// stack class
{
	//private section
	int top;
	T arr[SIZE];
	public:// public section
		Stack()//default constructor
		{
			top=-1;
		}
		~Stack()//destructor
		{}
		void push (T x)//pushing onto stack using try block
		{
			try
			{
				if(top==SIZE-1)
				{
					cout<<"stack is full\n";
					throw "can't push into the stack";
				}
				arr[++top]=x;
			}
			catch(char *s)
			{
				cout<<s<<endl;
			}
		}
		T pop()// popping element using try catch block
		{
			try
			{
				if(top==-1)
				{
					cout<<"stack is empty\n";
					throw "can't pop from the stack";
				}
				return arr[top--];
			}
			catch(char *s)
			{
				cout<<s<<endl;
			}
		}
		int size()///returning size of stack
		{
			return top+1;
		}
};
int main()
{
	//declaring stack objects
	Stack<int> t;
	cout<<"size of the stack till now is "<<t.size()<<endl;
	//int ans=(t.pop()|-1);
	t.push(0);
	t.push(2);
	cout<<"size of the stack till now is "<<t.size()<<endl;
	int temp=t.pop();
	cout<<"the top of the stack element is "<<temp<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}