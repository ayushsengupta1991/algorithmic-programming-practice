#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int *v=new int [2000];
	int i;
	for(i=0;i<2000;i++)
		v[i]=-1;
	vector<string> list;
	int q;
	cin>>q;
	while(q--)
	{
		string x,y;
		cin>>x;
		cin>>y;
		if(list.size()==0)
		{
			list.push_back(x);
			list.push_back(y);
			v[0]=1;
		}
		else
		{
			int index=-1;
			for(i=0;i<list.size();i++)
				if(x.compare(list[i])==0)
					index=i;
			if(index>=0)
			{
				list.push_back(y);
				v[index]=list.size()-1;
			}
			else
			{
				list.push_back(x);
				list.push_back(y);
				v[list.size()-2]=list.size()-1;
			}
		}
		
	}
	vector<string> ans;
	for(i=0;i<2000;i++)
	{
		if(v[i]!=-1)
		{
			int p,c;
			p=i;
			c=v[i];
			ans.push_back(list[i]);
			do
			{
				v[p]=-1;
				p=c;
				if(v[c]==-1)
				{
					ans.push_back(list[c]);
					break;
				}
				else{
					c=v[c];
				}
			}while(true);
			
		}
	}
	cout<<ans.size()/2<<"\n";
	for(i=0;i<ans.size()/2;i++)
		cout<<ans[2*i]<<" "<<ans[2*i+1]<<"\n";
	return 0;
}
