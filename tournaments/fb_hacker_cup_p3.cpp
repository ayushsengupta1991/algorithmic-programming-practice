// character to number conversion
// 0 ->left
// 1 ->up
// 2 ->right
// 3 ->down
// 4 ->#
// 5 ->.
// 6 ->S
// 7 ->G
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
struct point
{
	int i;//row
	int j;//column
	long long int g;// actual cost incurred to reach point p ....cost function g(n) 
	int h;// heuristic function h(n)
	
};
class comparePoint{
public:
	bool operator()(point& p1, point& p2)
	{
		if((p1.g+p1.h)<=(p2.g+p2.h))
			return false;
		return true;
	}
};
int charToInt(char ch)
{
	switch(ch)
	{
		case '<':return 0;
		case '^':return 1;
		case '>':return 2;
		case 'v':return 3;
		case '#':return 4;
		case '.':return 5;
		case 'S':return 6;
		case 'G':return 7;
	}
}
bool valid(short state[105][105],int m,int n,int i,int j,long long int moves)
{
	if(i<0 || i>m-1)
		return false;
	if(j<0 || j>n-1)
		return false;
	if(state[i][j]>=0 && state[i][j]<=4)
		return false;
	int r;
	for(r=i;r<m;r++)
	{
		if(state[r][j]==4)
			break;
		if(state[r][j]>=0 && state[r][j]<=3)
		{
			long long int check=(state[r][j]+moves)%4;
			//cout<<"Check:="<<check<<"\n";
			if(check==1)
				return false;
			break;
		}
	}
	for(r=i;r>=0;r--)
	{
		if(state[r][j]==4)
			break;
		if(state[r][j]>=0 && state[r][j]<=3)
		{
			long long int check=(state[r][j]+moves)%4;
			//cout<<"Check:="<<check<<"\n";
			if(check==3)
				return false;
			break;
		}
	}
	for(r=j;r<n;r++)
	{
		if(state[i][r]==4)
			break;
		if(state[i][r]>=0 && state[i][r]<=3)
		{
			long long int check=(state[i][r]+moves)%4;
			//cout<<"Check:="<<check<<"\n";
			if(check==0)
				return false;
			break;
		}
	}
	for(r=j;r>=0;r--)
	{
		if(state[i][r]==4)
			break;
		if(state[i][r]>=0 && state[i][r]<=3)
		{
			long long int check=(state[i][r]+moves)%4;
			//cout<<"Check:="<<check<<"\n";
			if(check==2)
				return false;
			break;
		}
	}
	
	return true;
}
int main()
{
	int t,it=1;
	cin>>t;
	while(t--)
	{
		int m,n,i,j;
		point start,end;
		cin>>m>>n;
		short state[105][105];
		long long int visit[105][105];
		long long int minMoves=-1;
		for(i=0;i<m;i++)
		{
			char *x=new char [n+2];
			cin>>x;
			for(j=0;j<n;j++)
			{
				state[i][j]=charToInt(x[j]);
				if(state[i][j]==6)
				{
					start.i=i;
					start.j=j;
					start.g=0;
				}
				if(state[i][j]==7)
				{
					end.i=i;
					end.j=j;
					end.g=-1;
					end.h=0;
				}
			}
			start.h=abs(start.i-end.i)+abs(start.j-end.j);
			
		}
		
		priority_queue<point, vector<point>, comparePoint> pq;
		pq.push(start);
		//while(true);
		//int counter=0;
		while(!pq.empty())
		{
			point temp=pq.top();
			pq.pop();
			//cout<<"Best Current State:"<<temp.i<<" "<<temp.j<<" "<<temp.g<<" "<<temp.h<<"\n";
			//cout<<pq.size()<<"\n";
			//if(pq.size()>10000000)
			//	break;
			//counter++;
			if(state[temp.i][temp.j]==7)
			{
				minMoves=temp.g+temp.h;
				break;
			}
			if(valid(state,m,n,temp.i+1,temp.j,temp.g+1))
			{
				point x;
				x.i=temp.i+1;
				x.j=temp.j;
				x.g=temp.g+1;
				x.h=abs(x.i-end.i)+abs(x.j-end.j);
				pq.push(x);
				//cout<<"Valid state:="<<temp.i+1<<" "<<temp.j<<" "<<temp.g+1<<"\n";
			}
			//else cout<<"Invalid state:="<<temp.i+1<<" "<<temp.j<<" "<<temp.g+1<<"\n";
			if(valid(state,m,n,temp.i-1,temp.j,temp.g+1))
			{
				point x;
				x.i=temp.i-1;
				x.j=temp.j;
				x.g=temp.g+1;
				x.h=abs(x.i-end.i)+abs(x.j-end.j);
				pq.push(x);
				//cout<<"Valid state:="<<temp.i-1<<" "<<temp.j<<" "<<temp.g+1<<"\n";
			}
			//else cout<<"Invalid state:="<<temp.i-1<<" "<<temp.j<<" "<<temp.g+1<<"\n";
			if(valid(state,m,n,temp.i,temp.j+1,temp.g+1))
			{
				point x;
				x.i=temp.i;
				x.j=temp.j+1;
				x.g=temp.g+1;
				x.h=abs(x.i-end.i)+abs(x.j-end.j);
				pq.push(x);
				//cout<<"Valid state:="<<temp.i<<" "<<temp.j+1<<" "<<temp.g+1<<"\n";
			}
			//else cout<<"Invalid state:="<<temp.i<<" "<<temp.j+1<<" "<<temp.g+1<<"\n";
			if(valid(state,m,n,temp.i,temp.j-1,temp.g+1))
			{
				point x;
				x.i=temp.i;
				x.j=temp.j-1;
				x.g=temp.g+1;
				x.h=abs(x.i-end.i)+abs(x.j-end.j);
				pq.push(x);
				//cout<<"Valid state:="<<temp.i<<" "<<temp.j-1<<" "<<temp.g+1<<"\n";
			}
			//else cout<<"Invalid state:="<<temp.i<<" "<<temp.j-1<<" "<<temp.g+1<<"\n";
		}
		if(minMoves>=0)
		{
			cout<<"Case #"<<it<<": "<<minMoves<<"\n";
		}
		else 
		{
			cout<<"Case #"<<it<<": impossible"<<"\n";
		}
		it++;
		
	}
	return 0;
	
}
