#include<iostream>
using namespace std;
int main()
{
	int n,i,m;
	cin>>n;
	int *p=new int [n+1];
	int *q=new int [n+1];
	for(i=1;i<=n;i++)
	{
		cin>>p[i];
		q[i]=p[i];
	}
	cin>>m;
	// count the minimum number of sorts required!
	int minP=0;
	vector<int> ansI;
	vector<int> ansJ;
	for(i=1;i<n;i++)
	{
		if(p[i]==i)	continue;
		else
		{
			for(j=i+1;j<=n;j++)
			{
				if(p[j]==i)
				{
					int swap=p[i];
					p[i]=p[j];
					p[j]=swap;
					minP++;
					break;
				}
			}
		}
	}
	if(minP>=m)
	{
		int t=minP-m;
		cout<<t<<"\n";
		for(i=1;i<n;i++)
		{
			if(t==0)
				break;
			if(q[i]==i) continue;
			else
			{
				for(j=i+1;j<=n;j++)
				{
					if(q[j]==i)
					{
						int swap=q[i];
						q[i]=q[j];
						q[j]=swap;
						//minP++;
						ansI.push_back(i);
						ansJ.push_back(j);
						t--;
						break;
					}
				}
			}
		}
	}
	else
	{
		int t=m-minP;
	}
	return 0;
}