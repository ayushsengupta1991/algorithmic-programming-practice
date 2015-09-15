#include<iostream>
#include<queue>
using namespace std;
struct node
{
	string s;
	long long int v;
};
int main()
{
	long long int n;
	cin>>n;
	queue<struct node> q;
	struct node x;
	x.s="1";
	x.v=1;
	if(x.v%n==0)
	{
		cout<<x.s<<"\n";
		return 0;
	}
	q.push(x);
	while(!q.empty())
	{
		struct node temp=q.front();
		q.pop();
		struct node x;
		struct node y;
		x.s=temp.s+'0';
		y.s=temp.s+'1';
		x.v=(temp.v*10)%n;
		y.v=((temp.v*10)%n+1)%n;
		if(x.v==0)
		{
			cout<<x.s<<"\n";
			return 0;
		}
		if(y.v==0)
		{
			cout<<y.s<<"\n";
			return 0;
		}
		q.push(x);
		q.push(y);
	}
	return 0;
}
