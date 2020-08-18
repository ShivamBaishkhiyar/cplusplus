#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	//constructor
	node(int d)
	{
		data = d;
		next = NULL;
	}
};

void insert_at_head(node* &head, int data)
{
	node* temp = head;
	node* n = new node(data);
	n->next = head;
	if(temp!=NULL)
	{
	    while(temp->next!=head)
	    {
		    temp = temp->next;
	    }
	    temp->next = n;
    }
    else
    {
    	//to link only one node to itself when other nodes are not present
        n->next = n;
	}
	    head = n;
}

node* getnode(node* head,int key)
{
	node*temp = head;
	//for all node except last node
	while(temp->next!=head)
	{
		if(temp->data==key)
			return temp;
		temp = temp->next;
	}
	if(temp->data==key)
		return temp;
    return NULL;
}

void delete_node(node* &head, int data)
{
	node *del = getnode(head,data);
	
	if(del==NULL)
		return;
	if(del==head)
	{
		head=head->next;
	}
	node*temp=head;
	//stop one step behind the node to be deleted
	while(temp->next!=del)
	{
		temp=temp->next;
	}
	temp->next = del->next;
	delete del;
}

void Print(node *head)
{
	node *temp=head;
	if(temp==NULL)
		return;
	while(temp->next!=head)
	{
		cout<<temp->data<<"-->";
		temp = temp->next;
	}
	cout<<temp->data;
	return;
}

int main()
{
	node* head =NULL;
	insert_at_head(head,5);
	insert_at_head(head,4);
	insert_at_head(head,3);
	insert_at_head(head,2);
	insert_at_head(head,1);
	Print(head);
	cout<<endl;
	
	delete_node(head,1);
	delete_node(head,4);
    Print(head);
	return 0;
}