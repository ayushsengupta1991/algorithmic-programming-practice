#include<iostream>
using namespace std;
int sub(int x,int y)
{
	if(x>y)	return (x-y);
	else 	return (y-x);
}
int main()
{
	int n,m;
	cin>>n>>m;
	int *a=new int [m];
	int i;
	for(i=0;i<m;i++)
		cin>>a[i];
	int profit=0,cost=0;
	for(i=0;i<m-1;i++)
	{
		cost=cost+sub(a[i],a[i+1]);
	}
	for(i=0;i<m;i++)
	{
		if(i==0)
		{
			int r=sub(a[i],a[i+1]);
			if(r>profit)
				profit=r;
		}
		else if(i==m-1)
		{
			int r=sub(a[i-1],a[i]);
			if(r>profit)
				profit=r;
		}
		else
		{
			if(a[i]<=a[i-1] && a[i]<=a[i+1])
			{
				int r=sub(a[i-1],a[i])+sub(a[i],a[i+1])-sub(a[i-1],a[i+1]);
				if(r>profit)
					profit=r;
			}
			if(a[i]>=a[i-1] && a[i]>=a[i+1])
			{
				int r=sub(a[i-1],a[i])+sub(a[i],a[i+1])-sub(a[i-1],a[i+1]);
				if(r>profit)
					profit=r;
			}
		}
	}
	cout<<(cost-profit)<<"\n";
	return 0;
}