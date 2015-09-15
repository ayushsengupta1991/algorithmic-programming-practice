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
#define FOR1(n) for(LL i=0;i<n;i++)
#define FOR2(x,n) for(LL i=x;i<n;i++)
#define FOR3(m,n) for(LL i=0;i<m;i++) for(LL j=0;j<n;j++)
#define SIZE(x) int((x).size())
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int b,g;
	int i,it;
	
	bool *happyB=new bool [n];
	bool *happyG=new bool [m];
	
	FOR1(n)
		happyB[i]=false;
		
	FOR1(m)
		happyG[i]=false;
	cin>>b;
	FOR1(b)
	{
		int x;
		cin>>x;
		happyB[x]=true;
	}
	cin>>g;
	FOR1(g)
	{
		int x;
		cin>>x;
		happyG[x]=true;
	}
	i=0;int j=0;
	for(it=0;it<=(m+1)*(n+1);it++)
	{
		if(happyB[i] || happyG[j])
		{
			happyB[i]=true;
			happyG[j]=true;
		}
		i=(i+1)%n;
		j=(j+1)%m;
	}
	for(i=0;i<n;i++)
	{
		if(!happyB[i])
		{
			cout<<"No\n";
			return 0;
		}
	}
	for(i=0;i<m;i++)
	{
		if(!happyG[i])
		{
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}
