#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int o,all=0;
	double e;
	cin>>o;
	for(int i=1;i<=o;i++)
	{
		cin>>a[i];
		all+=a[i];
	}
	e=1.0*all/o;
	printf("%0.2lf",e);
	return 0;
} 
