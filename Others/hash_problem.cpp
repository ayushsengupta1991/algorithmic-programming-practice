#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<map>
#include<climits>
#define LIM 512
using namespace std;
string findWinner(vector<vector<string> > votes)
{
	unordered_map <string,bool> isValid;
	int i,j;
	for(i=0;i<(int)votes.size();++i)
		for(j=0;j<(int)votes[i].size();++j)
			if(!isValid[votes[i][j]])
				isValid[votes[i][j]]=true;
	//isValid initialized! 
	int totVotes=(int)votes.size();
	int loop=0;
	while(loop++ < isValid.size()){
		map<string,int> votesCount;
		for(auto it=isValid.begin();it!=isValid.end();++it)
			if(it->second)
				votesCount[it->first]=0;
		string maxVotes;
		string minVotes;
		int max=INT_MIN;
		int min=INT_MAX;
		for(i=0;i<(int)votes.size();++i)
		{
			for(j=0;j<(int)votes[i].size();++j)
			{
				if(isValid[votes[i][j]])
				{
					votesCount[votes[i][j]]=votesCount[votes[i][j]]+1;
					break;
				}
			}
		}
		for(auto it=votesCount.begin();it!=votesCount.end();++it)
		{
			if(it->second>max)
			{
				max=it->second;
				maxVotes = it->first;
				
			}
			if(it->second<max)
			{
				min=it->second;
				minVotes = it->first;
				
			}
		}
		if(max>votes.size()/2)
			return maxVotes;
		else
			isValid[minVotes]=false;
	}
}

int main()
{
	vector<vector<string> > votes;
	char first[LIM];
	cin.getline(first,LIM);
	istringstream inp(first);
	int n;
	inp>>n;
	for(int ii=1;ii<=n;++ii)
	{
		char s[LIM];
		cin.getline(s,LIM);
		istringstream s2(s);
		string p;
		vector<string> inp;
		while(s2>>p)
			inp.push_back(p);
		votes.push_back(inp);
	}
	cout<<findWinner(votes);
	return 0;
}
