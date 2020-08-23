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
int height(node* root)
{
	if(root==NULL)
		return 0;
	int left_subtree = height(root->left);
	int right_subtree = height(root->right);
	return max(left_subtree,right_subtree) + 1 ;
}
int main()
{
	node *root = buildTree();
	cout<<height(root);
	return 0;
}