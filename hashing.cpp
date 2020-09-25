#include<iostream>
using namespace std;

template<typename T>
class Node
{
public:
	string key;
	T value;
	Node<T>*next;
	Node(string key,T val)
	{
		this->key = key;
		value = val;
		next = NULL;
	}
	~Node()
	{
		if(next!=NULL)
		{
			delete next;
		}
	}
	
};

template<typename T>
class HashTable
{
	Node<T>** table; //Pointer to an array of pointers
	int current_size;
	int table_size;
public:
	HashTable(int ts=7)
	{
	    table_size = ts;
	    table = new Node<T>*[table_size];
	    current_size = 0;

	    for(int i=0;i<table_size;i++)
	    {
	    	table[i] = NULL;
	    }	
	}
	int hashFn(string key)
	{
		int idx = 0;
		int p = 1;
		for (int j=0;j<key.length();j++)
		{
			idx = idx + (key[j]*p)%table_size;   //(a+b+c)%m = (a%m+b%m+c%m)%m
			idx = idx%table_size;
			p = (p*27)%table_size;        //base - 27
		}
		return idx;
	}

	void insert(string key, T value)
	{
		int idx = hashFn(key);
		Node<T>*n = new Node<T>(key,value);
		//Insert at head of the linked list
		n->next = table[idx];
		table[idx] = n;
		current_size++;
        
        //rehash.......
        float load_factor = current_size/(1.0*table_size);

        if(load_factor>0.75)
        {
        	rehash();
        }
	}

	T* search(string key)
	{
		int idx = hashFn(key);
		Node<T>*temp = table[idx];
		while(temp!=NULL)
		{
			if(temp->key == key)
			{
				return &temp->value;
			}
		}
		return NULL;
	}

	void erase(string key)
	{
		//......


	}

	T& operator[](string key)
	{
		T *f = search(key);
		if(f==NULL)
		{
			//Insert key,value(garbage) in the hashmap
			T garbage;
			insert(key,garbage);
			f = search(key);
		}
		return *f;
	}

	void rehash()
	{
		Node<T>** oldTable = table ;
		int oldTableSize = table_size;
		table_size = 2*table_size;
		table = new Node<T>*[table_size];

		for(int i=0;i<table_size;i++)
	    {
	    	table[i] = NULL;
	    }
	    current_size = 0;

	    //shift the element from old table to new table
	    for(int i=0; i<oldTableSize; i++)
	    {
	    	Node<T>*temp = oldTable[i];
	    	while(temp!=NULL)
	    	{
	    		insert(temp->key,temp->value);
	    		temp = temp->next;
	    	}
	    	if(oldTable[i]!=NULL)
	    	{
	    		delete oldTable[i];
	    	}
	    }
	    delete [] oldTable;
	}

	void print()
	{
		for(int i=0;i<table_size;i++)
		{
			cout<< "Bucket "<<i<<" ->";
			Node<T>*temp = table[i];
			while(temp!=NULL)
			{
				cout<<temp->key <<"-->";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
};
int main()
{
	HashTable<int> price_menu;

	price_menu.insert("Burger",120);
	price_menu.insert("Pepsi",20);
	price_menu.insert("BurgerPizza",150);
	price_menu.insert("Noodles",25);
	price_menu.insert("Cake",400);
	price_menu.insert("VegMeal",65);
	price_menu.insert("NonVegMeal",80);
	price_menu.insert("Milk",40);
	price_menu.insert("Soda",25);


	price_menu.print();

	int *price = price_menu.search("Noodles");
	if(price==NULL)
	{
		cout<<"NOT FOUND!!!";
	}
	else
	{
		cout<<"Price is "<<*price<<endl;
	}

	//Operator Overloading 

	//insert 
	price_menu["Dosa"] = 60;

	//update
    price_menu["Dosa"] += 10;

    //search
    cout<<"Price of Dosa ";
    cout<< price_menu["Dosa"]<<endl;

	return 0;
}