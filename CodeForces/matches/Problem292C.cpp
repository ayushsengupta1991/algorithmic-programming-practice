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
int *power=new int [4];
int prime[4]={2,3,5,7};
map<int,int> mp;
LL factorial(int r)
{
	if(r==0)
		return 1;
	else return r*factorial(r-1);
}
void addPower(int r)
{
	LL total=factorial(r);
	for(int i=0;i<4;i++)
	{
		while(total%prime[i]==0)
		{
			total/=prime[i];
			power[i]++;
		}
	}
}
void subtractPower(int r)
{
	LL total=factorial(r);
	for(int i=0;i<4;i++)
	{
		while(total%prime[i]==0)
		{
			total/=prime[i];
			power[i]--;
		}
	}
}
/*bool valid()
{
	
}
*/
int main()
{
	int n,i;
	string s;
	cin>>n;
	cin>>s;
	for(i=0;i<4;i++)
		power[i]=0;
	mp[2]=0;
	mp[3]=1;
	mp[5]=2;
	mp[7]=3;
	for(i=0;i<n;i++)
	{
		if(s[i]-'0'>=2 && s[i]-'0'<=9)
		{
			addPower(s[i]-'0');
		}
	}
	vector<int> digits;
	for(i=3;i>=0;i--)
	{
		while(power[i]>0)
		{
			subtractPower(prime[i]);
			digits.push_back(prime[i]);
		}
	}
	for(i=0;i<SIZE(digits);i++)
		cout<<digits[i];
	cout<<"\n";
	return 0;
}
