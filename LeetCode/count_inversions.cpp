#include<iostream>
#include<cstring>
using namespace std;
long countInversions(int *a,int *b,int l,int r,int n)
{
	if(l==r)
	{
		return 0;
	}
	int m=(l+r)/2;
	leftInv = countInversions(a,b,l,m,n);
	rightInv = countInversions(a,b,m+1,r,n);
	for(int i=l;i<=r;i++)
		b[i]=a[i];
	int currInv=0;
	int i=l,j=m+1,k=l;
	while(i<=m && j<=r)
	{
		if(b[i]<=b[j])
		{
			a[k++]=b[i++];
		}
		else
		{
			currInv+ = m-i+1;
			a[k++]=b[j++];
		}
	}
	while(i<=m)
	{
		a[k++]=b[i++];
	}
	while(j<=r)
	{
		a[k++]=b[j++];
	}
	return (leftInv+rightInv+currInv);
}

int main()
{
	int n;
	cin>>n;
	int *a=new int [n];
	int *b=new int [n];
	for(int i=0;i<n;++i)
		cin>>a[i];
	long inversions = mergeSort(a,b,0,n-1,n);
	cout<<"Inversions:="<<inversions<<"\n";
	return 0;
}