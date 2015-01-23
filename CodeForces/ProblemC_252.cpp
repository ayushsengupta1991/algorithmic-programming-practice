#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct element
{
	int number;
	int degree;
	int s;
};
struct edges
{
	int a;
	int b;
};
int myComp(struct element i,struct element j)
{
	return (i.degree < j.degree);
}
int main()
{
	int n;
	cin>>n;
	int i,j;
	struct element *list=new element [n];
	int *ind=new int [n];
	for(i=0;i<n;i++){
		cin>>list[i].degree>>list[i].s;
		list[i].number=i;
	}
	sort(list,list+n,myComp);
	for(i=0;i<n;i++){
		//cout<<list[i].number<<" "<<list[i].degree<<" "<<list[i].s<<"\n";
		ind[list[i].number]=i;
	}
	i=0;
	vector<struct edges> sol;
	while(list[i].degree==0)
	{
		i++;
		if(i==n)
			break;
	}
	while(i<n)
	{
		while(list[i].degree<=1)
		{
			
			if(list[i].degree==1)
			{
				struct edges t;
				t.a=list[i].number;
				t.b=list[i].s;
				sol.push_back(t);
				list[i].degree=0;
				list[ind[list[i].s]].degree--;
				list[ind[list[i].s]].s ^=list[i].number;
			}
			i++;
			if(i==n)
				break;
		}
		if(i==n)break;
		//sort(list+i,list+n,myComp);
		for(j=i;j<n;j++)
			ind[list[j].number]=j;
		
	}
	cout<<sol.size()<<"\n";
	for(i=0;i<sol.size();i++)
		cout<<sol[i].a<<" "<<sol[i].b<<"\n";
	return 0;
}
	