#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class Queuell
{
	struct node* fron;
	struct node* rear;
public:
	Queuell()
	{
		fron=rear=NULL;
	}
	void push(int);
	int front();
	void display();
	~Queuell()
	{
		while(fron!=NULL)
		{
			struct node *temp=fron;
			fron=fron->next;
			delete temp;
		}
	}
};
void Queuell::push(int x)
{
	struct node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(rear==NULL)
	{
		fron=rear=temp;
	}
	else
	{
		temp->next=rear;
		rear=temp;
	}
}
int Queuell::front()
{
	struct node *curr=rear;
	int x=-999;
	if(curr==NULL)
	{
		return x;
	}
	if(curr->next==NULL)
	{
		x=curr->data;
		rear=fron=NULL;
		delete curr;
		return x;
	}
	while(curr->next!=fron)
	{
		curr=curr->next;
	}
	curr->next=NULL;
	x=fron->data;
	delete fron;
	fron=curr;
	return x;
}
void Queuell::display()
{
	if(rear==NULL)
	{
		cout<<"Queue is empty\n";
		return ;
	}
	struct node *temp=rear;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
	Queuell ll;
	int input;
	while(1)
	{
		cout<<"enter the operation you want to perform"<<endl;
		cout<<"1.push\n2.pop\n3.display\n4.exit\n";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"enter the element to be pushed"<<endl;
					cin>>input;
					ll.push(input);
					break;
			case 2: input=ll.front();
					cout<<"the popped element is "<<input<<endl;
					break;
			case 3: ll.display();
					break;
			case 4: exit(0);
		}
	}
	return 0;
}