#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
struct mark
{
	int val;
	bool visited;
};
struct node
{
	int val;
	string s;
};
bool myfunc(node i,node j)
{
	if(i.val>j.val)
		return true;
	else if(i.val<j.val)
		return false;
	else
		return (i.s<j.s);
}
int main()
{
	int i,n,k;
	cin>>n;
	map<string,struct mark> mp;
	vector<string> inp;
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		inp.push_back(s);
		mp[s].val=0;
		mp[s].visited=false;
	}
	cin>>k;
	for(i=0;i<inp.size();i++)
		mp[inp[i]].val++;
	vector<struct node> distinctString;
	for(i=0;i<inp.size();i++)
	{
		if(!mp[inp[i]].visited)
		{
			mp[inp[i]].visited=true;
			struct node temp;
			temp.s=inp[i];
			temp.val=mp[inp[i]].val;
			distinctString.push_back(temp);
		}
	}
	sort(distinctString.begin(),distinctString.end(),myfunc);
	for(i=0;i<k;i++)
		cout<<distinctString[i].s<<"\n";
		
	return 0;
}