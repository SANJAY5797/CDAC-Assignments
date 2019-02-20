#include<iostream>
using namespace std;
struct node 
{
	int coeff;
	int power;
	struct node *next;
};
class poly
{
	struct node *start;
public:
	poly()
	{
		start=NULL;
	}
	void createPoly();
	void addToList(int x,int y);
	void add(poly p1,poly p2);
	void display();
	~poly()
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
void poly::display()
{
	if(start!=NULL)
	{
		struct node *temp=start;
		while(temp!=NULL)
		{
			if(temp->coeff<0)
				cout<<temp->coeff<<"x^"<<temp->power<<" ";
			else if(temp->coeff>0)
			{
				cout<<"+"<<temp->coeff<<"x^"<<temp->power<<" ";
			}
			temp=temp->next;
		}
		cout<<endl;
	}
}
void poly::add(poly p1,poly p2)
{
	int x,y;
	struct node *x1=p1.start,*x2=p2.start;
	while(x1!=NULL&&x2!=NULL)
	{
		if(x1->power==x2->power)
		{
			x=x1->coeff+x2->coeff;
			addToList(x,x1->power);
			x1=x1->next;
			x2=x2->next;
		}
		else if(x1->power<x2->power)
		{
			addToList(x2->coeff,x2->power);
			x2=x2->next;
		}
		else 
		{
			addToList(x1->coeff,x1->power);
			x1=x1->next;
		}
	}
	while(x1!=NULL)
	{
		addToList(x1->coeff,x1->power);
		x1=x1->next;
	}
	while(x2!=NULL)
	{
		addToList(x2->coeff,x2->power);
		x2=x2->next;
	}
	return ;
}
void poly::addToList(int x,int y)
{
	struct node *temp=new node;
	temp->coeff=x;
	temp->power=y;
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
void poly::createPoly()
{
	cout<<"enter the polynomial coefficient followed by exponents"<<endl;
	int numInputs;
	cin>>numInputs;
	while(numInputs--)
	{
		int coeff,power;
		cin>>coeff>>power;
		addToList(coeff,power);
	}
}
int main()
{
	poly p1,p2,p3;
	p1.createPoly();
	p1.display();
	p2.createPoly();
	p2.display();
	p3.add(p1,p2);
	p3.display();
	// to stop console from closing
	system("pause");
	return 0;
}