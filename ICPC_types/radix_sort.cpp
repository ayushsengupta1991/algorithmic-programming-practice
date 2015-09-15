#include<iostream>
#include<vector>
using namespace std;
void radix_sort(int *arr,int n)
{
	int max=arr[0];
	for(int i=0;i<n;++i)
		if(arr[i]>max)
			max = arr[i];
	
	int mod=1;
	while(max>0)
	{
		vector<int> bucket[10];
		for(int i=0;i<n;++i)
		{
			bucket[(arr[i]/mod)%10].push_back(arr[i]);
		}
		int k=0;
		for(int i=0;i<10;++i)
		{
			for(int j=0;j<bucket[i].size();++j)
				arr[k++]=bucket[i][j];
		}
		mod=mod*10;
		max=max/10;
	}

}
void print_array(int *arr,int n)
{
	for(int i=0;i<n;++i)
		cout<<arr[i]<<"\n";
}
int main()
{
	int n,i;
	cin>>n;
	int *arr = new int [n];
	for(i=0;i<n;++i)
		cin>>arr[i];
	radix_sort(arr,n);
	print_array(arr,n);
	return 0;
}
