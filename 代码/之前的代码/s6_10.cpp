#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,a[15],p;
	for(i=1;i<=10;i++)
		cin>>a[i];
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10-i;j++)
		if(a[j]>a[j+1])
		{
			p=a[j];
			a[j]=a[j+1];
			a[j+1]=p;
		}
	}
	
	for(i=1;i<=10;i++)
	cout<<a[i]<<" ";
	return 0;
	
}
