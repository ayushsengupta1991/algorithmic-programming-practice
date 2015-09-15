#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

string sortChar(string s)
{
	transform(s.begin(),s.end(),s.begin(),::tolower);
	int *count = new int [26];
	for(int i=0;i<(int)s.size();++i)
		count[s[i]-'a']++;
	string sc="";
	for(int i=0;i<26;++i)
	{
		while(count[i]--)
			sc=sc + char(97+i);
	}
	return sc;
}

int main()
{
	map<string,vector<string> > anagrams;
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		string sc=sortChar(s);
		anagrams[sc].push_back(s);
	}
	int counter=1;
	for(map<string,vector<string> >::iterator it=anagrams.begin();it!=anagrams.end();++it)
	{
		cout<<"Type#"<<counter++<<": ";
		for(int i=0;i<(*it).second.size();++i)
			cout<<(*it).second[i]<<" ";
		cout<<"\n";
	}
	return 0;
}