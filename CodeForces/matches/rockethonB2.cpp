#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cstring>
typedef long long int LL;
using namespace std;
int fact(int n)
    {
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        else return (n*fact(n-1));
    }
string getPermutation(LL n, LL k) {
        
        bool mark[n];
        LL i,j;
        for(i=0;i<n;i++)
            mark[i]=false;
        string str="";
        k--;
        for(i=0;i<n;i++)
        {
            LL x=(k/fact(n-i-1));
            LL r=x;
            for(j=0;j<n;j++)
            {
                if(!mark[j] && x==0)
                {
                    mark[j]=true;
                    str.push_back((j+1)+'0');
                    break;
                }
                else if(!mark[j] && x>0)
                    x--;
            }
            k=k-(r*fact(n-i-1));
        }
    
        return str;    
    }

int main()
{
	LL n,k,i;
	cin>>n>>k;
	string ans=getPermutation(n,k);
	for(i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}
