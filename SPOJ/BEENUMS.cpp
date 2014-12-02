// Problem Code: BEENUMS
#include<iostream>
#include<vector>
#define LIMIT 1000000000
using namespace std;
int main()
{
	
	long long int n;
	//n=0;
	while(true)
	{
		cin>>n;
		if(n==-1)
			break;
		if(n==1)
			cout<<"Y\n";
		else
		{
			n=n-1;
			if(n%3!=0)
				cout<<"N\n";
			else
			{
				n=n/3;
				long i;
				bool flag=false;
				for(i=1;i*(i+1)<=n;i++)
				{
					if(i*(i+1)==n)
					{
						cout<<"Y\n";
						flag=true;
					}
				}
				if(!flag)
					cout<<"N\n";
			}
		}
	}
	
	return 0;
}