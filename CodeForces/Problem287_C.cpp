#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
#define ULL unsigned long long
using namespace std;
ULL power(ULL a,ULL b)
{
	ULL product=1;
	for(ULL i=1;i<=b;i++)
		product=product*a;
	return product;
}
void countSum(ULL &sum,bool dir,ULL h,ULL n)
{
	if(h==0)
	{
		return;
	}
	if(dir)
	{
		if(n<=power(2,h-1))
		{
			sum++;
			countSum(sum,false,h-1,n);
		}
		else
		{
			sum=sum+(power(2,h));
			countSum(sum,true,h-1,n-power(2,h-1));
		}
	}
	else
	{
		if(n<=power(2,h-1))
		{
			sum=sum+power(2,h);
			countSum(sum,false,h-1,n);
		}
		else
		{
			sum++;
			countSum(sum,true,h-1,n-power(2,h-1));
		}
	}
}
int main()
{
	ULL sum=0;
	ULL h;
	ULL n;
	cin>>h>>n;
	countSum(sum,true,h,n);
	cout<<sum;
	return 0;
}
