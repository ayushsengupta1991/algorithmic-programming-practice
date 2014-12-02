#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int r, c;
int pacman_r, pacman_c;
int food_r, food_c;
char grid[10000][10000];
void nextMove()
{
	//logic here
	int note[r][c][3]; // 0 is distance, 1 is row, 2 is column!
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			note[i][j][0]=-1;
			note[i][j][1]=-1;
			note[i][j][2]=-1;
		}
	
	vector< pair<int,int> > p; // first is same as 'r'... second is same as 'c'... 
	queue< pair<int,int> > q;
	p.push_back(make_pair(pacman_r,pacman_c));
	q.push(make_pair(pacman_r,pacman_c));
	note[pacman_r][pacman_c][0]=0;
	bool flag=false;
	while(!q.empty())
	{
		pair<int,int> curr=q.front();
		q.pop();
		//UP
		if(curr.first-1>=0)
		{
			if(grid[curr.first-1][curr.second]!='%' && note[curr.first-1][curr.second][0]==-1)
			{
				p.push_back(make_pair(curr.first-1,curr.second));
				if(food_r==curr.first-1 && food_c==curr.second)
				{
					flag=true;
				}
				q.push(make_pair(curr.first-1,curr.second));
				note[curr.first-1][curr.second][0]=note[curr.first][curr.second][0]+1;
				note[curr.first-1][curr.second][1]=curr.first;
				note[curr.first-1][curr.second][2]=curr.second;
			}
		}
		if(flag) break;
		//LEFT
		if(curr.second-1>=0)
		{
			if(grid[curr.first][curr.second-1]!='%' && note[curr.first][curr.second-1][0]==-1)
			{
				p.push_back(make_pair(curr.first,curr.second-1));
				if(food_r==curr.first && food_c==curr.second-1)
				{
					flag=true;
				}
				q.push(make_pair(curr.first,curr.second-1));
				note[curr.first][curr.second-1][0]=note[curr.first][curr.second][0]+1;
				note[curr.first][curr.second-1][1]=curr.first;
				note[curr.first][curr.second-1][2]=curr.second;
			}
		}
		if(flag) break;
		//RIGHT
		if(curr.second+1<c)
		{
			if(grid[curr.first][curr.second+1]!='%' && note[curr.first][curr.second+1][0]==-1)
			{
				p.push_back(make_pair(curr.first,curr.second+1));
				if(food_r==curr.first && food_c==curr.second+1)
				{
					flag=true;
				}
				q.push(make_pair(curr.first,curr.second+1));
				note[curr.first][curr.second+1][0]=note[curr.first][curr.second][0]+1;
				note[curr.first][curr.second+1][1]=curr.first;
				note[curr.first][curr.second+1][2]=curr.second;
			}
		}
		if(flag) break;
		//DOWN
		if(curr.first+1<r)
		{
			if(grid[curr.first+1][curr.second]!='%' && note[curr.first+1][curr.second][0]==-1)
			{
				p.push_back(make_pair(curr.first+1,curr.second));
				if(food_r==curr.first+1 && food_c==curr.second)
				{
					flag=true;
				}
				q.push(make_pair(curr.first+1,curr.second));
				note[curr.first+1][curr.second][0]=note[curr.first][curr.second][0]+1;
				note[curr.first+1][curr.second][1]=curr.first;
				note[curr.first+1][curr.second][2]=curr.second;
			}
		}
		if(flag) break;
	}
	printf("%d\n",p.size());
	for(int i=0;i<p.size();i++)
		printf("%d %d\n",p[i].first,p[i].second);
	
	vector< pair<int,int> > traceback;
	traceback.push_back(make_pair(food_r,food_c));
	pair<int,int> current=traceback[traceback.size()-1];
	while(note[current.first][current.second][1]!=-1 || note[current.first][current.second][2]!=-1)
	{
		traceback.push_back(make_pair(note[current.first][current.second][1],note[current.first][current.second][2]));
		current=traceback[traceback.size()-1];
	}
	printf("%d\n",traceback.size()-1);
	for(int i=traceback.size()-1;i>=0;i--)
		printf("%d %d\n",traceback[i].first,traceback[i].second);
}

int main() 
{
	
	scanf( "%d %d", &pacman_r, &pacman_c);
	scanf( "%d %d", &food_r, &food_c);
	scanf( "%d %d", &r, &c);
	
	for( int i=0; i<r; i++) {
		scanf("%s[^\\n]%*c", grid[i]);
	}
	nextMove();
	return 0;
}