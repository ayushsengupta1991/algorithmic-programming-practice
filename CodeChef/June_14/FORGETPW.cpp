#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		char x,y;
		int map[127];
		int i,j=0,ri,rj,k,tempj;
		for(i=0;i<127;i++)
			map[i]=-1;
		for(i=1;i<=n;i++)
		{
			cin>>x>>y;
			map[int(x)]=int(y);
		}
		char s[1000010];
		cin>>s;
		for(i=0;i<strlen(s);i++)
		{
			if(map[int(s[i])]!=-1)
				s[i]=char(map[int(s[i])]);
			
		}
		//cout<<s<<"\n";
		//converted into decimal
		char sn[1000010];
		i=0;
		while(s[i]=='0')
			i++;
		while(s[i]!='.' || s[i]!='\0')
		{
			sn[j++]=s[i++];
		}
		if(s[i]=='\0')
		{	
			sn[j]=s[i];
			cout<<sn<<"\n";
		}
		//sn[j++]=s[i++];
		else
		{
			// location of dot for current i
			tempj=j;
			ri=strlen(s)-1;
			while(s[ri]=='0')
				ri--;
			for(k=ri,j=tempj+i-ri;k>=i;k--,j--)
				sn[j]=s[k];
			j=tempj+i-ri;
			if(sn[j]=='.')
				sn[j]='\0';
			else
				sn[j+1]='\0';
			cout<<sn<<"\n";
		
		}
	}
	return 0;
}