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
int main()
{
	int n,m;
	cin>>n>>m;
	if(n==1)
		cout<<1;
	else if(m<=n/2)
		cout<<(m+1);
	else cout<<(m-1);
	return 0;
}