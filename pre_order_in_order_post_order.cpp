#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* left;
	node* right;
	
	node(int d)
	{
		data = d;
		left = NULL;
		right=NULL;
	}
};
node* buildTree()
{
	int d;
	cin>>d;
	if(d == -1)
		return NULL;
	node *root = new node(d);
	root->left = buildTree();
	root->right= buildTree();
	return root;
}
void print_pre_order(node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	print_pre_order(root->left);
	print_pre_order(root->right);
}
void print_in_order(node* root)
{
	if(root==NULL)
		return;
	print_in_order(root->left);
	cout<<root->data<<" ";
	print_in_order(root->right);
}
void print_post_order(node* root)
{
	if(root==NULL)
		return;
	print_post_order(root->left);
	print_post_order(root->right);
	cout<<root->data<<" ";
}
int main()
{
	node *root = buildTree();
	print_pre_order(root);
	cout<<endl;

	print_in_order(root);
	cout<<endl;

	print_post_order(root);
	cout<<endl;
	return 0;
}