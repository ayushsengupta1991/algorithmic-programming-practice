#include<iostream>
#include<vector>
#define LL long long int
using namespace std;
int main()
{
	int t;
	cin>>t;
//	return 0;
	while(t--)
	{
		long long int x,y;
		cin>>x>>y;
		vector<bool> mark(y-x+1,true);
		for(LL i=2;i*i<=y;i++)
		{
			long long int gap=i*i;
			long long int b=x+(gap-(x%gap))%gap;
			for(LL k=b;k<=y;k+=gap)
			{
				mark[(long long int)(k-x)]=false;
			}
		}
		LL sum=0;
		for(long long int i=0;i<mark.size();i++)
			if(mark[i]) sum++;
			
		cout<<sum<<"\n";
	}
	return 0;
}