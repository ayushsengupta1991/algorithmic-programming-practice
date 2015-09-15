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
#define MOD 1000000007
using namespace std;
LL power(LL m, LL n)
{
	LL pro=1;
	for(LL i=1;i<=n;i++)
		pro = (pro * m)%MOD;
	return pro;
}
int main()
{
	LL comb[101][101];
	comb[1][0] = 1;
	comb[1][1] = 1;
	for(int i=2;i<=100;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0)
				comb[i][j]=1;
			else if(j==i)
				comb[i][j]=1;
			else comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%MOD;
		}
	}
	int t;
	cin>>t;
	for(int it=1;it<=t;it++){
	
		LL m,n;
		cin>>m>>n;
		LL sol = 0;
		int sign=1;
		for(LL i=0;i<m;i++)
		{
			sol = (sol + MOD + (sign*power(m-i,n)*comb[m][m-i])%MOD)%MOD;
			sign = sign*(-1);
		}
		cout<<"Case #"<<it<<": "<<sol<<"\n";
	}
	return 0;
}