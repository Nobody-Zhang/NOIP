#include<bits/stdc++.h>
using namespace std;
double a[13],all,pj;
int main()
{
	for(int i=1;i<=12;i++)
	{
		cin>>a[i];
		all+=a[i];
	}
	pj=1.0*all/12;
	printf("%.2lf",pj);
	return 0;
}
