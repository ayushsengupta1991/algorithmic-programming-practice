#include<iostream>
using namespace std;
int main()
{
	while(true)
	{
		char s[6];
		cin.getline(s,6);
		if(s[0]=='Z' && s[1]=='\0')
			break;
		char puzzle[5][5];
		for(int i=0;i<5;i++)
			puzzle[0][i]=s[i];
		for(int j=0;j<4;j++)
		{
			cin.getline(s,6);
			for(int i=0;i<5;i++)
				puzzle[1+j][i]=s[i];
		}
		char inp[256];
		cin.getline(inp,256);
		int start_i,start_j;
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				if(puzzle[i][j]==' ')
				{
					start_i=i;
					start_j=j;
				}
		int it=-1;
		bool valid=true;
		while(inp[++it]!='0')
		{
			if(inp[it]=='A')
			{
				if(start_i-1>=0){
				char temp=puzzle[start_i][start_j];
				puzzle[start_i][start_j]=puzzle[start_i-1][start_j];
				puzzle[start_i-1][start_j]=temp;
				}
				else 
					{
						valid=false;
						break;
					}
					

			}
			if(inp[it]=='B' && start_i+1<5)
			{
				char temp=puzzle[start_i][start_j];
				puzzle[start_i][start_j]=puzzle[start_i+1][start_j];
				puzzle[start_i+1][start_j]=temp;
				
			}
			else 
			{
				valid=false;
				break;
			}
			if(inp[it]=='L' && start_j-1>=0)
			{
				char temp=puzzle[start_i][start_j-1];
				puzzle[start_i][start_j]=puzzle[start_i][start_j-1];
				puzzle[start_i][start_j-1]=temp;
				
			}
			else 
			{
				valid=false;
				break;
			}
			if(inp[it]=='R' && start_j+1<5)
			{
				char temp=puzzle[start_i][start_j];
				puzzle[start_i][start_j]=puzzle[start_i][start_j+1];
				puzzle[start_i][start_j+1]=temp;
				
			}
			else 
			{
				valid=false;
				break;
			}
			
		}
		if(valid)
		{
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<5;j++)
					cout<<puzzle[i][j]<<" ";
				cout<<"\n";
			}
		}
		else
		{
			cout<<"This puzzle has no final configuration\n";
		}
	}
}