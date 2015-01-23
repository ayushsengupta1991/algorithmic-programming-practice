#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
LL minimum(LL a,LL b)
{
	if(a>b)
		return b;
	return a;
}
struct exam
{
	LL a;
	LL b;
};
bool myfunc(struct exam i,struct exam j)
{
	return (i.b<j.b);
}
int main()
{
	LL n,r,avg;
	cin>>n>>r>>avg;
	struct exam *inp=new struct exam [n];
	LL i,sum=0,tot,sol=0;
	for(i=0;i<n;i++)
	{
		cin>>inp[i].a>>inp[i].b;
		sum+=inp[i].a;
	}
	//cout<<"done"<<"\n";
	tot=avg*n;
	LL rem=(tot-sum);
	if(rem<=0)
	{	cout<<0<<"\n";
		return 0;
	}
	i=0;
	//cout<<rem<<"\n";
	sort(inp,inp+n,myfunc);
	//for(i=0;i<n;i++)
	//	cout<<inp[i].a<<" "<<inp[i].b<<"\n";
	//cout<<"X:=\n";
	i=0;
	while(true)
	{
		if(rem<=0)
			break;
		if(inp[i].a==r)
		{
			i++;
			continue;
		}
		LL x=minimum(rem,r-inp[i].a);
		rem=rem-x;
		inp[i].a=inp[i].a+x;
		sol=sol+(x*inp[i].b);
		//cout<<"x:="<<x<<"i:="<<i<<"\n";
		i++;
		if(rem<=0)
			break;
	}
	//cout<<"doneX\n";
	cout<<sol<<"\n";
	return 0;
}
