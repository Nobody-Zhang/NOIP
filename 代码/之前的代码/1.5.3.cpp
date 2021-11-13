#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a[105],all=0,as;
	int i;
	cin>>i;
	for(int u=1;u<=i;u++)
	{
		cin>>a[u];
		all+=a[u];
	}
	as=1.0*all/i;
	printf("%.4lf",as);
	return 0;
}
