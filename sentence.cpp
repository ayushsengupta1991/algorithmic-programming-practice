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
int main()
{
	string s;
	while(getline(cin,s))
	{
		for(int i=0;i<(int)s.size();i++)
		{
			if(i==0)
			{
				if(isupper(s[0]))
					cout<<tolower(s[0]);
			}
			else if(s[i]=='.' || s[i]=='?' || s[i]=='!')
				{
					if(i+1<(int)s.size())
					{
						if(islower(s[i+1])
						{
							cout<<s[i]<<toupper(s[i+1]);
							i++;
						}
					}
				}
			else if(isupper(s[i]))
					cout<<tolower(s[i]);
			else 
			{
				cout<<s[i];
			}
		}
		cout<<"\n";
	}
	
	return 0;
}
