#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class Stackll
{
	struct node *top;
public:
	Stackll()
	{
		top=NULL;
	}
	void push(int);
	int pop();
	void display();
	int peek();
	~Stackll()
	{
		while(top!=NULL)
		{
			struct node *temp=top;
			top=top->next;
			delete temp;
		}
	}
};
void Stackll::push(int x)
{
	struct node *temp=new node;
	temp->next=NULL;
	temp->data=x;
	if(top==NULL)
	{
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
	return ;
}
int Stackll::pop()
{
	struct node *temp=NULL;
	int x=-999;
	if(top==NULL)
	{
		cout<<"Stack is empty and can't perform pop operation\n";
		return x;
	}
	temp=top;
	top=top->next;
	x=temp->data;
	delete temp;
	return x;
}
int Stackll::peek()
{
	int x=-999;
	if(top!=NULL)
	{
		x=top->data;
	}
	return x;
}
void Stackll::display()
{
	struct node* curr=top;
	if(curr==NULL)
	{
		cout<<"the stack is empty"<<endl;
		return ;
	}
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}
int main()
{
	Stackll ll;
	int input;
	while(1)
	{
		cout<<"enter the operation you want to perform"<<endl;
		cout<<"1.push\n2.pop\n3.peek\n4.display\n5.exit\n";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"enter the element to be pushed"<<endl;
					cin>>input;
					ll.push(input);
					break;
			case 2: input=ll.pop();
					cout<<"the popped element is "<<input<<endl;
					break;
			case 3: input=ll.peek();
					cout<<"the top element is "<<input<<endl;
					break;
			case 4: ll.display();
					break;
			case 5: exit(0);
		}
	}
	return 0;
}