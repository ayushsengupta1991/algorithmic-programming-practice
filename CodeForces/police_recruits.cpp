#include<iostream>
using namespace std;
int main()
{
	long long int n;
	long long int sum=0,negative=0;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		if(x>0)
			sum=sum+x;
		else
		{
			if(sum==0)
				negative++;
			else sum--;
		}
	}
	cout<<negative<<"\n";
	return 0;
}