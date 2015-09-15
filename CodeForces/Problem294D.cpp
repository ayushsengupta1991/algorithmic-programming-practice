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
	long *convert=new long [26];
	int i,j;
	for(i=0;i<26;i++)
		cin>>convert[i];
	string s;
	cin>>s;
	LL *cum=new LL [SIZE(s)+1];
	cum[0]=0;
	for(i=0;i<SIZE(s);i++)
	{
		cum[i+1]=cum[i]+convert[int(s[i]-'a')];
	}
	long long int ans=0;
	//char ch;
	for(i=0;i<=26;i++)
	{
		char test=i+'a';
		map<LL,int> hash;
		for(j=0;j<SIZE(s);j++)
		{
			if(s[j]==test)
			{
				ans+=hash[cum[j]];
				hash[cum[j+1]]++;
				//cout<<test<<" "<<hash[cum[j]]<<"\n";
				//cout<<test<<":"<<ans<<"\n";
			}
		}
	}
	cout<<ans;
	return 0;
}
