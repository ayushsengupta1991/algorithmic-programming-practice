#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
using namespace std;
bool special(char x)
{
	int r=(int)x;
	if(r>=65 && r<=90)
		return false;
	if(r>=97 && r<=122)
		return false;
	return true;
}
int main()
{
	while(true)
	{
		string line;
		getline(cin,line);
		if(line.size()==0)
			break;
		//cout<<line<<"\n";
		int n=line.size();
		int *dpo=new int [n];
		int *dpe=new int [n];
		int i;
		for(i=0;i<n;i++)
		{
			dpo[i]=-1;
			dpe[i]=-1;
		}
		// now we calculate the largest palindrome centred at point i for every odd i; 
		//cout<<"done0\n";
		for(i=0;i<n;i++)
		{
			if(special(line[i]))
				continue;
			int j,k;
			int size=1;
			j=i-1;
			k=i+1;
			while(j>=0 && k<n)
			{
				while(special(line[j]) && j>=0)
					j--;
				if(j<0) break;
				while(special(line[k]) && k<n)
					k++;
				if(k==n)break;
				if(tolower(line[j])==tolower(line[k]))
				{
					size=size+2;
					j--;
					k++;
				}
				else
					break;
			}
			dpo[i]=size;
		}
	    //  for(i=0;i<n;i++)
		//	cout<<dpo[i]<<" ";
	//	cout<<"\n";
		//now we calculate the largest palindrome centred at i,i+1 for every even i
		for(i=0;i<n;i++)
		{
			int size=0;
			if(special(line[i]))
				continue;
			int r=i+1;
			while(special(line[r]) && r<n)
				r++;
			if(r==n) continue;
			if(tolower(line[i])!=tolower(line[r]))
 				continue;
			// there is a potential even length palindrome starting at size!!
			size=size+2;
			int j=i-1;
			int k=r+1;
			while(j>=0 && k<n)
			{
				while(special(line[j]) && j>=0)
					j--;
				if(j<0) break;
				while(special(line[k])==' ' && k<n)
					k++;
				if(k==n)break;
				if(tolower(line[j])==tolower(line[k]))
				{
					size=size+2;
					j--;
					k++;
				}
				else break;
			}
			dpe[i]=size;
		}
	//	for(i=0;i<n;i++)
	//		cout<<dpe[i]<<" ";
	//	cout<<"\n";
		int maxsize=-1,mi=-1;
		for(i=0;i<n;i++)
		{
			if(dpe[i]>maxsize)
			{
				maxsize=dpe[i];
				mi=i;
			}
			if(dpo[i]>maxsize)
			{
				maxsize=dpo[i];
				mi=i;
			}
		}
		//cout<<"done3\n";
		//cout<<maxsize<<" "<<mi<<"\n";
		int sp,ep;
		sp=mi;
		if(maxsize%2==1)
		{
			ep=mi;
			maxsize--;
		}
		else
		{
			ep=mi+1;
			while(special(line[ep]))
				ep++;
			maxsize-=2;
		}
		while(maxsize>0)
		{
			sp--;
			while(special(line[sp]))
				sp--;
			maxsize--;
			ep++;
			while(special(line[ep]))
				ep++;
			maxsize--;
		//	cout<<sp<<" "<<ep<<"\n";
		}
		//cout<<"\n"<<sp<<" "<<ep<<"\n";
		for(i=sp;i<=ep;i++)
			cout<<line[i];
		cout<<"\n";
	}
	return 0;
}