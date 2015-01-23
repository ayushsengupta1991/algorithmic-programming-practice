#include<iostream>
using namespace std;
int findPivot(int a[],int n)
{
	if(a[0]<a[n-1])
		return 0;
	
	int beg=0,end=n-1,mid;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(a[mid]<a[mid-1] && a[mid]<a[mid+1])
			return mid;
		else if(a[mid]>a[end])
			beg=mid+1;
		else if(a[mid]<a[end])
			end=mid-1;
	}
}

int search(int A[], int n, int target) 
{
	int pivot=findPivot(A,n);
	cout<<pivot<<"\n";
	int begPs=0,endPs=n-1,midPs;
	int mid;
	while(begPs<=endPs)
	{
		midPs=(begPs+endPs)/2;
		mid=(pivot+midPs)%n;
		cout<<"midPs:"<<midPs<<"mid:"<<mid<<"\n";
		if(A[mid]==target)
			return mid;
		else if(A[mid]<target)
			begPs=midPs+1;
		else
			endPs=midPs-1;
	}
	return -1;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int [n];
	int i,target;
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>target;
	int index=search(a,n,target);
	cout<<index<<"\n";
}
