#include<bits/stdc++.h>
double a[10005],b[10005];
using namespace std;
void copy(double c[],double d[],int i)
{
	for(int p=0;p<=i;p++)
	 d[p]=c[p];
}
int main()
{
	int m;
	 cin>>m;
	for(int o=1;o<=m;o++)
	 cin>>a[o];
	copy(a,b,m);
	for(int o=1;o<=m;o++)
	 printf("%lf ",b[o]);
	 return 0;
}
