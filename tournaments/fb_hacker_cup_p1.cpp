#include<iostream>
#include<cstring>
using namespace std;
void swapCharacters(char a[],int i,int j)
{
	char s=a[i];
	a[i]=a[j];
	a[j]=s;
	
}
int main()
{
	int t;
	cin>>t;
	for(int it=1;it<=t;it++)
	{
		char inp[15];
		cin>>inp;
		cout<<"Case #"<<it<<": ";
		int i,index1=0,largest=inp[0]-'0';
		for(i=0;i<strlen(inp);i++)
		{
			if((inp[i]-'0')>=largest)
			{
				largest=inp[i]-'0';
				index1=i;
			}
		}
		int index2=0,smallest=inp[0]-'0';
		for(i=0;i<strlen(inp);i++)
		{
			if((inp[i]-'0')<=smallest && (inp[i]-'0')>0)
			{
				smallest=inp[i]-'0';
				index2=i;
			}
			
		}
		swapCharacters(inp,0,index2);
		cout<<inp<<" ";
		swapCharacters(inp,0,index2);
		swapCharacters(inp,0,index1);
		cout<<inp<<" ";
		swapCharacters(inp,0,index1);
		cout<<"\n";
	}
}