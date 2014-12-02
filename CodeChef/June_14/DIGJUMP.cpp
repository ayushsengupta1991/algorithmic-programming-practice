//01239435146784
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define N 100000
using namespace std;
int minimumDJ(int x,int y,int z)
{
	int min=x;
	if(y<min)	min=y;
	if(z<min)	min=z;
	return min;
}
int main()
{
	vector<int> sameDigit[10];
	bool markDigit[10];
	int i;
	char s[N+20];
	cin>>s;
	int n=strlen(s);
	for(i=0;i<n;i++)
		sameDigit[s[i]-'0'].push_back(i);
	int *min=new int [n];
	
	for(i=0;i<10;i++)
		markDigit[i]=true;
	
	min[0]=0;
	for(i=1;i<n;i++)
		min[i]=2*N;
	queue<int> bfs;
	bfs.push(0);
	while(!bfs.empty())
	{
		int x=bfs.front();
		bfs.pop();
		if(x>0)
		{
			if(min[x-1]==2*N)
			{
				min[x-1]=min[x]+1;
				bfs.push(x-1);
			}
		}
		if(x<n-1)
		{
			if(min[x+1]==2*N)
			{
				min[x+1]=min[x]+1;
				bfs.push(x+1);
			}
		}
		int d=s[x]-'0';
		if(markDigit[d])
		{
			for(int j=0;j<sameDigit[d].size();j++)
				if(min[sameDigit[d][j]]==2*N)
				{
					min[sameDigit[d][j]]=min[x]+1;
					bfs.push(sameDigit[d][j]);
				}
			markDigit[d]=false;
		}
	}
	cout<<min[n-1]<<"\n";
	return 0;
}