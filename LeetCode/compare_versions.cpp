#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> sol;
    
void generateParanthesisCustomized(string &x, int i,int l,int r,int n)
    {
        if(i==n*2)
        {
            sol.push_back(x);
            return;
        }
        if(l==n)
        {
            x[i]=')';
            generateParanthesisCustomized(x,i+1,l,r+1,n);
	    return;
        }
        if(l==r)
        {
            x[i]='(';
            generateParanthesisCustomized(x,i+1,l+1,r,n);
	    return;
        }
        x[i]='(';
        generateParanthesisCustomized(x,i+1,l+1,r,n);
        x[i]=')';
        generateParanthesisCustomized(x,i+1,l,r+1,n);
        
    }
int main()
{
	int n;
	cin>>n;
	string x(n*2,'0');
	generateParanthesisCustomized(x,0,0,0,n);
	cout<<sol.size()<<"\n";
	for(int i=0;i<sol.size();i++)	cout<<sol[i]<<"\n";
	return 0;
}
