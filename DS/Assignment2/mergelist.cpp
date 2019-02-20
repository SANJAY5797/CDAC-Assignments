#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class list
{
	struct node *start;
public:
	list()
	{
		start=NULL;
	}
	void addToList(int);
	void display();
	void createList();
	void merge(list l1,list l2);
	~list()
	{
		while(start!=NULL)
		{
			struct node *x=start;
			start=start->next;
			delete x;
		}
	}
};
void list::addToList(int x)
{
	struct node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		struct node *curr=start;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=temp;
	}
}
void list::display()
{
	struct node *curr=start;
	if(start!=NULL)
	{
		while(curr!=NULL)
		{
			cout<<curr->data<<" ";
			curr=curr->next;
		}
		cout<<endl;
	}
}
void list::createList()
{
	cout<<"enter the number of elements in the list\n";
	int n;
	cin>>n;
	cout<<"enter the elements in ascending order\n";
	while(n--)
	{
		int x;
		cin>>x;
		addToList(x);
	}
}
void list::merge(list l1,list l2)
{
	struct node *x=l1.start,*y=l2.start,*res=NULL;
	while(x!=NULL&&y!=NULL)
	{
		if(x->data==y->data)
		{
			addToList(x->data);
			addToList(x->data);
			x=x->next;
			y=y->next;
		}
		else if(x->data<y->data)
		{
			addToList(x->data);
			x=x->next;
		}
		else
		{
			addToList(y->data);
			y=y->next;
		}
	}
	while(x!=NULL)
	{
		addToList(x->data);
		x=x->next;
	}
	while(y!=NULL)
	{
		addToList(y->data);
		y=y->next;
	}
	return ;
}
int main()
{
	list l1,l2,l3;
	l1.createList();
	l1.display();
	l2.createList();
	l2.display();
	l3.merge(l1,l2);
	l3.display();
	// to stop console from closing
	system("pause");
	return 0;
}