#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		vector<int> c;
		int i=0,j;
		while(i<n)
		{
			int s=0;
			while(str[i]=='1')
			{
				s++;
				i++;
				if(i==n)
					break;
			}
			if(s>0)
				c.push_back(s);
			i++;
		}
		long long int sum=0;
		for(i=0;i<c.size();i++)
			sum+=(c[i]*(c[i]+1))/2;
		for(i=0;i<c.size();i++)
			for(j=i+1;j<c.size();j++)
				sum+=c[i]*c[j];
		cout<<sum<<"\n";
	}
	return 0;
}