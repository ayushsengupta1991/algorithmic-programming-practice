#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int n=100000;
bool *sieve=new bool [n+1];
long superPower(long z) {
	
	
	long i,j;
	for(i=0;i*i<=z;i++)
		sieve[i]=true;
	long limit_=i;
	sieve[0]=false;
	sieve[1]=false;
	for(i=2;i*2<limit_;i++)
	{
		if(sieve[i])
		{
			for(j=2*i;j<limit_;j=j+i)
				sieve[j]=false;
		}
	}
	// created sieve
	vector<int> values; // all the values must be multiples of the smallest value
	
	for(i=2;i<limit_;i++)
	{
		if(sieve[i] && z%i==0)
		{
			//cout<<i<<"\n";
			int count=0;
			while(z%i==0)
			{
				z=z/i;
				count++;
			}
			values.push_back(count);
		}
	}
	if(z>1)
	{
		//cout<<"this1\n";
		return 0;
	}
	int min=values[0];
	for(i=1;i<values.size();i++)
		if(values[i]<min)
			min=values[i];
		
		for(i=0;i<values.size();i++)
			if(values[i]%min != 0)
			{
				//cout<<"this2\n";
				return 0;
			}
	return 1;
}
int main()
{
	long x;
	cin>>x;
	cout<<superPower(x)<<"\n";
}
