#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	long long int x,y,xn,yn,r;
	cin>>r>>x>>y>>xn>>yn;
	long double dist=sqrt((xn-x)*(xn-x)+(yn-y)*(yn-y));
	long double ans=dist/(r*2);
	//long double v=1.342;
	if((long long int)ans<ans)
		cout<<((long long int)ans+1);
	else
		cout<<(long long int)ans;
	//cout<<ans;
	return 0;
}
