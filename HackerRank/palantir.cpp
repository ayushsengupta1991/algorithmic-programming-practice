#include <iostream>
#include <algorithm>
#include <limits>
#include <map>
#include <string>
#include <vector>
using namespace std;
void flip(string &temp,int n)
{
	int j;
	for(j=0;j<n;j++){
		if(temp[j]=='P')
			temp[j]='T';
		else if(temp[j]=='T')
			temp[j]='P';
	}
}
int main() 
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int m,n,i,j;
	map<string,int> hm;
	cin>>m>>n;
	vector<string> inp;
	for(i=0;i<m;i++)
	{
		string temp;
		cin>>temp;
		inp.push_back(temp);
		hm[temp]=0;
		flip(temp,n);
		hm[temp]=0;
	}
	int curr_max=1;
	for(i=0;i<m;i++)
	{
		if(hm[inp[i]]==curr_max)
		{
			curr_max=curr_max+1;
			hm[inp[i]]++;
		}
		else hm[inp[i]]++;
		flip(inp[i],n);
		if(hm[inp[i]]==curr_max)
		{
			curr_max=curr_max+1;
			hm[inp[i]]++;
		}
		else hm[inp[i]]++;
	}
	cout<<curr_max<<"\n";
	return 0;
}