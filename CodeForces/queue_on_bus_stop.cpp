#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int *a=new int [n+1];
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	a[n]=10;
	int bus=0,mark=0;
	mark=0;
	int capacity;
	while(mark<n)
	{
		if(a[mark]>m)
		{
			a[mark]-=m;
			bus++;
		}
		else if(a[mark]==m)
		{
			a[mark]=0;
			bus++;
			mark++;
		}
		else
		{
			capacity=m;
			while(capacity-a[mark]>=0)
			{
				capacity-=a[mark];
				a[mark]=0;
				mark++;
				if(mark>=n)
					break;
			}
			bus++;
			if(mark<n)
				a[mark]-=capacity;
		}
			
	}
	cout<<bus<<"\n";
	return 0;
}