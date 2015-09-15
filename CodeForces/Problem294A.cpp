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
int convertSmall(char ch)
{
	if(ch=='q')
		return 9;
	if(ch=='r')
		return 5;
	if(ch=='b')
		return 3;
	if(ch=='n')
		return 3;
	if(ch=='p')
		return 1;
	return 0;
}
int convertCapital(char ch)
{
	if(ch=='Q')
		return 9;
	if(ch=='R')
		return 5;
	if(ch=='B')
		return 3;
	if(ch=='N')
		return 3;
	if(ch=='P')
		return 1;
	return 0;
}

bool isCapital(char ch)
{
	if(ch>='A' && ch<='Z')
		return true;
	return false;
}
bool isSmall(char ch)
{
	if(ch>='a' && ch<='z')
		return true;
	return false;
}
int main()
{
	string s;
	int i;
	int black=0;
	int white=0;
	for(i=1;i<=8;i++)
	{
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			if(isSmall(s[j]))
			{
				black+=convertSmall(s[j]);
			//	cout<<black<<" ";
			}
			else if(isCapital(s[j])){
				white+=convertCapital(s[j]);
			//	cout<<white<<" ";
			}
		//	else cout<<".";
			
		}
		//cout<<"\n";
	}
	//cout<<white<<" "<<black<<"\n";
	if(white>black)
		cout<<"White\n";
	else if(white<black)
		cout<<"Black\n";
	else cout<<"Draw\n";
	return 0;
}
