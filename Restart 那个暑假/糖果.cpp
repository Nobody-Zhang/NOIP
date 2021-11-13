#include<bits/stdc++.h>
using namespace std;
int a[6];
int main()
{
	for(int i=0;i<=4;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=4;i++)
	{
		a[i]=a[i]-a[i]%3;
		a[i]/=3;
		a[(i+5-1)%5]+=a[i];
		a[(i+1)%5]+=a[i];
	}
	for(int i=0;i<=4;i++)
	{
		printf("%5d",a[i]);
	}
	return 0;
}