#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct tp
{
	int t;
	double p;
};
bool mycomparator(struct tp i,struct tp j)
{
	return (i.t+j.t*i.p)<(j.t+i.t*j.p);
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	int n,i,j;
	cin>>n;
	cout<<setprecision(12);
	struct tp *store=(struct tp*)calloc(n,sizeof(tp));
	for(i=0;i<n;i++)
		cin>>store[i].t>>store[i].p;
	sort(store,store+n,mycomparator);
	double expected=0,product;
	for(i=0;i<n;i++)
	{
		product=1;
		for(j=i-1;j>=0;j--)
			product*=store[j].p;
		expected+=store[i].t*product;
		//cout<<store[i].t<<" "<<store[i].p<<"\n";
	}
	cout<<expected<<"\n";
	return 0;
}
