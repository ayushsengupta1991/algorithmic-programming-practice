#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#define LL long long int
using namespace std;
int main()
{
	char str[1020];
	scanf("%[^\n]%*c",str);
	int i;
	int hash[26];
	for(i=0;i<26;i++)
		hash[i]=0;
	for(i=0;i<strlen(str);i++)
	{
		if(int(str[i])>=97 && int(str[i])<=122)
			hash[int(str[i])-97]=1;
	}
	int count=0;
	for(i=0;i<26;i++)
	{
		//cout<<hash[i]<<" ";
		if(hash[i]==1)
			count++;
	}
	cout<<count<<"\n";
	return 0;
}