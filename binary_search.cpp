#include<iostream>
using namespace std;
int binary_search(int a[], int n, int key)
{
   int start = 0, end = n-1;
   while(start <= end)
   {
      int mid = (start+end)/2;
      if(a[mid] == key)
         return mid;
      else if(a[mid] < key)
         start = mid+1;
      else
         end = mid-1;
   }
   return -1;
}
int main()
{
   int n , key;
   int arr[100];
   cin>>n;
   for(int i=0; i<n; i++)
   {
      cin>>arr[i];
   }
   cin>>key;
   cout<<binary_search(arr, n, key);
   return 0;
}