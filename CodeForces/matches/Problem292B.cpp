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
	LL a,b,s;
	cin>>a>>b>>s;
	LL f=abs(a)+abs(b);
	if(s<f)
	{
		cout<<"No\n";
		return 0;
	}
	else
	{
		s=s-f;
		if(s%2==0)
		{
			cout<<"Yes\n";
			return 0;
		}
		else 
		{
			cout<<"No\n";
			return 0;
		}
		
	}
	return 0;
}