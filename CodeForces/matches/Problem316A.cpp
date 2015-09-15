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
	cin>>n>>m;
	int *city_count=new int [n];
	int i,j;
	for(i=0;i<n;i++)
		city_count[i]=0;
	for(i=0;i<m;i++)
	{
		int max=-1,index=-1;
		for(j=0;j<n;j++)
		{
			int votes;
			cin>>votes;
			if(votes>max)
			{
				max=votes;
				index=j;
			}
		}
		city_count[index]++;
	}
	int max=-1,index=-1;
	for(i=0;i<n;i++)
	{
		if(city_count[i]>max)
		{
			max=city_count[i];
			index=i+1;
		}
	}
	cout<<index;
	return 0;
}