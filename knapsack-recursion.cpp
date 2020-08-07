//0-1 KNAPSACK PROBLEM

#include<iostream>
using namespace std;
int profit(int n,int c, int* weight, int* prices)
{
   //base case 
   if(n==0 || c==0)
      return 0;
   //rec case
   int max_profit = 0;
   int inc_profit=0, exc_profit=0;
   //inc
   if(weight[n-1]<=c)
      inc_profit = prices[n-1] + profit(n-1,c-weight[n-1],weight,prices);
   //exc
   exc_profit = profit(n-1,c,weight,prices);

   max_profit = max(inc_profit,exc_profit);
   return max_profit;
}
int main()
{
   int weight[] = {1,2,3,5};
   int prices[] = {40,20,35,100};
   int n = sizeof(weight)/sizeof(int);
   int c = 7;
   cout<<profit(n,c,weight,prices);
   return 0;
}