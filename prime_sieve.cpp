#include<iostream>
using namespace std;
//Naive Approach  O(N)
bool isPrime(int n)
{
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
//Optimised Aproach    O(sqrt(N))
bool isPrimeOptimised(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
//Prime-Sieve Optimised Approach  O(Nloglog(N))
void prime_sieve(int *p, int n)
{
	//special case
	p[0]=p[1]=0;
	p[2]=1;

	for(int i=3;i<=n;i+=2)
	{
		//first mark all odd number's prime
		p[i]=1;
	}
	for(int i=3;i<=n;i+=2)
	{
		//if the current number is not marked (it is prime)
		if(p[i]==1)
		{
			//mark all the multiples of i as not prime
			for(int j=i*i;j<=n;j+=i)
			{
				p[j]=0;
			}
		}
	}

}
int main()
{
	int n;
	cin>>n;
	int p[1000000] = {0};
	prime_sieve(p,n);

	//lets print prime upto range n
    
    for(int i=1;i<=n;i++)
    {
    	if(p[i]==1)
    		cout<<i<<" ";
    } 
    return 0;
}