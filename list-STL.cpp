#include<iostream>
#include<list>
using namespace std;
int main()
{
	//Create a linked list
	list<int> l;

	//Initialisation
	list<int> l1{1,2,3,10,8,5};
	
	//Iterate over the list and print the data
	for(auto i : l1)
	{
		cout<<i<<"-->";
	}
	cout<<endl;

    list<string>l2{"Apple","Guava","Mango","Banana"};
    
    //Push element at the end
    l2.push_back("Pineapple");

    //Pop element from front
    l2.pop_front();

    //Push element from front
    l2.push_front("Kiwi");

    //Pop element from back
    l2.pop_back();

    //Gives the front and back element
    cout<<l2.front()<<" "<<l2.back()<<endl;

	//Sort
    l2.sort();

    //Reverse linked list
    l2.reverse();

    for(auto i : l2)
	{
		cout<<i<<"-->";
	}
	cout<<endl;

	//Remove a element at particular location
	cout<<"Enter name of element to remove from the list"<<endl;
	string str;
	cin>>str;
	l2.remove(str);
	for(auto it = l2.begin();it!=l2.end();it++)
	{
		cout<<(*it)<<"--";
	}
	cout<<endl;
	
	//Erase an element using index
    auto it = l2.begin();
    it++;      //it at index 1
    it++;      //it at index 2
    l2.erase(it);

    //Insert element by index
    it = l2.begin();
    it++;
    l2.insert(it,"Fruit Juice");

	//Other method to iterate over list
	for(auto it = l2.begin();it!=l2.end();it++)
	{
		cout<<(*it)<<"--";
	}
	cout<<endl;

	return 0;
}