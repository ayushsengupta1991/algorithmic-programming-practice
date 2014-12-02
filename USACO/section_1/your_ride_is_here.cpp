/*
ID: ayush.s3
LANG: C++
PROG: ride
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	char a[10],b[10];
	fin>>a>>b;
	int x=1,y=1,i=0;
	for(;a[i]!='\0';i++)
		x=(x*(int(a[i])-64))%47;
	
	for(i=0;b[i]!='\0';i++)
		y=(y*(int(b[i])-64))%47;
	
	if(x==y)
		fout<<"GO\n";
	else fout<<"STAY\n";
	return 0;
}