#include<iostream>
#define limit 1000000000
using namespace std;
int main()
{
	long long int n,k;
	cin>>n>>k;
	long long int *a=new long long int [n];
	long long int *x=new long long int [n];
	long long int *y=new long long int [n];
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	//done
	long long int max=a[0];
	for(i=1;i<n;i++)
		if(a[i]>max)
			max=a[i];
			
	for(i=0;i<n;i++)
	{
		x[i]=max-a[i];
		//cout<<x[i]<<" ";
	}
	
	max=x[0];
	for(i=1;i<n;i++)
		if(x[i]>max)
			max=x[i];
		
	for(i=0;i<n;i++)
	{
		y[i]=max-x[i];
		//cout<<y[i]<<" ";
	}
	
	if(k==0)
		for(i=0;i<n;i++)
			cout<<a[i]<<" ";
	else if(k%2==1) for(i=0;i<n;i++) cout<<x[i]<<" ";
	else for(i=0;i<n;i++) cout<<y[i]<<" ";
//	cout<<"\n";
	
	cout<<"\n";
	return 0;
}