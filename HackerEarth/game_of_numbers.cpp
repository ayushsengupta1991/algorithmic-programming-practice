#include<iostream>
#include<vector>
#define LIMIT 31630
#define LL long long int
using namespace std;
vector<int> p;
bool isSpecial(LL n)
{
	int i;
	for(i=0;p[i]*p[i]<=n;i++)
	{
		if(n%p[i]==0)
		{
			//int x=1;
			n=n/p[i];
			if(n%p[i]==0) return false;
		}
		if(n==1)	break;
	}
	return true;
	
}
int main()
{
	bool *primes=new bool [LIMIT+1];
	LL i,j;
	for(i=0;i<=LIMIT;i++)
		primes[i]=true;
	primes[0]=primes[1]=false;
	for(i=2;i<=LIMIT;i++)
		if(primes[i])
		{
			for(j=i*2;j<=LIMIT;j+=i)
				primes[j]=false;
		}

	for(i=2;i<=LIMIT;i++)
		if(primes[i])	p.push_back(i);
	
	int t;
	cin>>t;
	while(t--)
	{
		LL x,y,sum=0;
		cin>>x>>y;
		for(i=x;i<=y;i++)
			if(isSpecial(i))
			{
				//cout<<i<<" ";
				sum++;
			}
	
		cout<<"\n"<<sum<<"\n";
	}
	
}