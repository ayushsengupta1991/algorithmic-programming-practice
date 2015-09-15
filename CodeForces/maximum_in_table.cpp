#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int i,j;
	int n;
	cin>>n;
	int a[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==0)
				a[i][j]=1;
			else if(j==0)
				a[i][j]=1;
			else
			{
				int sum=0;
				if(i-1>=0)
					sum+=a[i-1][j];
				if(j-1>=0)
					sum+=a[i][j-1];
				a[i][j]=sum;
			}
		}
	}
	cout<<a[n-1][n-1];
	return 0;
}

