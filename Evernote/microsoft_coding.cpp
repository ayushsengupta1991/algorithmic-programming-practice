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
#define FOR1(n) for(LL i=0;i<n;i++)
#define FOR2(x,n) for(LL i=x;i<n;i++)
#define FOR3(m,n) for(LL i=0;i<m;i++) for(LL j=0;j<n;j++)
#define SIZE(x) int((x).size())
using namespace std;
struct bool_wrapper
{
	bool val;
	bool_wrapper()
	{
		val = false;
	}
};
int main()
{
	string line;
	map<string, map<string, bool_wrapper> > hashMap;
	while(cin>>line)
	{
		//cout<<line<<"\n";
		string delim1 = ":";
		string delim2 = ",";
		string token;
		size_t pos=0;
		pos = line.find(delim1);
		string head = line.substr(0,pos);
		string tail = line.substr(pos+1);
		map<string, bool_wrapper> list;
		int i=0;
		while((pos = tail.find(delim2)) != string::npos)
		{
			token = tail.substr(0,pos);
			list[token].val = true;
			i++;
			tail.erase(0, pos + delim2.length());
		}
		if(i>0)
		{
			hashMap[head] = list;
			//cout<<"First type done\n";
		}
		else
		{
			// this is just a query
			//cout<<"Second Type\n";
			queue<string> bfs;
			map<string, bool_wrapper> mark;
			bool there = false;
			if(hashMap[head][tail].val)
			{
				cout<<"YES(Direct)\n";
				there = true;
			}
			else
			{
				for(auto it = hashMap[head].begin(); it!= hashMap[head].end(); ++it)
				{
					if(!mark[it->first].val)
					{
						bfs.push(it->first);
						mark[it->first].val = true;
					}
				}
				while(!bfs.empty())
				{
					string f = bfs.front();
					cout<<bfs.front()<<" "<<bfs.back()<<"\n";
					if(hashMap[f][tail].val){
						cout<<"YES(Indirect)\n";
						there = true;
						break;
					}
					for(auto it = hashMap[f].begin(); it!= hashMap[f].end(); ++it)
					{
						if(!mark[it->first].val)
						{
							bfs.push(it->first);
							mark[it->first].val = true;
						}
					}
					bfs.pop();
				}
			}
			if(!there)
				cout<<"NO\n";
			
		}
	}
	return 0;
}