#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int adj[100][100][100];
int n,m;
bool reachable(int s,int t,int c)
{
	int i;
	queue<int> q;
	int *mark=new int [n];
	for(i=0;i<n;i++)
		mark[i]=0;
	q.push(s);
	while(!q.empty())
	{
		int r=q.front();
		mark[r]=1;
		if(r==t)
			return true;
		for(i=0;i<n;i++)
			if(adj[c][r][i]==1 && mark[i]==0)
				q.push(i);
		q.pop();
	}
	return false;
}
int main()
{
	
	int i,j,k;
	cin>>n>>m;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				adj[i][j][k]=0;
	
	for(i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adj[c-1][a-1][b-1]=1;
		adj[c-1][b-1][a-1]=1;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int u,v,c,sum=0;
		cin>>u>>v;
		u--;v--;
		for(c=0;c<m;c++)
			if(reachable(u,v,c))
				sum++;
		cout<<sum<<"\n";
	}
	
	return 0;
}