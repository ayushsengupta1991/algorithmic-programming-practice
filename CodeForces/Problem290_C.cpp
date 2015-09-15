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

int minimum(int a,int b)
{
	if(a<b)
		return a;
	else return b;
}
struct charSort
{
	char c;
	int time;
};
bool myfunc(struct charSort i,struct charSort j)
{
	return (i.time>j.time);
}
int *startTime=new int [26];
int *endTime=new int [26];
int g[26][26];
bool dfs()
{
	stack<int> st;
	int counter=0,i,j;
	for(i=0;i<26;i++)
	{
	if(startTime[i]==-1)
		st.push(i);
	//st.push(0);
	while(!st.empty())
	{
		int t=st.top();
		int didPush=0;
		if(startTime[t]==-1)
		{
			counter++;
			startTime[t]=counter;
			for(j=0;j<26;j++)
			{
				if(g[t][j]==1)
				{
					if(startTime[j]!=-1 && endTime[j]==-1)
						return false;
					else if(startTime[j]==-1 && endTime[j]==-1)
					{
						st.push(j);
						didPush++;
					}
				}
			}
		}
		if(didPush==0)
		{
			if(endTime[t]==-1){
			counter++;
			endTime[t]=counter;
			}
			st.pop();
		}
		
	}
	}
	return true;
}
int main()
{
	
	int i,j,k;
	for(i=0;i<26;i++)
		for(j=0;j<26;j++)
			g[i][j]=0;
	
	int n;
	cin>>n;
	vector<string> names;
	for(i=1;i<=n;i++)
	{
		string x;
		cin>>x;
		names.push_back(x);
	}
	for(i=0;i<names.size();i++)
	{
		for(j=i+1;j<names.size();j++)
		{
			bool diff=false;
			for(k=0;k<minimum(names[i].size(),names[j].size());k++)
			{
				if(names[i][k]!=names[j][k])
				{
					g[int(names[i][k])-97][int(names[j][k])-97]=1;
					diff=true;
					break;
				}
			}
			if(!diff && names[i].size()>names[j].size())
			{
				cout<<"Impossible\n";
				return 0;
			}
		}
	}
	for(i=0;i<26;i++)
	{
		startTime[i]=-1;
		endTime[i]=-1;
	}
	bool ans=dfs();
	if(ans)
	{
		vector<struct charSort> toSort;
		for(i=0;i<26;i++)
		{
			struct charSort x;
			x.c=char(i+97);
			x.time=endTime[i];
			//cout<<startTime[i]<<" "<<endTime[i]<<"\n";
			toSort.push_back(x);
		}
		sort(toSort.begin(),toSort.end(),myfunc);
		for(i=0;i<26;i++)
		{
			cout<<toSort[i].c;
		}
		cout<<"\n";
	}
	else
		cout<<"Impossible\n";
	return 0;
}
