#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#define LL long long int
using namespace std;
int main()
{
	char str[210];
	cin>>str;
	int k,n=strlen(str),l,x,y,xi;
	cin>>k;
	bool repeat;
	if((n+k)%2==0)
		l=n+k;
	else l=n+k-1;
	for(;l>0;l=l-2)
	{
		repeat=false;
		//if you find a valid tandem repeat, just break
		xi=0;
		while(true)
		{
			if(xi+l>n+k)
				break;
			x=xi;
			y=x+l/2;
			while(true)
			{
				if(y>=xi+l || y>=n)
				{
					repeat=true;
					break;
				}
				else if(str[x]!=str[y])
				{
					repeat=false;
					//cout<<"done3";
					break;
					
				}
				else{
					//cout<<"done4";
					x++;y++;}
				
			}
			//cout<<l<<"::"<<xi<<" "<<x<<" "<<y<<" "<<repeat<<"\n";
			if(repeat)
				break;
			xi++;
			
		}
		if(repeat)
			break;
	}
	cout<<l<<"\n";
	return 0;
}