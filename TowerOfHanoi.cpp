#include<iostream>
using namespace std
;void TowerOfHanoi(char source, char helper, char destination, int n)
{
    if(n==1)
    {
        cout<<"Disk "<<n<<" from "<<source<<" to "<<destination<<endl;
        return;
    }
    
    //Transfer n-1 disk from source(A) to helper(B) using destination(C)
    TowerOfHanoi(source,destination,helper,n-1);
    
    cout<<"Disk "<<n<<" from "<<source<<" to "<<destination<<endl;
    
    //Transfer n-1 disk from helper(B) to destination(C) using source(A)
    TowerOfHanoi(helper,source,destination,n-1);
    return;
}
int main()
{
    int n;
    cin>>n;
    TowerOfHanoi('A','B','C',n);
    return 0;
}