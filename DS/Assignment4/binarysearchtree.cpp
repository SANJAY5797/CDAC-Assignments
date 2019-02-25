#include<iostream>
using namespace std;
// Declaration of node
struct node
{
	int data;
	struct node *left,*right;
};
// creation of new node
struct node* newNode(int data)
{
	struct node* temp=new struct node;
	temp->data=data;
	temp->left=temp->right=NULL;
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
// inserting an element into BST
struct node* insert(struct node *node,int key)
{
	if(node==NULL)
		return newNode(key);
	if(key<node->data)
	{
		node->left=insert(node->left,key);
	}
	else
		node->right=insert(node->right,key);
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
int main()
{
	cout<<"Enter the number of elements in the tree"<<endl;
	int tree_size;
	cin>>tree_size;
	struct node *root=NULL;
	cout<<"enter the root of the tree\n";
	int value;
	cin>>value;
	root=insert(root,value);
	cout<<"enter the elements in the tree\n";
	for(int i=1;i<tree_size;i++)
	{
		int tree_ele;
		cin>>tree_ele;
		insert(root,tree_ele);
	}
	cout<<"the ascending order of the elements is \n";
	inorder(root);
	cout<<endl;
	cout<<"enter the element you want to delete"<<endl;
	int delete_ele;
	cin>>delete_ele;
	root=deleteN(root,delete_ele);
	cout<<"resultant is "<<endl;
	inorder(root);
	// to stop console from closing
	system("pause");
	return 0;
}