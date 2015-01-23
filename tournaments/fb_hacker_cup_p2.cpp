#include<iostream>
using namespace std;
bool subsetSum(int i,int *p,int *c,int *f,int gp,int gc,int gf,int n)
{
	if(i==n)
	{
		if(gp==0 && gc==0 && gf==0)
			return true;
		return false;
	}
	bool sol=false;
	sol=sol || subsetSum(i+1,p,c,f,gp-p[i],gc-c[i],gf-f[i],n) || subsetSum(i+1,p,c,f,gp,gc,gf,n);
	return sol;
}
int main()
{
	int t,it=1;
	cin>>t;
	while(t--)
	{
		int gp,gc,gf,n;
		int *p=new int [n];
		int *c=new int [n];
		int *f=new int [n];
		cin>>gp>>gc>>gf;
		cin>>n;
		int i;
		for(i=0;i<n;i++)
			cin>>p[i]>>c[i]>>f[i];
		bool sol=subsetSum(0,p,c,f,gp,gc,gf,n);
		cout<<"Case #"<<it<<": ";
		it++;
		if(sol)
			cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}