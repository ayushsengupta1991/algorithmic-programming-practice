#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char *exp=new char [1000009];
		cin>>exp;
		long long int i,j=-1,stack=0;
		for(i=0;i<strlen(exp);i++)
		{
			if(exp[i]=='<')
				stack++;
			else stack--;
			if(stack==0)
				j=i;
			if(stack<0)
				break;
		}
		cout<<j+1<<"\n";	
	}
	return 0;
}