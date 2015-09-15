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
#include <map>
#include <set>
#include <string>
#include <cstring>
typedef long long int LL;
using namespace std;
LL power(LL n)
{
	LL product=1;
	for(LL i=1;i<=n;i++)
		product*=2;
	return product;
}
int main()
{
	LL n,k;
	cin>>n>>k;
	LL *p=new LL [n];
	LL *e=new LL [n];
	LL i,j;
	LL minSum=0;
	for(i=0;i<n;i++)
	{
		cin>>p[i]>>e[i];
		minSum+=e[i];
	}
	// small cases.
	bool *subset=new bool [n];
	LL elem;
	bool sol=false;
	LL pw=power(n);
	for(i=0;i<pw;i++)
	{
		for(j=0;j<n;j++)
			subset[j]=false;
		LL x=i;
		elem=0;
		while(x>0)
		{
			int r=x%2;
		//	cout<<r<<"R";
			if(r==1){
				subset[elem]=true;
				
			}
			elem++;
			x=x/2;
		}

		LL sum=0,points=0;
		for(j=0;j<n;j++)
		{
			if(subset[j])
			{
				sum+=e[j];
				points+=1;
			}
			else
				p[j]+=1;
			//cout<<subset[j]<<" ";
		}
		LL rank=0;
		
		for(j=0;j<n;j++)
		{
			if(p[j]>points)
				rank++;
			else if(p[j]==points && !subset[j])
				rank++;
			if(!subset[j])
				p[j]-=1;
		}
		cout<<"rank=:"<<rank<<"\n";
		cout<<sum<<"\n";
		if(rank<=k-1 && sum<minSum)
		{
			minSum=sum;
			sol=true;
		}
	}
	if(sol)
		cout<<minSum<<"\n";
	else cout<<"-1\n";
	return 0;
}
