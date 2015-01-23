#include<iostream>
using namespace std;
struct point
{
	long long x;
	long long y;
};
int main()
{
	struct point p1,p2;
	cin>>p1.x>>p1.y;
	cin>>p2.x>>p2.y;
	long long sum=0;
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		long long a,b,c;
		cin>>a>>b>>c;
		long long s1,s2;
		s1=(a*p1.x+b*p1.y+c);
		s2=(a*p2.x+b*p2.y+c);
		if(s1<0 && s2>0)
			sum++;
		else if(s1>0 && s2<0)
			sum++;
	}
	cout<<sum<<"\n";
	return 0;
}