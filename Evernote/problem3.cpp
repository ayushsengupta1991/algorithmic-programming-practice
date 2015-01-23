#include<iostream>
using namespace std;
int main()
{
	int N,i;
	cin>>N;
	int *list=new int [N];
	for(i=0;i<N;i++)
		cin>>list[i];
	long long int *left=new long long int [N];
	long long int *right=new long long int [N];
	left[0]=1;
	right[N-1]=1;
	for(i=1;i<N;i++)
		left[i]=left[i-1]*list[i-1];
	for(i=N-2;i>=0;i--)
		right[i]=right[i+1]*list[i+1];
	for(i=0;i<N;i++)
	{
		cout<<left[i]*right[i]<<"\n";
	}
	return 0;
}
