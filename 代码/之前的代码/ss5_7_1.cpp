#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a0=0,a1=1,a2,n,i;
	double x=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		a2=a1+a0;
		x+=2.0-1.0*(n-1)/a2;
		a0=a1;
		a1=a2;
	}
	printf("%lf",x);
	return 0;
}
