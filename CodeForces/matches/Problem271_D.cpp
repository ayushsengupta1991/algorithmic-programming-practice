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
#define mod 1000000007
#define limit 100000
using namespace std;

int main()
{
	LL t,k;
	cin>>t>>k;
	LL *sum=new LL [limit+2];
	LL *ways=new LL [limit+2];
	LL i;
	ways[0]=0;
	for(i=1;i<k;i++)
		ways[i]=1;
	ways[k]=2;
	for(i=k+1;i<=limit;i++)
		ways[i]=(ways[i-1]+ways[i-k])%mod;
	sum[0]=0;
	for(i=1;i<=limit;i++)
		sum[i]=(sum[i-1]+ways[i])%mod;
	while(t--)
	{
		LL a,b;
		cin>>a>>b;
		cout<<((mod+sum[b]-sum[a-1])%mod)<<"\n";
	}
	return 0;
}
