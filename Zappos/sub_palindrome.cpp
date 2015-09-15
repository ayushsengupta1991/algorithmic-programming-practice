#include <map>
#include <set>
#include <list>
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
#include <string>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int palindrome(string str)
{
	bool **dp=new bool *[str.size()];
	int i,j;
	int count=0;
	for(i=0;i<str.size();i++)
	{
		dp[i]=new bool [str.size()];
	}
	
	
	for(i=0;i<str.size();i++)
		for(j=0;j<str.size();j++)
			dp[i][j]=false;
	//map<char,int> hm1;
	//map<string,int> hm2;
	set<char> s1;
	set<string> s2;
	for(i=0;i<str.size();i++)
	{
		
		dp[i][i]=true;
		s1.insert(str[i]);
			
		if(i!=0)
		{
			if(str[i-1]==str[i])
			{
				dp[i-1][i]=true;
				s2.insert(str.substr(i-1,2));
			}
		}
	}
	count+=s1.size()+s2.size();
	int l;
	
	for(l=3;l<=str.size();l++)
	{
		set<string> s3;
		//map<string,int> hm;
		for(i=0;i+l-1<str.size();i++)
		{
			if(str[i]==str[i+l-1] && dp[i+1][i+l-2])
			{
				dp[i][i+l-1]=true;
				s3.insert(str.substr(i,l));
				
			}
		}
		count+=s3.size();
	}
		
	return count;		
}
int main()
{
	string s;
	cin>>s;
	cout<<palindrome(s)<<"\n";
	return 0;
}