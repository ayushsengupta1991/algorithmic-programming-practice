#include<iostream>
#include<cstring>
using namespace std;
bool isPalin(char a[],int i,int j)
{
	while(i<=j)
	{
		if(a[i]!=a[j])
			return false;
		i++;
		j--;
	}
	return true;
}
int solve(char a[])
{
	int i=0,j=strlen(a)-1;
	for(;i<=j;i++,j--)
	{
		if(a[i]!=a[j])
		{
			if(isPalin(a,i,j-1))
				return j;
			else return i;
		}
	}
	return -1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char str[100010];
		cin>>str;
		cout<<solve(str)<<"\n";
	}
	return 0;    
}