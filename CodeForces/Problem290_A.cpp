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
int main()
{
	int n,m;
	int i,j;
	cin>>n>>m;
	string s=".";
	for(i=0;i<m-1;i++)
		s+='.';
	vector<string> v;
	for(i=0;i<n;i++)
		v.push_back(s);
	int x=0;
	while(x<n)
	{
		for(i=0;i<m;i++)
			v[x][i]='#';
		i--;
		if(x+2>=n)
			break;
		v[x+1][m-1]='#';
		x=x+2;
		for(i=m-1;i>=0;i--)
		{
			v[x][i]='#';
		}
		if(x+2>=n)
			break;
		v[x+1][0]='#';
		x=x+2;
	}
	for(i=0;i<n;i++)
		cout<<v[i]<<"\n";
	return 0;
}