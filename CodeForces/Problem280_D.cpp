#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
LL gcd(LL x,LL y)
{
	if(y>x)
		return gcd(y,x);
	if(x%y==0)
		return y;
	else return gcd(y,x%y);
}
int main()
{
	LL n,x,y;
	cin>>n>>x>>y;
	LL *a=new LL [n];
	LL i;
	for(i=0;i<n;i++)
		cin>>a[i];
	vector<bool> hit;
	// true means x hits... false means y hits.
	
	return 0;
}