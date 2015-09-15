#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;
struct TrieNode
{
	bool leaf;
	string val;
	TrieNode *next[27];
	TrieNode()
	{
		leaf=false;
		val="";
		int i;
		for(i=0;i<27;i++)
			next[i]=NULL;
	}
};
void preOrder(struct TrieNode *root,vector<string> &ans)
{
	if(root)
	{
		if(root->leaf)
		{
			ans.push_back(root->val);
		}
		else
		{
			int i;
			for(i=0;i<27;i++)
				preOrder(root->next[i],ans);
		}
	
	}
	return;
}
void trieInsert(TrieNode *root,string s)
{
	s+='{';
	int i=0;
	while(root->next[int(s[i]-'a')])
		root=root->next[int(s[i++]-'a')];
	if(i==s.size())
		return;
	else
	{
		while(i<s.size())
		{
			struct TrieNode *temp=new struct TrieNode;
			root->next[int(s[i]-'a')]=temp;
			root=temp;
			i++;
		}
		root->leaf=true;
		root->val=s.substr(0,s.size()-1);
		return;
	}
}
vector<string> trieFind(TrieNode *root,string s)
{
	vector<string> ans;
	if(!root)
		return ans;
	int i=0;
	while(i<s.size())
	{
		root=root->next[int(s[i]-'a')];
		if(!root)
			return ans;
		preOrder(root,ans);
	}
	return ans;
	
}
int main()
{
	struct TrieNode *root=new struct TrieNode;
	trieInsert(root,"string1");
	trieInsert(root,"string2");
	trieInsert(root,"str");
	vector<string> s=trieFind(root,"st");
	for(int i=0;i<s.size();i++)
		cout<<s[i]<<"\n";
	return 0;
}
