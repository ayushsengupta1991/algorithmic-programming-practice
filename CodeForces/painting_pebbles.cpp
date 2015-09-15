#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long n,k,i,j;
	cin>>n>>k;
	long *a=new long [n];
	for(i=0;i<n;i++)
		cin>>a[i];
	long max=a[0];
	long min=a[0];
	long mi=0;
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
		{
			min=a[i];
			mi=i;
		}
	}
	if(max-min>k)
	{
		cout<<"NO\n";
		return 0;
	}
	else
	{
		cout<<"YES\n";
		for(i=0;i<n;i++)
		{
			for(j=1;j<=min;j++)
				cout<<1<<" ";
			long count=1;
			for(j=1;j<=a[i]-min;j++)
			{
				cout<<count<<" ";
				count++;
			}
			cout<<"\n";
		}
	}
	return 0;
}