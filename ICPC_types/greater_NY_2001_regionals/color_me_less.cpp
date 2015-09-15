#include<iostream>
#include<climits>
#include<cmath>
#include<vector>
using namespace std;
struct point
{
	int x;
	int y;
	int z;
};
int main()
{
	int i=1;
	vector<point> inp;
	while(true)
	{
		point p;
		cin>>p.x>>p.y>>p.z;
		if(i++<=16)
		{
			inp.push_back(p);
		}
		else if (p.x==-1 && p.y==-1 && p.z==-1)
		{
			break;
		}
		else
		{
			long long min = LLONG_MAX;
			int pos=-1;
			for(int i=0;i<16;++i)
			{
				if(((p.x-inp[i].x)*(p.x-inp[i].x) + (p.y-inp[i].y)*(p.y-inp[i].y) + (p.z-inp[i].z)*(p.z-inp[i].z))< min){
					min = (p.x-inp[i].x)*(p.x-inp[i].x) + (p.y-inp[i].y)*(p.y-inp[i].y) + (p.z-inp[i].z)*(p.z-inp[i].z);
					pos = i;
				}
			}
			cout<<"("<<p.x<<","<<p.y<<","<<p.z<<")"<<" maps to ("<<inp[pos].x<<","<<inp[pos].y<<","<<inp[pos].z<<")\n";
		}
	}
	return 0;
}