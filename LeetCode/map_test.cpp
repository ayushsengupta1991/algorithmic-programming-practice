#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct node
{
	int x;
	int y;
	node(){
		x=0;
		y=0;
	}
	node(int a,int b){
	
		x=a;
		y=b;
	}
	
};
int main()
{
	map<int,struct node> mp;
	
	cout<<mp[1].x<<" "<<mp[1].y<<"\n";
	//if(mp[1])
	//	cout<<"Passed\n";
	//else cout<<"Failed\n";
	return 0;
}