#include <iostream>
#include <cstring>
#define MAX 10000
using namespace std;
int main() 
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	char str1[MAX+2],str2[MAX+2];
	cin.getline(str1,MAX);
	cin.getline(str2,MAX);
	int *count=new int [256];
	int i;
	for(i=0;i<256;i++)
		count[i]=0;
	for(i=0;i<strlen(str1);i++)
		if(str1[i]!=' ' || str1[i]!='\n' || str1[i]!='\0')
			count[int(str1[i])]++;

	for(i=0;i<strlen(str2);i++)
		if(str2[i]!=' ' || str2[i]!='\n' || str2[i]!='\0')
			count[int(str2[i])]--;
	
	for(i=0;i<256;i++)
		if(count[i]!=0)
		{
			cout<<"Not anagrams!\n";
			return 0;
		}
	cout<<"Anagrams!\n";
	return 0;
}