#include<iostream>
#include<vector>
using namespace std;
class heap
{
private:
    vector<int> v;
    bool minHeap;   //minHeap - true      //maxHeap - false
    bool compare(int a, int b)
    {
        if(minHeap)
            return a < b;
        else
            return a>b;
    }
    
public:
    //constructor
    heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size);
        v.push_back(-1);  //index 0 is blocked
        minHeap = type;
    }
    void push(int d)
    {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx/2;
        //Keep pushing to the top till you reach a root node or stop midway because current element is already greater or lesser
        //than the parent
        while(idx > 1 and compare(v[idx],v[parent]))
        {
            swap(v[idx],v[parent]);
            idx = parent;
            parent = parent/2;
        }
    }
    void heapify(int idx)
    {
        int left = 2*idx;
        int right = left+1;

        int min_idx = idx;
        int last = v.size() - 1;

        if(left<=last and compare(v[left],v[idx]))
            min_idx = left;
        if(right<=last and compare(v[right],v[min_idx]))
            min_idx = right;
        if(min_idx != idx)
        {
            swap(v[idx],v[min_idx]);
            heapify(min_idx);
        }
    }
    void pop()
    {
        int last = v.size() - 1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }
    bool empty()
    {
        return v.size() == 1;
    }
    int top()
    {
        return v[1];
    }
};
int main()
{
    heap h;                //Minheap
    //heap h(15,false);    //Maxheap
    int n;
    cin>>n;
    int no;
    for(int i=0; i<n; i++)
    {
        cin>>no;
        h.push(no);
    }

    //Remove all element one by one
    while(!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }
    return 0;
}