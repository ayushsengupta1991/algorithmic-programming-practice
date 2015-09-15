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
vector<vector <int> > sol;
    
    void solve(int i,int *mark,vector<int> &temp,vector<int> num)
    {
        if(i==num.size())
        {
            sol.push_back(temp);
            return;
        }
        int j;
        for(j=0;j<num.size();j++)
        {
            if(mark[j]==0)
            {
                mark[j]=1;
                temp[i]=num[j];
                solve(i+1,mark,temp,num);
                mark[j]=0;
            }
        }
        return;
    }
    
vector<vector<int> > permute(vector<int> &num) {
        
        vector<int> temp;
        int i;
        for(i=0;i<num.size();i++)
            temp.push_back(1);
        int *mark=new int [num.size()];
        for(i=0;i<num.size();i++)
            mark[i]=0;
        solve(0,mark,temp,num);
        return sol;
    }

int main()
{
	LL kk;
	int n,i,j,k,l;
	cin>>n>>kk;
	vector<int> num;
	LL total=0,curr=0;
	for(i=1;i<=n;i++)
	{
		num.push_back(i);
		total+=i*(n-i+1);
	}
	vector<vector<int> > ans=permute(num);
	for(i=0;i<ans.size();i++)
	{
		LL count=0;
		for(j=0;j<ans[i].size();j++)
		{
			for(k=j;k<ans[i].size();k++)
			{
				l=j;
				int min=ans[i][l];
				for(l=j+1;l<=k;l++)
				{
					min=minimum(min,ans[i][l]);
				}
				count+=min;
			}
		}
		if(count==total)
		{
			curr++;
			if(curr==kk)
			{
				for(j=0;j<ans[i].size();j++)
					cout<<ans[i][j]<<" ";
				return 0;
			}
		}
	}
	//LL total=0;
	
	return 0;
}
