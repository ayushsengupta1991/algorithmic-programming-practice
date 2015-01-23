#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct xy
{
	long x;
	long y;
};
long absolute(long x,long y)
{
	if(x>y)
		return (x-y);
	else return (y-x);
}
long binary_search(long *radius,long beg,long end,long long int val)
{
	long mid;
	while(beg<=end)
	{
		mid=(beg+end)/2;	
		if(mid==end && pow(radius[mid],2)<val)
			return end;
		else if(pow(radius[mid],2)<val && pow(radius[mid+1],2)>val)
			return mid;
		else if(pow(radius[mid],2)<val)
			beg=mid+1;
		else
			end=mid-1;
	}
	return -1;
}
int main()
{
	long n,i,m;
	long sc,ec;
	cin>>n;
	long *radius=(long *)calloc(n,sizeof(long));
	for(i=0;i<n;i++)
		cin>>radius[i];
	sort(radius,radius+n);
	//for(i=0;i<n;i++)
	//	cout<<radius[i]<<" ";
	//cout<<"\n";
	cin>>m;
	struct xy *start=(struct xy*)calloc(m,sizeof(struct xy));
	struct xy *end=(struct xy*)calloc(m,sizeof(struct xy));
	long long int pairs=0;
	for(i=0;i<m;i++)
	{
		cin>>start[i].x>>start[i].y>>end[i].x>>end[i].y;
		if(pow(start[i].x,2)+pow(start[i].y,2)<(radius[0]*radius[0]))
			sc=-1;
		else
			sc=binary_search(radius,0,n-1,pow(start[i].x,2)+pow(start[i].y,2));
		if(pow(end[i].x,2)+pow(end[i].y,2)<(radius[0]*radius[0]))
			ec=-1;
		else 
			ec=binary_search(radius,0,n-1,pow(end[i].x,2)+pow(end[i].y,2));
		//cout<<sc<<" "<<ec<<"\n";
		pairs+=absolute(ec,sc);
	}
	cout<<pairs<<"\n";
	return 0;
}
