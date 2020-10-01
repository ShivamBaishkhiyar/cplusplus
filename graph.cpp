#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;
	//Array of list
	list<int> *l;
public:
	Graph(int V)
	{
		this->V = V;
		l = new list<int>[V];
	}
	void addEdge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void printAdjList()
	{
		//Iterate over all vertices
		for(int i=0;i<V;i++)
		{
			cout<<"Vertex "<< i << " -> ";
			for(int nbr : l[i])
			{
				cout<<nbr<<",";
			}
			cout<<endl;
		}
	}
};
int main()
{
	Graph G(4);
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(1,2);
	G.addEdge(2,3);
	G.printAdjList();
	return 0;
}