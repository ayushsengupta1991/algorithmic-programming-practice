#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct metadata
{
	int length;
	char type;
};

int main() 
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	int n,k,i;
	cin>>n>>k;
	int *a=new int [n];
	for(i=0;i<n;i++)
		cin>>a[i];
	queue<metadata> q;
	for(i=1;i<k;i++)
	{
		if(i==1)
		{
			if(a[i]>a[i-1])
			{
				metadata temp;
				temp.length=2;
				temp.type='a';
				q.push(temp);
			}
			else if(a[i]==a[i-1])
			{
				metadata temp;
				temp.length=2;
				temp.type='e';
				q.push(temp);
			}
			else
			{
				metadata temp;
				temp.length=2;
				temp.type='d';
				q.push(temp);
			}
		}
		else
		{
			
		}
	}
	return 0;
}
