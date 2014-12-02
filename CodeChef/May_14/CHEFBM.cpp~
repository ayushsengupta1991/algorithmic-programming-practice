#include<iostream>
using namespace std;
int main()
{
	int m,n,p;
	int i,j;
	cin>>n>>m>>p;
	int **mat=new int * [n];
	for(i=0;i<n;i++)
		mat[i]=new int [m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			mat[i][j]=j;
	}
	int **value=new int *[n];
	for(i=0;i<n;i++)
	{
		value[i]=new int [2];
		value[i][0]=m-1;
		value[i][1]=0;
	}
	for(int kk=1;kk<=p;kk++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		mat[x][y]++;
		if(m>1)
		{
			if(y==m-1)
			{
				value[x][0]++;
				if(mat[x][y]==mat[x][y-1])
					value[x][1]++;
			}
			else if(y==0)
			{
				value[x][0]--;
				if(mat[x][y]==mat[x][y+1]+1)
					value[x][1]--;
			}
			else
			{
				if(mat[x][y]==mat[x][y-1])
					value[x][1]++;
				if(mat[x][y]==mat[x][y+1]+1)
					value[x][1]--;
			}
		
		}
	
	}
	for(i=0;i<n;i++)
	{
		if(value[i][1]>=0)
			cout<<value[i][0]<<"\n";
		else
			cout<<"-1\n";
	}
	return 0;
}