#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	if(s>0)
	{
		long long int *dp =new long long int [s.size()];
		dp[0]=1;
		for(int i=1;i<s.size();i++)
		{
			int curr=s[i]-'0';
			int prev=s[i-1]-'0';
			if(curr==0)
				dp[i]=dp[i-1];
			else if(prev==0)
				dp[i]=dp[i-1];
			else
			{
				dp[i]=dp[i-1];
				if(prev*10+curr <= 26)
					dp[i]+=dp[i-2];
			}
		}
	}
	else
		cout<<"-1\n";
	return 0;
}