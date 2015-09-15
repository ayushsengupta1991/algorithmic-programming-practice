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
	int t,n;
	cin>>t>>n;
	int teams=0;
	if(t<n)
	{
		int swap=t;
		t=n;
		n=swap;
	}
	while(t>n && n>0)
	{
		t-=2;
		n--;
		teams++;
	}
	if(n==0)
	{
		cout<<teams<<"\n";
		return 0;
	}
	else
	{
		teams+=t/3;
		teams+=t/3;
		t=t%3;
		n=n%3;
		if((t==2 && n==1) || (t==1 && n==2))
			teams++;
		else if(t==2 && n==2)
			teams++;
		cout<<teams<<"\n";
		return 0;
	}
	return 0;
}
