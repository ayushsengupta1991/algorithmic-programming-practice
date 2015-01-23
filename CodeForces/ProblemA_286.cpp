#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
bool isPalin(char s[],int n)
{
	int i=0,j=n-1;
	while(i<=j)
	{
		if(s[i]!=s[j])
			return false;
		i++;j--;
	}
	return true;
}
void insert(char s[],int i,char ch,int n)
{
	int j;
	for(j=n;j>=i;j--)
		s[j+1]=s[j];
	s[i]=ch;
}
void erase(char s[],int i,int n)
{
	int j;
	for(j=i;j<n;j++)
		s[j]=s[j+1];
}
int main()
{
	char s[12];
	cin>>s;
	int n=strlen(s);
	int i,j,k;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<26;j++)
		{
			insert(s,i,char(97+j),n);
			if(isPalin(s,n+1))
			{
				cout<<s<<"\n";
				return 0;
			}
			erase(s,i,n+1);
		}
	}
	cout<<"NA\n";
	return 0;
}