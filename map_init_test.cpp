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
using namespace std;
struct test
{
	int x;
	bool y;
	test(){
	x=8;
	y=false;
	}
};

int main()
{
	map<int,struct test> mp;
	map<int,bool> s;
	cout<<s[10]<<"\n";
	cout<<mp[5].x<<" "<<mp[5].y<<"\n";
	return 0;
}
