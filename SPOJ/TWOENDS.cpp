// http://www.spoj.com/problems/TWENDS/

#include<iostream>
using namespace std;
long max(long x,long y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int j=1;
	while(true)
	{
		int n;
		cin>>n;
		if(n==0) break;
		//long *a=new long [n];
		int i=1;
		long sumE=0,sumO=0;
		for(i=1;i<=n;i++)
		{
			long r;
			cin>>r;
			if(i%2==1)
				sumO+=r;
			else
				sumE+=r;	
		}
		cout<<"In game "<<j<<", the greedy strategy might lose by as many as "<<(2*max(sumO,sumE))-(sumO+sumE)<<" points.\n";
		j++;
		
	}
	return 0;
}
