#include<iostream>
#include<string>
#include<algorithms>
using namespace std;
int doSum(string s)
{
	int i;
	int sum=0;
	for(i=0;i<s.size();i++)
	{
		sum+=(s[i]-'0');
	}
	return sum;
}

string getInit(int sum)
{
	string ans;
	while(sum>=10)
	{
		ans.push_back(9+'0');
		sum-=9;
	}
	if(sum>0)
	{
		ans.push_back(sum+'0');
	}
	int i,j;
	for(i=0,j=ans.size()-1;i<=j;i++,j--)
	{
		char s=ans[i];
		ans[i]=ans[j];
		ans[j]=s;
	}
	return ans;
}
string getNextNumber(string x,int sum)
{
	string check=getInit(sum);
	if(check.size()>x.size())
		return check;
	else if(check.size()==x.size() && x.compare(check)==0)
	{
		if(sum%9==0)
			{
				string inter=getInit(sum-1);
				string ans="10";
				return (ans+inter);
			}
			else
			{
				x[0]=x[0]+1;
				if(x.size()>1)
					x[1]=x[1]-1;
				return x;
			}
			
		
	}
	else if(check.size()==x.size() && sum>doSum(x))
		return check;
	else
	{
		if(x[0]=='9')
		{
			vector<string> solutions;
			string ans="1";
			string inter=getInit(sum-1);
			int interZeros=x.size()-inter.size();
			for(int i=1;i<=interZeros;i++)
				ans=ans+'0';
			ans=ans+inter;
			solutions.push_back(ans);
			
			
		}
		else
		{
			x[0]=x[0]+1;
			string inter=getInit(sum-1);
			int interZeros=x.size()-(inter.size()+1);
			string ans="1";
			for(int i=1;i<=interZeros;i++)
				ans=ans+'0';
			ans+=inter;
			return ans;
		}
	
	}
}

int main()
{
	int i,n;
	cin>>n;
	int *b=new int [n];
	for(i=0;i<n;i++)
		cin>>b[i];
	string r=getInit(b[0]);
	cout<<r<<"\n";
	for(i=1;i<n;i++)
	{
		r=getInit(r,b[i]);
		cout<<r<<"\n";
	}
	return 0;
}