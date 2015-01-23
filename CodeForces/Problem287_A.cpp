#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
struct point
{
	int index;
	int val;
};
bool myfunc(struct point i,struct point j)
{
	return (i.val<j.val);
}
int main()
{
	int n,i;
	long k;
	vector<int> sol_index;
	cin>>n>>k;
	struct point *a=new struct point [n];
	for(i=0;i<n;i++){
		cin>>a[i].val;
		a[i].index=i+1;
	}
	sort(a,a+n,myfunc);
	long rem=k;
	for(i=0;i<n;i++)
	{
		if(rem>=a[i].val)
		{
			rem-=a[i].val;
			sol_index.push_back(a[i].index);
		}
		else break;
	}
	cout<<sol_index.size()<<"\n";
	for(i=0;i<sol_index.size();i++)
		cout<<sol_index[i]<<" ";
	return 0;
}
