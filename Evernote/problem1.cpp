#include<iostream>
#include<string>
using namespace std;
void pop(int* begPointer,int* endPointer,int N)
{
	if(*begPointer==*endPointer)
	{
		*begPointer=-1;
		*endPointer=-1;
		return;
	}
	*begPointer=(*begPointer+1)%N;
	return;
}
void push(string buffer[],int* begPointer,int* endPointer,int N,string str)
{
	if(*begPointer==-1)
	{
		*begPointer=0;
		*endPointer=0;
		buffer[*endPointer]=str;
		return;
	}
	if(*begPointer==(*endPointer+1)%N)
	{
		*begPointer=(*begPointer+1)%N;
		*endPointer=(*endPointer+1)%N;
		buffer[*endPointer]=str;
		return;
	}
	*endPointer=(*endPointer+1)%N;
	buffer[*endPointer]=str;
	return;
}
int main()
{
	int N;
	cin>>N;
	string *buffer=new string [N];
	int beg=-1,end=-1,n;
	bool q=false;
	while(true)
	{
		char ch;
		cin>>ch;
		switch(ch)
		{
			case 'A': cin>>n;
				  for(int i=0;i<n;i++)
				  {
					  string str;
					  cin>>str;
					  push(buffer,&beg,&end,N,str);
				  }
				  //cout<<"Beg:="<<beg<<" End:="<<end<<"\n";
				  break;
			case 'R': cin>>n;
				  for(int i=0;i<n;i++)
					pop(&beg,&end,N);
				  //cout<<"Beg:="<<beg<<" End:="<<end<<"\n";
				  break;
			case 'L': for(int i=beg;i!=end;i=(i+1)%N)
					cout<<buffer[i]<<"\n";
				  cout<<buffer[end]<<"\n";
				  break;
			case 'Q': q=true;
				  break;
		}
		if(q)break;
	}
	return 0;
}
