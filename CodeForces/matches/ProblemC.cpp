#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#define LL long long int
using namespace std;
struct point
{
	int x;
	int y;
};
int main()
{
	int n,m,k,i,j;
	cin>>n>>m>>k;
	short board[n+1][m+1];
	/*for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			board[i][j]=0;
		*/
	vector<point> *v=new vector<point> [k];
	int R=(k-1)*2,direction=1;
	int total=n*m;
	//first tube
	point curr;
	curr.x=1;
	curr.y=1;
	while(total>R)
	{
		v[0].push_back(curr);
		//board[curr.x][curr.y]=1;
		total--;
		if(direction==1)
		{
			if(curr.y<m)
				curr.y++;
			else if(curr.y==m)
			{
				direction=-1;
				curr.x++;
			}
		}
		else 
		{
			if(curr.y>1)
				curr.y--;
			else if(curr.y==1)
			{
				direction=1;
				curr.x++;
			}
		}
		
	}
	// for all other tubes
	for(i=1;i<=k-1;i++)
	{
		for(j=1;j<=2;j++)
		{
			//cout<<curr.x<<" "<<curr.y<<"\n";
			v[i].push_back(curr);
			total--;
			if(direction==1)
			{
				if(curr.y<m)
					curr.y++;
				else if(curr.y==m)
				{
					direction=-1;
					curr.x++;
				}
			//	cout<<"\naye1\n";
			}
			else 
			{
				if(curr.y>1)
					curr.y--;
				else if(curr.y==1)
				{
					direction=1;
					curr.x++;
				}
			//	cout<<"\naye2\n";
			}
		}
	}
	for(i=0;i<k;i++)
	{
		cout<<v[i].size()<<" ";
		for(j=0;j<v[i].size();j++)
			cout<<v[i][j].x<<" "<<v[i][j].y<<" ";
		cout<<"\n";
	}
	return 0;
}