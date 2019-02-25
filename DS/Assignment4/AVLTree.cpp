#include<iostream>
using namespace std;
/////need to make a lot of changes

struct node
{
	int data;
	int height;
	struct node *left,*right;
};
int height(struct node *root)
{
	if(root==NULL)
		return 0;
	return root->height;
}
int max(int a,int b)
{
	return a>b?a:b;
}
// creation of new node
struct node* newNode(int data)
{
	struct node* temp=new struct node;
	temp->data=data;
	temp->left=temp->right=NULL;
	temp->height=1;
	return temp;
}
// inorder traversal of tree
void inorder(struct node* root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
// finding successor of root
struct node *findMin(struct node *root)
{
	struct node *curr=root;
	while(curr->left!=NULL)
	{
		curr=curr->left;
	}
	return curr;
}
struct node* rightRotate(struct node *root)
{
	struct node *temp=root->left;
	struct node *temp2=temp->right;
	temp->right=root;
	root->left=temp2;
	root->height=max(height(root->left),height(root->right))+1;
	temp->height=max(height(temp->left),height(temp->right))+1;
	return temp;
}
struct node* leftRotate(struct node *root)
{
	struct node *temp=root->right;
	struct node *temp2=temp->left;
	temp->left=root;
	root->right=temp2;
	root->height=max(height(root->left),height(root->right))+1;
	temp->height=max(height(temp->left),height(temp->right))+1;
	return temp;
}
int getBalance(struct node *root)
{
	if(root==NULL)
		return 0;
	return height(root->left)-height(root->right);
}
// inserting an element into BST
struct node* insert(struct node *node,int key)
{
	if(node==NULL)
		return newNode(key);
	if(key<node->data)
	{
		node->left=insert(node->left,key);
	}
	else if(key>node->data)
		node->right=insert(node->right,key);
	else
		return node;
	node->height=1+max(height(node->left),height(node->right));
	int balance=getBalance(node);
	if(balance>1&&key<node->left->data)
	{
		return rightRotate(node);
	}
	if(balance<-1&&key>node->right->data)
	{
		return leftRotate(node);
	}
	if(balance>1&&key>node->left->data)
	{
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance<-1&&key<node->right->data)
	{
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
// deleting element
struct node* deleteN(struct node *root,int key)
{
	if(root==NULL)
		return root;
	if(root->data<key)
	{
		root->right=deleteN(root->right,key);
	}
	else if(root->data>key)
	{
		root->left=deleteN(root->left,key);
	}
	else
	{
		if(root->left==NULL)// if contains only right subtree
		{
			struct node * temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL)// if contains only left subtree
		{
			struct node *temp=root->left;
			delete root;
			return temp;
		}
		else// if both subtrees are present
		{
			struct node *mn=findMin(root->right);
			root->data=mn->data;
			root->right=deleteN(root->right,mn->data);
		}
	}
}
int main(int argc, char const *argv[])
{
	cout<<"Enter the number of elements in the tree"<<endl;
	int tree_size;
	cin>>tree_size;
	struct node *root=NULL;
	cout<<"enter the elements in the tree\n";
	for(int i=0;i<tree_size;i++)
	{
		int tree_ele;
		cin>>tree_ele;
		root=insert(root,tree_ele);
	}
	cout<<"the ascending order of the elements is \n";
	inorder(root);
	cout<<endl;
	/*cout<<"enter the element you want to delete"<<endl;
	int delete_ele;
	cin>>delete_ele;
	root=deleteN(root,delete_ele);
	cout<<"resultant is "<<endl;
	inorder(root);*/
	// to stop console from closing
	system("pause");
	return 0;
}