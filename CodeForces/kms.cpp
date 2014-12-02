#include<iostream>
#include<algorithm>
#include<cstdio>
#define LL long long int
using namespace std;
void create_sum(LL a[],LL sum[],int n)
{
	int i;
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i-1];
	}
}
int main()
{
	int n,i;
	cin>>n;
	LL *a=new LL [n];
	LL *b=new LL [n];
	LL *sum=new LL [n+1];
	LL *sum_sort=new LL [n+1];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	create_sum(a,sum,n);
	sort(b,b+n);
	create_sum(b,sum_sort,n);
	int m;
	cin>>m;
	while(m--)
	{
		int type,l,r;
		cin>>type>>l>>r;
		if(type==1)
		{
			cout<<(sum[r]-sum[l-1])<<"\n";
		}
		else
		{
			cout<<(sum_sort[r]-sum_sort[l-1])<<"\n";
		}
	}
	return 0;
}