#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	long n;
	cin>>n;
	long i=1,j;
	while(true)
	{
		long sum=0;
		for(j=1;j<=i;j++)
			sum+=(j*(j+1))/2;
		if(sum>n)
			break;
		i++;
	}
	cout<<(i-1)<<"\n";
	return 0;
}