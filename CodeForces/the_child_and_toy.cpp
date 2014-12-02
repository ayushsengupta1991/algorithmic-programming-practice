#include<iostream>
#define LL long long int
using namespace std;
int main()
{
	LL n,m,i,j;
	cin>>n>>m;
	LL *vertices=new LL [n];
	bool *mark=new bool [n];
	for(i=0;i<n;i++)
	{
		cin>>vertices[i];
		mark[i]=true;
	}
	short edge[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			edge[i][j]=0;
	for(i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		edge[x-1][y-1]=1;
		edge[y-1][x-1]=1;
	}	
	// well calculating the edge
	LL profit[n][2];
	for(i=0;i<n;i++)
	{
		LL count=0;
		LL sum=0;
		for(j=0;j<n;j++)
		{
			if(edge[i][j])
			{
				count++;
				sum+=vertices[j];
			}
		}
		profit[i][0]=sum;
		profit[i][1]=count*vertices[i];
	}
	LL sum=0;
	for(i=1;i<=n-1;i++)
	{
		LL max;
		LL max_ind;
		for(j=0;j<n;j++)
			if(mark[j])
			{
				max=profit[j][1]-profit[j][0];
				max_ind=j;
				break;
			}
		for(j=max_ind+1;j<n;j++)
		{
			if(mark[j])
			{
				if((profit[j][1]-profit[j][0])>max)
				{
					max=profit[j][1]-profit[j][0];
					max_ind=j;
				}
				else if(profit[j][1]-profit[j][0]==max)
				{
					if(profit[j][0]<profit[max_ind][0])
						max_ind=j;
				}
			}
		}
		sum+=profit[max_ind][0];
		for(j=0;j<n;j++)
		{
			if(edge[max_ind][j]==1 && mark[j])
			{
				profit[j][0]=profit[j][0]-vertices[max_ind];
				profit[j][1]=profit[j][1]-vertices[j];
			}
			
		}
		mark[max_ind]=false;
	}
	cout<<sum<<"\n";
	return 0;
}