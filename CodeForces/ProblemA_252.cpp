#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct option
{
	int v;
	int length;
};
char w(int i)
{
	if(i==1)
		return 'A';
	if(i==2) return 'B';
	if(i==3) return 'C';
	if(i==4) return 'D';
}
bool mf(option x,option y)
{
	return (x.length<y.length);
}
int main()
{
	char a[110],b[110],c[110],d[110];
	cin>>a>>b>>c>>d;
	option *l=new option [4];
	l[0].length=strlen(a)-2;l[1].length=strlen(b)-2;l[2].length=strlen(c)-2;l[3].length=strlen(d)-2;
	l[0].v=1;l[1].v=2;l[2].v=3;l[3].v=4;
	sort(l,l+4,mf);
	bool great[4];
	great[0]=false;great[1]=false;great[2]=false;great[3]=false;
	if(l[0].length*2<=l[1].length)
		great[l[0].v-1]=true;
//	if(l[1].length*2<=l[2].length && l[1].length>=l[0].length*2)
//		great[l[1].v-1]=true;
//	if(l[2].length*2<=l[3].length && l[2].length>=l[1].length*2)
//		great[l[2].v-1]=true;
	if(l[3].length>=l[2].length*2)
		great[l[3].v-1]=true;
	int count=0,i;
	for(i=0;i<4;i++)
		if(great[i]) count++;
	if(count==0 || count>=2)
		cout<<"C\n";
	else
	{
		for(i=0;i<4;i++)
			if(great[i])
			{
				cout<<w(i+1)<<"\n";
				break;
			}
	}
	return 0;
}