#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	long sum,limit,i;
	cin>>sum>>limit;
	long *total=new long [20];
	for(i=0;i<20;i++)
		total[i]=0;
	long r;
	vector<long> ans;
	for(i=0;(r=1<<i)<=limit;i++)
	{
		long x=limit/r;
		if(x%2==1)
			total[i]=(x+1)/2;
		else
			total[i]=x/2;
	}
	bool possible=true;
	while(sum>0)
	{
		long i=19;
		while((r=1<<i)>sum || total[i]==0)
		{
			i--;
			if(i==-1)
				break;
		}
		if(i==-1)
		{
			possible=false;
			break;
		}
		long x=1;
		while(sum>=r && total[i]>0)
		{
			ans.push_back(x*r);
			x=x+2;
			total[i]--;
			sum=sum-r;
		}
	}
	if(!possible)
		cout<<"-1\n";
	else
	{
		cout<<ans.size()<<"\n";
		for(i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	}
	return 0;
}
