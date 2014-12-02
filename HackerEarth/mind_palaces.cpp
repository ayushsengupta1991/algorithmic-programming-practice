#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,n,m;
	scanf("%d %d",&n,&m);
	long **matrix=new long *[n];
	for(i=0;i<n;i++)
		matrix[i]=new long [m];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%ld",&matrix[i][j]);
	
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long val;
		scanf("%ld",&val);
		i=0;
		j=m-1;
		int posx=-1,posy=-1;
		//cout<<val<<"\n";
		while(i<n && j>=0)
		{
			if(matrix[i][j]==val)
			{
				//cout<<"1 ";
				posx=i;
				posy=j;
				break;
			}
			else if(matrix[i][j]>val)
			{
				//cout<<"2 ";
				j--;
			}
			else
			{
				//cout<<"3 ";
				i++;
			}
		}
		printf("%d %d\n",posx,posy);
	}
	return 0;
}