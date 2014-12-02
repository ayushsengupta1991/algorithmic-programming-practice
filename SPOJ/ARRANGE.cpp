//program code ARRANGE
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
#define LL long long int
using namespace std;

bool sort_function(LL i,LL j)
{
        if(((i==2) && (j==3)) || ((i==3) && (j==2)))
	    return (i<j);
        else if(i==1 || j==1)
	    return (i<j);
        else return (i>j);
}
int main()
{
        long n;
        int t;
        cin>>t;
        int tc,i;
        for(tc=1;tc<=t;tc++)
        {
	    scanf("%ld",&n);
	    LL *a=new LL [n];
	    for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	    vector<LL> sol (a,a+n);
	    sort(sol.begin(),sol.end(),sort_function);
	    for(vector<LL>::iterator it = sol.begin(); it!=sol.end();it++)
		cout<<*it<<" ";
	    cout<<"\n";
        }
        return 0;
}


