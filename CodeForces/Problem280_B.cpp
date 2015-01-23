#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	long long l;
	cin>>n>>l;
	long double *a=new long double [n+2];
	int i;
	for(i=1;i<=n;i++)
		cin>>a[i];
	a[0]=0;
	a[n+1]=l;
	sort(a,a+n+2);
	long double max=((a[1]-a[0])>(a[n+1]-a[n]))?(a[1]-a[0]):(a[n+1]-a[n]);
	for(i=1;i<n;i++)
	{
		//cout<<double(a[i+1]-a[i])/2<<"\n";
		if(((a[i+1]-a[i])/2)>max)
			max=(a[i+1]-a[i])/2;
	}
	cout<<setprecision(20);
	cout<<max<<"\n";
	return 0;
}
