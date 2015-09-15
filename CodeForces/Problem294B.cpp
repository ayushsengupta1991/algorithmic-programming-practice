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
	int i,n;
	cin>>n;
	map<int,int> hash1;
	map<int,int> hash2;
	map<int,int> hash3;
	for(i=0;i<n;i++)
	{
		int r;
		cin>>r;
		hash1[r]++;
	}
	for(i=0;i<n-1;i++)
	{
		int r;
		cin>>r;
		hash2[r]++;
	}
	for(map<int,int>::iterator it=hash1.begin();it!=hash1.end();++it)
	{
		if(it->second - hash2[it->first]==1)
			cout<<it->first<<"\n";
		
	}
	for(i=0;i<n-2;i++)
	{
		int r;
		cin>>r;
		hash3[r]++;
	}
	for(map<int,int>::iterator it=hash2.begin();it!=hash2.end();++it)
	{
		if(it->second - hash3[it->first]==1)
			cout<<it->first<<"\n";
	}
	return 0;
}
