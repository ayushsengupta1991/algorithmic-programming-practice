#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define N 999999
using namespace std;
int main()
{
	long datCenter,i,j;
	cin>>datCenter;
	if(datCenter==0 || dataCenter==1)
	{
		cout<<"done\n";
		return 0;
	}
	long *dataSetFind=new long [N+1];
	for(i=0;i<N;i++)
		dataSetFind[i]=0;
	
	vector<vector<long> > v;
	for(i=1;i<=datCenter;i++)
	{
		int l;
		cin>>l;
		vector<long> temp;
		for(j=0;j<l;j++)
		{
			long did;
			cin>>did;
			temp.push_back(did);
			if(dataSetFind[did]==0)
				dataSetFind[did]=i;
		}
		v.push_back(temp);
	}
	vector<long> validId;
	for(i=1;i<N;i++)
		if(dataSetFind[i]!=0)
			validId.push_back(i);
	
	for(i=0;i<v.size();i++)
	{
		for(j=0;j<v[i].size();j++)
		{
			dataSetFind[v[i][j]]=(i+1);
		}
		for(j=0;j<validId.size();j++)
		{
			if(dataSetFind[validId[j]]!=0 && dataSetFind[validId[j]]!=(i+1))
				cout<<validId[j]<<" "<<dataSetFind[validId[j]]<<" "<<(i+1)<<"\n";
		}
	}
	cout<<"done\n";
	return 0;
}