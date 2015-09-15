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
	string s;
	cin>>s;
	int i=1;
	int total=0,count;
	if(s.size()<=1)
	{
		cout<<0<<"\n";
		return 0;
	}
	while(i<s.size())
	{
		count=1;
		while(i<s.size() && s[i]==s[i-1])
		{
			i++;
			count=(count+1)%2;
		}
		if(count==0)
			total++;
		i++;
	}
	cout<<total<<"\n";
	return 0;
}