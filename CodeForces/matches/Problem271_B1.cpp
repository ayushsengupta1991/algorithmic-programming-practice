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
	int n;
	cin>>n;
	int *a=new int [n];
	LL sum=0,k=0;
	int i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int *ht=new int [sum+1];
	for(i=0;i<n;i++)
	{
		for(j=1;j<=a[i];j++)
		{
			ht[++k]=i+1;
		}
	}
	int m;
	cin>>m;
	for(i=0;i<m;i++)
	{
		int x;
		cin>>x;
		cout<<ht[x]<<"\n";
	}
	return 0;
}
