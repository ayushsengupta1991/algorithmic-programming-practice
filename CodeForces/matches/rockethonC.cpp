#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cstring>
typedef long long int LL;
using namespace std;
long double maximum(long double a,long double b)
{
	if(a>b)
		return a;
	else return b;
}
long double minimum(long double a,long double b)
{
	if(a<b)
		return a;
	else return b;
}
long double adjust(long double a)
{
	if(a<=0)
		return 0;
	else return a;
}
int main()
{
	long double i;
	int n;
	int it,jt,kt;
	cin>>n;
	long double *l=new long double [n];
	long double *r=new long double [n];
	long double max,min;
	for(it=0;it<n;it++)
		cin>>l[it]>>r[it];
	
	for(it=0;it<n;it++){	
		if(it==0)
		{
			max=r[it];
			min=l[it];
		}
		else
		{
			max=maximum(max,r[it]);
			min=minimum(min,l[it]);
		}
		cout<<l[it]<<" "<<r[it]<<"\n";
	}
	long double total=0.0;
	long double exp=0.0;
	//cout<<"min:="<<min<<"max:="<<max<<"\n";
	for(i=min;i<=max;i++)
	{
		for(it=0;it<n;it++)
		{
			for(jt=0;jt<n;jt++)
			{
				if(it!=jt)
				{
					total=i*10;
					for(kt=0;kt<n;kt++)
					{
						if(kt!=it && kt!=jt)
						{
							if(i>=l[kt] && i<=r[kt])
								total*=((adjust(i-l[kt]+1))/(r[kt]-l[kt]+1));
							else if(i<l[kt])
								total=total*0.0;
							else if (i>r[kt])
								total=total*1.0;
							cout<<total<<"\n";
						}
					}
					if(i>=l[jt] && i<=r[jt])
						total*=(1/r[jt]-l[jt]+1);
					else if(i<l[jt])
						total*=0.0;
					else if(i>r[jt])
						total*=0.0;
					
					if(i>=l[it] && i<=r[it])
						total*=(adjust(r[it]-i+1)/(r[it]-l[it]+1));
					else if(i<l[it])
						total*=1.0;
					else if(i>r[it])
						total*=0.0;
					//else total=total*0;
					cout<<total<<":"<<i<<"\n";
					exp+=total;
				}
				
				
			}
			
		}
	}
	cout<<exp<<"\n";
	return 0;
}