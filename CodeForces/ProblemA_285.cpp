#include<iostream>
using namespace std;
long max(long a,long b)
{
	if(a>b)
		return a;
	else return b;
}
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(max((3*a)/10,a-(a/250)*c)>max((3*b)/10,b-(b/250)*d))
		cout<<"Misha\n";
	else if (max((3*a)/10,a-(a/250)*c)==max((3*b)/10,b-(b/250)*d))
		cout<<"Tie\n";
	else
		cout<<"Vasya\n";
	return 0;
}
