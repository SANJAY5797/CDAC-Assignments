#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class deque
{
	struct node* fron;
	struct node* rear;
public:
	deque()
	{
		fron=rear=NULL;
	}
	void push_front(int);
	void push_back(int);
	int pop_front();
	int pop_back();
	void display();
	~deque()
	{
		while(fron!=NULL)
		{
			struct node *temp=fron;
			fron=fron->next;
			delete temp;
		}
	}
};
void deque::push_front(int x)
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
void deque::push_back(int x)
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
		struct node* curr=rear;
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=temp;
		fron=temp;
	}
}
int deque::pop_back()
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
int deque::pop_front()
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
	curr=curr->next;
	x=rear->data;
	delete rear;
	rear=curr;
	return x;
}
void deque::display()
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
	deque ll;
	int input;
	while(1)
	{
		cout<<"enter the operation you want to perform"<<endl;
		cout<<"1.push back\n2.push front\n3.pop back\n4.pop front\n5.display\n6.exit\n";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"enter the element to be pushed"<<endl;
					cin>>input;
					ll.push_back(input);
					break;
			case 2: cout<<"enter the element to be pushed"<<endl;
					cin>>input;
					ll.push_front(input);
					break;
			case 3: input=ll.pop_back();
					cout<<"the popped element is "<<input<<endl;
					break;
			case 4: input=ll.pop_front();
					cout<<"the popped element is "<<input<<endl;
					break;
			case 5: ll.display();
					break;
			case 6: exit(0);
		}
	}
	return 0;
}
