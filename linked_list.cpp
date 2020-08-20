#include<iostream>
using namespace std;

class node
{
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

int length(node *head)
{
	int len=0;
	while(head!=NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}

void insert_At_head(node* &head, int data)
{
	if(head==NULL)
	{
		head = new node(data);
		return;
	}
	node* temp;
	temp = new node(data);
	temp->next = head;
	head = temp;
}

void insert_At_tail(node* &head, int data)
{
	if(head==NULL)
	{
		head = new node(data);
		return;
	}
	
	node *temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = new node(data);
}

void insert_At_middle(node* &head, int pos, int data)
{
	if(head==NULL || pos==0)
		insert_At_head(head,data);
	
	else if(pos>=length(head))
		insert_At_tail(head,data);
	
	else
	{
		node *temp = head;
		for(int i=1;i<=pos-1;i++)
		{
			temp = temp->next;
		}
		node *n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
}

void delete_from_head(node *&head)
{
	if(head==NULL)
		return;
	node* temp = head;
	head = head->next;
	delete temp;
}

void delete_from_middle(node *&head , int pos)
{
	if(head==NULL)
		return;
	node *temp = head;
	node *prev = NULL;
	for(int i=0;i<pos;i++)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	delete temp;
}

void delete_from_tail(node *&head)
{
	if(head==NULL)
		return;
	node *temp = head;
	node *prev=NULL;
	
	while(temp->next!=NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	delete temp;
}

bool search_Iterative(node *head, int key)
{
	while(head!=NULL)
	{
		if(head->data==key)
			return true;
		head = head->next;
	}
	return false;
}

bool search_Recursive(node *head, int key)
{
	//base case
	if(head==NULL)
		return false;
	
	//rec. case
	if(head->data==key)
		return true;
	else
		return search_Recursive(head->next,key);
}

void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
}
//Build a linked list
//Other Method -- void input_linked_list(node *&head)
node* input_linkedlist()
{
	int d;
	cin>>d;
	node *head = NULL;
	
	while(d!=-1)
	{
		insert_At_tail(head,d);
		cin>>d;
	}
	return head;
}

void Reverse_Iterative(node* &head)
{
	node* current = head;
	node* prev = NULL;
	node* n;
	
	while(current!=NULL)
	{
		//save the next node
		n = current->next;
		//make the current node point to prev
		current->next = prev;
		//update current and prev node
		prev = current;
		current = n;
	}
	head = prev;
}

node* Reverse_Recursive(node* &head)
{
	//base case
	//if there is no node / only one node
	if(head->next==NULL or head==NULL)
		return head;

	// rec case
	node*shead = Reverse_Recursive(head->next);

	/*
	node*temp = shead;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	*/
    node *temp = head->next;
	head->next = NULL;
	temp->next = head;
	return shead;
}

node* midpoint(node*head)
{
	//if ll consist of 0 or 1 node only
	if(head==NULL or head->next==NULL)
		return head;

	node*slow = head;
	node*fast = head->next;
	
	while(fast!=NULL and fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node* kthnode_from_end(node* head)
{
	int k;
	cin>>k;
	if(head==NULL or head->next==NULL)
		return head;
	int jump = 1;
	node*slow=head;
	node*fast=head;
	
	while(jump<=k-1)
	{
		jump++;
        fast=fast->next;
	}
	while(fast->next!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	return slow;
}

node* merge(node*a, node*b)
{
	//base case
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	
	//take a head pointer
	node*c;
	if(a->data < b->data)
	{
		c = a;
		c->next = merge(a->next, b);
	}
	else
	{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}

node* mergeSort(node*&head)
{
	//base case
	if(head==NULL or head->next==NULL)
		return head;

	//rec case
	//1.Break
	
	node*mid = midpoint(head);
	node*a = head;
	node*b = mid->next;

	mid->next=NULL;

	//2.rec. sort the two parts
	a=mergeSort(a);
	b=mergeSort(b);

	//3.merge them
	node*c = merge(a,b);
	return c;
}

bool detectCycle(node*head)
{
	node*slow = head;
	node*fast = head;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)
			return true;
	}
	return false;
}

int main()
{
	node *head = NULL;
	
	insert_At_tail(head,5);
	insert_At_tail(head,15);
	insert_At_tail(head,25);
	insert_At_tail(head,35);
	insert_At_tail(head,45);
	
	insert_At_head(head,4);
	insert_At_head(head,3);
	insert_At_head(head,2);
	insert_At_head(head,1);
	insert_At_head(head,0);
	
	insert_At_middle(head,6,6);
	insert_At_middle(head,7,7);
	insert_At_middle(head,12,46);
	insert_At_middle(head,0,-1);
	
	delete_from_head(head);
	
	delete_from_tail(head);
	
	delete_from_middle(head,7);
	delete_from_middle(head,1);
    
    print(head);
    cout<<endl;
    
    cout<<search_Iterative(head,6);
    cout<<endl;
    
    cout<<search_Recursive(head,36);
    cout<<endl;
	
	cout<<length(head);
	cout<<endl;
	
	node* head2 = input_linkedlist();
	print(head2);
	cout<<endl;

    Reverse_Iterative(head2);
    print(head2);
    cout<<endl;

    head = Reverse_Recursive(head);
    print(head);

    node*mid = midpoint(head2);
    cout<<mid->data<<endl;

	node*k_end = kthnode_from_end(head2);
	cout<<k_end->data<<endl;

	node*a =input_linkedlist();
	node*b =input_linkedlist();
	node*c = merge(a,b);
	print(c);
	cout<<endl; 

    node* s =input_linkedlist();
    mergeSort(s);
    print(s);
    cout<<endl;
	return 0;

}