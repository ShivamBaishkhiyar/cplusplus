#include<iostream>
#include<unordered_map>
#include<list>
#include<string>
using namespace std;

class Graph
{
	//Adj. list
	unordered_map<string, list<pair<string,int> > > l;
public:
	void addEdge(string x,string y, bool bidir, int wt)
	{
		l[x].push_back(make_pair(y,wt));
		if(bidir)
		{
			l[y].push_back(make_pair(x,wt));
		}
	}
	void printAdjList()
	{
		//iterate over all the keys in the map
		for(auto p : l)
		{
			string city = p.first;
			list<pair<string,int> > nbrs = p.second;
			
			cout<<city<<"->";
			for(pair<string,int> nbr : nbrs)
			{
				string dest = nbr.first;
				int dist = nbr.second;

				cout<<"("<<dest<<","<<dist<<")"<<",";
			}
			cout<<endl;
		}
	}
};
int main()
{
	Graph G;
	G.addEdge("A","B",true,20);
	G.addEdge("B","D",true,40);
	G.addEdge("C","D",true,40);
	G.addEdge("A","C",true,10);
	G.addEdge("A","D",false,50);
	G.printAdjList();
	return 0;
}