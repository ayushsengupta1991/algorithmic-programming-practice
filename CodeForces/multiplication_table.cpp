#include<iostream>
using namespace std;
int main()
{
	long long int count=0;
	long long int n,x;
	cin>>n>>x;
	for(long long int i=1;i<=n;i++)
	{
		if(x%i==0 && x<=i*n)
			count++;
	}
	cout<<count<<"\n";
	return 0; 
}