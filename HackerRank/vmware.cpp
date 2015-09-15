#include <map>
#include <set>
#include <list>
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
using namespace std;


/*
 * Complete the function below.
 */
double string_to_decimal(string s)
{
    double x=0.0;
    int i=0;
    while(s[i]!='.' && i<s.size())
    {
        x=x*10 + (s[i++]-'0');
    }    
    if(s[i]=='.')
        i++;
    double exp = (1/10);
    while(i<s.size())
      {
         x = x + (s[i++]-'0')*exp;
         exp = exp/10;
      }
    return x;
}       

bool isClean(string s)
{
     if(s.size()==0)
	     return false;
     if(s[0]=='-')
         return false;
     else
     {
         for(int i=0;i<s.size();++i)
             if(s[i]>='1' && s[i]<='9')
                return true;
         return false;
     }
}

float Interpolate(int n, vector < int > amount, vector < string > ucost) {
    
    vector<int> clean_amount;
    vector<double> clean_ucost;
    cout<<"DOND";
    for(int i=0;i<(int)ucost.size();i++)
    {
        if(isClean(ucost[i]))
        {
            clean_amount.push_back(amount[i]);
            clean_ucost.push_back(string_to_decimal(ucost[i]));
        }
    }
    cout<<"DONE!";
    int pos=(int)clean_amount.size();
    for(int i=0;i<(int)clean_amount.size();i++)
    {
        if(clean_amount[i]==n)
        {
            return (roundf(clean_ucost[i]*100)/100);
        }
        else if (clean_amount[i]>n)
        {
            pos=i;
        }
    }
    
    if(pos==0)
    {
        double slope = (clean_ucost[1]-clean_ucost[0])/(clean_amount[1]-clean_amount[0]);
        double ans = clean_ucost[0] + slope*(n - clean_amount[0]);
        return roundf((ans*100)/100);
    }
    else if (pos == (int)clean_amount.size())
    {
        int end = (int)clean_amount.size();
        double slope = (clean_ucost[end-1]-clean_ucost[end-2])/(clean_amount[end-1]-clean_amount[end-2]);
        double ans = clean_ucost[end-2] + slope*(n - clean_amount[end-2]);
        return roundf((ans*100)/100);
    }
    else 
    {
        double slope = (clean_ucost[pos]-clean_ucost[pos-1])/(clean_amount[pos]-clean_amount[pos-1]);
        double ans = clean_ucost[pos-1] + slope*(n - clean_amount[pos-1]);
        return roundf((ans*100)/100);
    }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    float res;
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    
    int _amount_size;
    cin >> _amount_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _amount;
    int _amount_item;
    for(int _amount_i=0; _amount_i<_amount_size; _amount_i++) {
        cin >> _amount_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _amount.push_back(_amount_item);
    }
    
    
    int _ucost_size;
    cin >> _ucost_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _ucost;
    string _ucost_item;
    for(int _ucost_i=0; _ucost_i<_ucost_size; _ucost_i++) {
        getline(cin, _ucost_item);
        _ucost.push_back(_ucost_item);
    }
    
    res = Interpolate(_n, _amount, _ucost);
    fout << res << endl;
    
    fout.close();
    return 0;
}


