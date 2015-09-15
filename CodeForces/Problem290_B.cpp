#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cstring>
typedef long long int LL;
using namespace std;
struct node
{
	int i;
	int j;
	int pi;
	int pj;
};
int mark[50][50];
int m,n;
bool dfs(vector<string> g,int i,int j)
{
	char color=g[i][j];
	struct node x;
	x.i=i;
	x.j=j;
	x.pi=-1;
	x.pj=-1;
	stack<struct node> st;
	st.push(x);
	while(!st.empty())
	{
		struct node temp=st.top();
		//st.pop();
		mark[temp.i][temp.j]=1;
		int didPush=0;
		if(temp.i-1>=0 && g[temp.i-1][temp.j]==color)
		{
			if(mark[temp.i-1][temp.j]==1 && ((temp.i-1!=temp.pi) || (temp.j!=temp.pj)))
			{
				return true;
			}
			else if(mark[temp.i-1][temp.j]==0)
			{
				struct node add;
				add.i=temp.i-1;
				add.j=temp.j;
				add.pi=temp.i;
				add.pj=temp.j;
				st.push(add);
				didPush++;
			}
		}
		
		if(temp.j-1>=0 && g[temp.i][temp.j-1]==color)
		{
			if(mark[temp.i][temp.j-1]==1 && ((temp.i!=temp.pi) || (temp.j-1!=temp.pj)))
			{
				return true;
			}
			else if(mark[temp.i][temp.j-1]==0)
			{
				struct node add;
				add.i=temp.i;
				add.j=temp.j-1;
				add.pi=temp.i;
				add.pj=temp.j;
				st.push(add);
				didPush++;
			}
		}
		
		if(temp.i+1<m && g[temp.i+1][temp.j]==color)
		{
			if(mark[temp.i+1][temp.j]==1 && ((temp.i+1!=temp.pi) || (temp.j!=temp.pj)))
			{
				return true;
			}
			else if(mark[temp.i+1][temp.j]==0)
			{
				struct node add;
				add.i=temp.i+1;
				add.j=temp.j;
				add.pi=temp.i;
				add.pj=temp.j;
				st.push(add);
				didPush++;
			}
		}
		
		if(temp.j+1<n && g[temp.i][temp.j+1]==color)
		{
			if(mark[temp.i][temp.j+1]==1 && ((temp.i!=temp.pi) || (temp.j+1!=temp.pj)))
			{
				return true;
			}
			else if(mark[temp.i][temp.j+1]==0)
			{
				struct node add;
				add.i=temp.i;
				add.j=temp.j+1;
				add.pi=temp.i;
				add.pj=temp.j;
				st.push(add);
				didPush++;
			}
		}
		if(didPush==0)
			st.pop();
		
	}
	return false;
}
int main()
{
	
	cin>>m>>n;
	vector<string> g;
	int i,j;
	for(i=0;i<m;i++)
	{
		string x;
		cin>>x;
		g.push_back(x);
	}
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			mark[i][j]=0;
	bool ans=false;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			if(mark[i][j]==0)
			{
				ans=ans || dfs(g,i,j);
				if(ans)
					break;
			}
			if(ans)
				break;
		}
	if(ans)
		cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
