#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int absDiff(int a,int b)
{
	if(a>b)	return (a-b);
	else return (b-a);
}
int main()
{
	int n,m;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	vector<int> b[n+1];
	int a[m];
	int i,j;
	for(i=0;i<m;i++)cin>>a[i];
	if(m==1)	cout<<"0\n";
	else
	{
	if(a[0]!=a[1])b[a[0]].push_back(a[1]);
	if(a[m-1]!=a[m-2])b[a[m-1]].push_back(a[m-2]);
	for(i=1;i<m-1;i++)
	{
		if(a[i]!=a[i-1])
			b[a[i]].push_back(a[i-1]);
		if(a[i]!=a[i+1])
			b[a[i]].push_back(a[i+1]);
		
	}
	// now lets look at it for all size
	long long int profit=0,sum=0;
	for(i=1;i<=n;i++)
	{
		if(b[i].size()==0)
			continue;
		sort(b[i].begin(),b[i].end());
		int x=b[i][b[i].size()/2];
	//	for(j=0;j<b[i].size();j++)
	//		cout<<b[i][j]<<" ";
	//	cout<<"\n";
		long long int before=0,after=0;
		for(j=0;j<b[i].size();j++)
		{
			before+=absDiff(b[i][j],i);
			after+=absDiff(b[i][j],x);
		}
	//	cout<<i<<":"<<after<<":"<<before<<"\n";
		profit=((before-after)>profit)?(before-after):profit;
		sum=sum+before;
	}
	cout<<sum/2-profit<<"\n";
	}
	return 0;
}