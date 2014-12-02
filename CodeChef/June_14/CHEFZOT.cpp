#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int first=0,second=0,max=0,i;
	for(i=1;i<=n+1;i++)
	{
		int val;
		if(i==n+1)
			val=0;
		else
			cin>>val;
		if(val==0)
		{
			second=i;
			if((second-first-1)>max)
				max=second-first-1;
			first=second;
			
		}
	}
	cout<<max<<"\n";
	return 0;
}