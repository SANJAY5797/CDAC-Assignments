#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class linkedlist
{
	struct node *start;
public:
	linkedlist()
	{
		start=NULL;
	}
	~linkedlist()
	{
		while(start!=NULL)
		{
			struct node *temp=start;
			start=start->next;
			delete temp;
		}
	}
	void insertBeginning(int ele);
	void insertLast(int ele);
	void insertBefore(int sele,int ele);
	void insertAfter(int sele,int ele);
	int deleteBeginning();
	int deleteLast();
	int deleteBefore(int sele);
	int deleteAfter(int sele);
	void DisplayForward();
	void DisplayBackward();
	void reverse();
	friend void print(struct node *);
};
void linkedlist::reverse()
{
	if(start!=NULL)
	{
		struct node *curr=start,*prev=NULL,*temp=NULL;
		while(curr!=NULL)
		{
			temp=curr->next;
			curr->next=prev;
			prev=curr;
			curr=temp;
		}
		start=prev;
	}
}
int linkedlist:: deleteAfter(int sele)
{
	int x=-999;
	if(start!=NULL)
	{
		if(start->next!=NULL)
		{
			struct node *curr=start,*prev=NULL;
			while(curr!=NULL&&curr->data!=sele)
			{
				prev=curr;
				curr=curr->next;
			}
			if(curr->next!=NULL)
			{
				x=curr->data;
				prev->next=curr->next;
				delete curr;
			}
			else
			{
				//cout<<"no element to delete"<<endl;
			}
		}
	}
	return x;
}
int linkedlist::deleteBefore(int sele)
{
	int x=-999;
	if(start!=NULL)
	{
		if(start->next!=NULL)
		{
			struct node *curr=start,*prev=NULL;
			while(curr->next!=NULL&&curr->next->data!=sele)
			{
				prev=curr;
				curr=curr->next;
			}
			if(curr->next!=NULL)
			{
				x=curr->data;
				if(prev!=NULL)
				prev->next=curr->next;
				else
				{
					start=curr->next;
				}
				delete curr;
			}
		}
	}
	return x;
}
int linkedlist::deleteBeginning()
{
	int x=-999;
	if(start!=NULL)
	{
		struct node *temp=start;
		start=start->next;
		x=temp->data;
		delete temp;
	}
	return x;
}
int linkedlist::deleteLast()
{
	int x=-999;
	if(start!=NULL)
	{
		if(start->next==NULL)
		{
			x=start->data;
			delete start;
			return x;
		}
		struct node* curr=start;
		struct node *temp=start;
		while(curr->next!=NULL)
		{
			temp=curr;
			curr=curr->next;
		}
		temp->next=NULL;
		x=curr->data;
		delete curr;
	}
	return x;
}
void linkedlist:: insertBeginning(int ele)
{
	struct node *temp=new node;
	temp->data=ele;
	temp->next=start;
	start=temp;	
}
void linkedlist:: insertLast(int ele)
{
	struct node *temp=new node;
	temp->data=ele;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
		return ;
	}
	struct node *curr=start;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=temp;
	return ;
}
void linkedlist::insertAfter(int sele,int ele)
{
	struct node *temp=new node;
	temp->data=ele;
	temp->next=NULL;
	struct node *curr=start;
	while(curr!=NULL&&curr->data!=sele)
	{
		curr=curr->next;
	}
	if(curr==NULL)
	{
		cout<<"no element found"<<endl;
	}
	else if(curr->data==sele)
	{
		temp->next=curr->next;
		curr->next=temp;
	}
	return ;
}
void linkedlist::insertBefore(int sele,int ele)
{
	struct node *temp=new node;
	temp->data=ele;
	temp->next=NULL;
	struct node *curr=start;
	if(start==NULL)
	{
		cout<<"list empty to insert before the element"<<endl;
		return ;
	}
	while(curr->next!=NULL&&curr->next->data!=sele)
	{
		curr=curr->next;
	}
	if(curr->next==NULL)
	{
		cout<<"no element found"<<endl;
	}
	else if(curr->next->data==sele)
	{
		temp->next=curr->next;
		curr->next=temp;
	}
	return ;
}
void linkedlist::DisplayForward()
{
	if(start!=NULL)
	{
		struct node *temp=start;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	else
	{
		cout<<"the list is empty"<<endl;
	}
}
void print(struct node *temp)
{
	if(temp)
	{
		print(temp);
		cout<<temp->data<<" ";
	}
}
void linkedlist::DisplayBackward()
{
	print(start);
	cout<<endl;
}
int main()
{
	linkedlist l;
	while(1)
	{
		cout<<"enter the operation you want"<<endl;
		cout<<"1. Insert at beginning \n2. insert at end\n3. insert before an element\n4. insert after an element\n";
		cout<<"5. delete at beginning \n6. delete at end\n7. delete before an element\n8. delete after an element\n";
		cout<<"9. Display\n10.reverse\n11.exit\n";
		int choice;
		cin>>choice;
		int ele,sele;
		switch(choice)
		{
			case 1:
				cin>>ele;
				l.insertBeginning(ele);
				break;
			case 2:cin>>ele;
				l.insertLast(ele);
				break;
			case 3:
				cin>>ele>>sele;
				l.insertBefore(sele,ele);
				break;
			case 4:
				cin>>ele>>sele;
				l.insertAfter(sele,ele);
				break;
			case 5:
				ele=l.deleteBeginning();
				if(ele!=-999)
					cout<<"deleted element is "<<ele<<endl;
				else
					cout<<"element not found to delete "<<endl;
				break;
			case 6:
				ele=l.deleteLast();
				if(ele!=-999)
					cout<<"deleted element is "<<ele<<endl;
				else
					cout<<"element not found to delete "<<endl;
				break;
			case 7:
				cin>>sele;
				ele=l.deleteBefore(sele);
				if(ele!=-999)
					cout<<"deleted element is "<<ele<<endl;
				else
					cout<<"element not found to delete "<<endl;
				break;
			case 8:
				cin>>sele;
				ele=l.deleteAfter(sele);
				if(ele!=-999)
					cout<<"deleted element is "<<ele<<endl;
				else
					cout<<"element not found to delete "<<endl;
				break;
			case 9:
				cout<<"enter the choice\n";
				cout<<"\t1.DisplayForward\n\t2.DisplayBackward\n";
				int x;
				cin>>x;
				if(x==1)
				{
					l.DisplayForward();
				}
				else
					l.DisplayBackward();
				break;
			case 10:
				l1.reverse();
				cout<<"reversed list is"<<endl;
				l1.DisplayForward();
				break;
			case 11:
				exit(0);
		}	
	}
	return 0;
}