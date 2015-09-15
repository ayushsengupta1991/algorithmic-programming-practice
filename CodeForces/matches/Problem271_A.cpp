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
	string a="qwertyuiop";
	string b="asdfghjkl;";
	string c="zxcvbnm,./";
	char ch;
	cin>>ch;
	int i,j;
	string s;
	cin>>s;
	if(ch=='R')
	{
		for(i=0;i<s.size();i++)
		{
			bool done=false;
			for(j=0;j<a.size();j++)
				if(s[i]==a[j]){
					
					cout<<a[j-1];
					done=true;
					break;
				}
			if(done)
				continue;
			for(j=0;j<b.size();j++)
				if(s[i]==b[j]){
					
					cout<<b[j-1];
					done=true;
					break;
				}
			if(done)continue;	
			for(j=0;j<c.size();j++)
				if(s[i]==c[j]){
					
					cout<<c[j-1];
					done=true;
					break;
				}	
		}
	}
	else
	{
		for(i=0;i<s.size();i++)
		{
			bool done=false;
			for(j=0;j<a.size();j++)
				if(s[i]==a[j]){
					
					cout<<a[j+1];
					done=true;
					break;
				}
				if(done)
					continue;
				for(j=0;j<b.size();j++)
					if(s[i]==b[j]){
						
						cout<<b[j+1];
						done=true;
						break;
					}
					if(done)continue;	
					for(j=0;j<c.size();j++)
						if(s[i]==c[j]){
							
							cout<<c[j+1];
							done=true;
							break;
						}	
		}
	}
	cout<<"\n";
	return 0;
}
