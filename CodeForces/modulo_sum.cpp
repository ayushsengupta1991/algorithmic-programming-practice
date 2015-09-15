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
#define FOR_NESTED(m,n) for(LL i=0;i<m;i++) for(LL j=0;j<n;j++)
#define SIZE(x) int((x).size())
using namespace std;
int main()
{
	LL m,n;
	cin>>n>>m;
	if(n>m)
	{
		cout<<"YES\n";		
	}
	else
	{
		LL *a = new LL [n];
		FOR1(n)
		{
			cin>>a[i];
			a[i] = a[i]%m;
		}
		bool **dp = new bool* [n+1];
		FOR1(n+1)
		{
			dp[i] = new bool [m];
		}
		FOR1(m){
			dp[0][i]=false;
			dp[1][i]=false;
		}
		dp[1][a[0]]=true;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<m;j++)
			{
				dp[i][j] = (dp[i-1][j] || dp[i-1][(m+j-a[i-1])%m]);
			}
			dp[i][a[i-1]]=true;
		}
		/*for(int i=0;i<=n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<dp[i][j]<<" ";
			cout<<"\n";
		}*/
		if(dp[n][0])
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
