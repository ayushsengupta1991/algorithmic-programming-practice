#include<iostream>
using namespace std;
int main()
{
	int count=0;
	while(true)
	{
		cout<<"1.. Enter a name\n";
		cout<<"2.. Tell me how many start with 'A'\n";
		cout<<"3.. Exit\n";
		int ch;
		cin>>ch;
		//cout<<count<<"\n";
		if(ch==1)
		{
			char x[150];
			cin>>x;
			//cout<<x;
			if(x[0]=='a')
				count++;
		}
		if(ch==2)
		{
			cout<<"\n\n"<<count<<"\n\n\n\n";
			//for(int i=1;i<=50;i++)
			//	cout<<"\n";
		}
		if(ch==3)
			break;
		
	}
	return 0;
}