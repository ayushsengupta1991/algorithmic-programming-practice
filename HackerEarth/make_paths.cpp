#include<iostream>
#include<vector>
#include<cstdio>
#define limit 100000
#define LL long long int
using namespace std;
long *parent=new parent [limit];
struct point
{
	long x;
	long y;
	point()
	{
		x=0;
		y=0;
	}
};
struct edge
{
	long u;
	long v;
	long cost;
	edge()
	{
		u=-1;
		v=-1;
		cost=0;
	}
};
bool x_cmp(point 
int main()
{
	long n;
	scanf("%ld",&n);
	long i;
	for(i=0;i<n;i++)
		parent[i]=i;
	
	vector<point> p;
	for(i=0;i<n;i++)
	{
		point r;
		scanf("%ld %ld\n",&r.x,&r.y);
	}
	return 0;
}