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
int gcd(int a,int b)
{
	if(a<b)
		return gcd(b,a);
	if(a%b==0)	return b;
	return gcd(b,a%b);
}
int main()
{
	int n,x0,y0;
	cin>>n>>x0>>y0;
	vector<int> slope;
	set<pair<int,int> > s;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		int num=y-y0;
		int den=x-x0;
		if(num==0 || den==0)
		{
			if(num==0)
				s.insert(make_pair(0,1));
			else if(den==0)
				s.insert(make_pair(1,0));
		}
		else 
		{
			int div=gcd(abs(num),abs(den));
			num/=div;
			den/=div;
			//cout<<num<<" "<<den<<"\n";
			if((num>0 && den>0) || (num<0 && den<0))
				s.insert(make_pair(abs(num),abs(den)));
			else
			{
				if(num<0)
					s.insert(make_pair(num,den));
				else if(den<0)
					s.insert(make_pair(-num,-den));
			}
		}
	}
	//cout<<"donedone\n";
	//for(set<pair<int,int> >::iterator it=s.begin();it!=s.end();++it)
	//{
	//	cout<<it->first<<" "<<it->second<<"\n";
	//}
	cout<<SIZE(s)<<"\n";
	return 0;
}