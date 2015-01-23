#include<iostream>
using namespace std;
bool *sieve=new bool [100000];
long long int gcd(long long int x,long long int y)
{
	if(x<y)
		return gcd(y,x);
	if(x%y==0)
		return y;
	else return (y,x%y);
}
long long findPrimeDivisor(long long int n)
{
	
}
int main()
{
	int n,m;
	cin>>n>>m;
	long long int *a=new long long int [n];
	int good[m][2];
	//int i=0;
	long i,j;
	sieve[1]=false;
	sieve[2]=true;
	while(i<m)
	{
		cin>>m[i][0]>>m[i][1];
		i++;
	}
	while(true)
	{
		
	}
	return 0;
}
