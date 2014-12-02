#include<iostream>
#define LL long long int 
using namespace std;
int main()
{
	LL i,n,t,c;
	cin>>n>>t>>c;
	LL prev=0,next=0,sum=0;
	for(i=1;i<=n+1;i++)
	{
		LL x;
		if(i==n+1)
		{
			x=t+5;
		}
		else cin>>x;
		if(x>t)
		{
			next=i;
			LL seq=(next-prev)-c;
			if(seq>0)
				sum+=seq;
			prev=next;
		}
	}
	cout<<sum<<"\n";
	return 0;
}