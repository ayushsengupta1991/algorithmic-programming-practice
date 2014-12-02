#include<iostream>
using namespace std;
long long int absolute(long long int a,long long int b)
{
	if(a<b)
		return b-a;
	else return a-b;
}
long long int calcPow(long long int a,long long int b)
{
	if(b==0) return 1;
	if(b==1) return a;
	long long int r=calcPow(a,b/2);
	if(b%2==0)
		return r*r;
	else return r*r*a;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long int a,b,x;
		cin>>a>>b>>x;
		if(b<0)
		{
			if(a==1)
			{
				long long int v=1/x;
				cout<<v<<"\n";
			}
			else if(a==-1)
			{
				if(b%2==0)
				{
					long long int v=1/x;
					cout<<v<<"\n";
				}
				else
				{
					long long int v=-1/x;
					cout<<v<<"\n";
				}
			}
			else
				cout<<"0\n";
		}
		else
		{
			long long int r=calcPow(a,b);
			long long int guess=r/x;
			long long int mul=guess;
			if(absolute(mul*x,r)>absolute((guess+1)*x,r))
				mul=guess+1;
			if(absolute(mul*x,r)>absolute((guess-1)*x,r))
				mul=guess-1;
			
			cout<<mul*x<<"\n";
		}
	}
	return 0;    
}