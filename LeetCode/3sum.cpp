#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int> > threeSum(vector<int> &num) {
        
        sort(num.begin(),num.end());
        int i,j,k;
        for(i=0;i<num.size();i++){
            cout<<num[i]<<" ";
	}
        cout<<"\n";
        vector<vector<int> > sol;
        if(num.size()<3)
            return sol;
	i=0;
        while(i<num.size()-2){
            if(i>0 && num[i]==num[i-1]){
		cout<<"i:="<<i<<"\n";
                i++;
                continue;
            }
            j=i+1;
            k=num.size()-1;
            while(j<k)
            {
                   cout<<i<<" "<<j<<" "<<k<<"\n";
                   if(num[i]+num[j]+num[k]==0)
                    {
                        vector<int> temp;
                        temp.push_back(num[i]);
                        temp.push_back(num[j]);
                        temp.push_back(num[k]);
                        sol.push_back(temp);
                        while(num[i]+num[j]+num[k]==0)
                            j++;
                    }
                    else if(num[i]+num[j]+num[k]>0)
                        k--;
                    else j++;
            }
	   i++;
        
	}
        return sol;
        
}
int main()
{
   cout << "Hello World" << endl; 
   vector<int> inp;
   int n;
   cin>>n;
   while(n--)
   {
       int x;
       cin>>x;
       inp.push_back(x);
   }
   vector<vector<int> > s=threeSum(inp);
   int i,j;
   for(i=0;i<s.size();i++)
    {
        for(j=0;j<s[i].size();j++)
            cout<<s[i][j]<<" ";
        cout<<"\n";
    }
   return 0;
}


