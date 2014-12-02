#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int two=0,one=0;
	while(n--)
	{
		int r;
		cin>>r;
		if(r==200) two++;
		else one++;
	}
	if((2*two+one)%2==1)
	{
		cout<<"NO\n";
	}
	else
	{
		int x=(2*two+one)/2;
		if(x%2==0)
			cout<<"YES\n";
		else
		{
			if(one>0)
				cout<<"YES\n";
			else cout<<"NO\n";
		}
	}	
	return 0;
}