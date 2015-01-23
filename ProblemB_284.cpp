#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int m,n;
	cin>>n>>m;
	//string *wordl1=new string [m];
	//string *wordl2=new string [m];
	vector<string> wordl1;
	vector<string> wordl2;
	bool *which=new bool [m];
	int i=0,j;
	//cout<<"done\n";
	for(i=0;i<m;i++)
	{
		string x,y;
		cin>>x>>y;
		if(y.size()<x.size())
			which[i]=true;
		else which[i]=false;
		wordl1.push_back(x);
		wordl2.push_back(y);
		//i++;
	}
	//for(i=0;i<m;i++)
	//	cout<<wordl1[i]<<" "<<wordl2[i]<<"\n";
	for(i=1;i<=n;i++)
	{
		string x;
		cin>>x;
		for(j=0;j<m;j++)
		{
			if(x.compare(wordl1[j])==0)
			{
				if(which[j]){
					cout<<wordl2[j]<<" ";
					break;
				}
				else
				{
					cout<<wordl1[j]<<" ";
					break;
				}
			}
		}
	}
	cout<<"\n";
	return 0;
}