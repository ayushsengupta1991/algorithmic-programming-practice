#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long t;
	scanf("%ld",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		// 1
		if(n>360)
			printf("n ");
		else if(360%n!=0)
			printf("n ");
		else printf("y ");
		//2
		if(n>360)
			printf("n ");
		else printf("y ");
		//3
		if(n>=360)
			printf("n ");
		else
		{
			long long int x=(n*(n-1))/2;
			if(x>360)
				printf("n ");
			else if(360-x<=n-1)
				printf("n ");
			else printf("y ");
		}
		printf("\n");
				
	}
	
	return 0;
}