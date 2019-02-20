#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class selflist
{
	struct node *start;
public:
	selflist()
	{
		start=NULL;
	}
	void adjust(int);
	void addToList(int);
	void display();
	~selflist()
	{
		struct node* temp=start;
		while(temp!=NULL)
		{
			struct node *x=temp;
			temp=temp->next;
			delete x;
		}
	}
};
void selflist::addToList(int x)
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
void selflist::display()
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
void selflist::adjust(int x)
{
	struct node *curr=start,*prev=NULL;
	if(start!=NULL)
	{
		while(curr!=NULL&&curr->data!=x)
		{
			prev=curr;
			curr=curr->next;
		}
		if(curr!=NULL&&prev!=NULL)
		{
			prev->next=curr->next;
			curr->next=start;
			start=curr;
		}
	}
}
int main()
{
	selflist li;
	cout<<"enter the size of the list\n";
	int n;
	cin>>n;
	cout<<"enter the elements"<<endl;
	while(n--)
	{
		int x;
		cin>>x;
		li.addToList(x);
	}
	cout<<"enter the number of times you want to search"<<endl;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		li.adjust(x);
		li.display();
	}
	// to stop console from closing
	system("pause");
	return 0;
}