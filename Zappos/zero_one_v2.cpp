#include<iostream>
#include<queue>
#define length 71
using namespace std;
long long int *table=new long long int [length];
long long int power(int x)
{
	long long int product=1;
	for(int i=1;i<=x;i++)
		product*=2;
	return product;
}
string convertToString(long long int v)
{
	while(v>0)
	{
		
	}
}
long long int getSum(long long int i)
{
	while(i>0)
	{
		
	}
}
string subsetSum(long long int n,long long int val,long long int mod)
{
	if(n==1)
	{
		if(val==0)
			return "0";
		else if(val==1)
			return "1";
	}
	else
	{
		int first=n/2;
		int last=n-first;
		long long int v1=-1,v2;
		map<long long int,int> hm;
		for(long long int i=0;i<power(last+1);i++)
		{
			long long int curr=(getSum(i)%mod);
			hm[curr]=1;
		}
		long long int imp;
		for(i=0;i<power(first+1);i++)
		{
			long long int curr=(getSum(i)%mod);
			if(hm[n-curr]==1)
			{
				v1=i;
				imp=n-curr;
				break;
			}
		}
		if(v1!=-1)
		{
			for(i=0;i<power(last+1);i++)
			{
			long long int curr=(getSum(i)%mod);
			if(curr==imp)
				v2=i;
			}
			string ret=convertToString(v1)+convertToString(v2);
			return ret;
		}
		
	}
	return "n";
}
int main()
{
	long long int n,s,i;
	cin>>n>>s;
	table[0]=(1%n);
	for(i=1;i<length;i++)
	{
		table[i]=(table[i-1]*10)%n;
	}
	if(table[0]==0)
	{
		cout<<1<<"\n";
		return 0;
	}
	for(i=2;i<length;i++)
	{
		long long int val=(n-table[i-1]);
		string r=subsetSum(i-1,val,n);
		if(r.compare("n")!=0)
		{
			string r="1"+r;
			cout<<r<<"\n";
			return 0;
		}
	}
	return 0;
}