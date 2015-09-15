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
LL factorial(LL n)
{
	if(n==0) return 1;
	else if(n==1) return 1;
	else return n*factorial(n-1);
}
int main()
{
	string s;
	//int n=2;
	while(cin>>s)
	{
		
		vector<LL> count;
		for(LL i=0;i<26;++i)
			count.push_back(0);
		for(LL i=0;i<(LL)s.size();++i)
			count[LL(s[i]-'a')]++;
		
		LL even=0;
		LL odd=0;
		for(int i=0;i<26;i++)
		{
			if(count[i]%2==0)
				even++;
			else odd++;
		}
		if(odd<=1)
		{
			cout<<"0,";
			vector<LL> temp;
			LL totsum=0;
			for(LL i=0;i<26;i++)
			{
				if(count[i]>0){
				temp.push_back(count[i]/2);
				totsum+=count[i]/2;
				}
			}
			LL ways = factorial(totsum);
			for(LL i=0;i<temp.size();i++)
				ways=ways/factorial(temp[i]);
			cout<<ways<<"\n";
		//	cout<<s<<"\n";
			
		}
		else
		{
			LL change = odd-1;
			cout<<change<<",";
			bool odd_counter=false;
			vector<LL> temp;
			LL totsum=0;
			for(LL i=0;i<26;i++)
			{
				if(count[i]>0){
				if(count[i]%2==1 && !odd_counter)
				{
					odd_counter=true;
					temp.push_back(count[i]/2);
					totsum += count[i]/2;
				}
				else if(count[i]%2==1 && odd_counter)
				{
					temp.push_back((count[i]-1)/2);
					totsum += (count[i]-1)/2;
				}
				else {temp.push_back(count[i]/2); totsum += count[i]/2;}
				}
			}
			LL ways = factorial(totsum);
			for(LL i=0;i<temp.size();i++)
				ways=ways/factorial(temp[i]);
			cout<<ways<<"\n";
		//	cout<<s<<"\n";
		}
		
	}
	return 0;
}
