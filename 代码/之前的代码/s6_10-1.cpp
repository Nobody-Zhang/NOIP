#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,r,j;
	cin>>n;
	int a[9999];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(j=0;j<n-1;j++)
		for(int q=0;q<n-j;q++)
			if(a[j+1]>a[j])
			{
				r=a[j+1];
				a[j+1]=a[j];
				a[j]=r;
			}
	for(j=0;j<n;j++)
	cout<<a[j]<<" ";
	return 0;
}
