#include<bits/stdc++.h>
using namespace std;
int n,m,a[21],b[10000001];
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==1)
	{
		if(a[1]>m)
		cout<<m<<endl;
		else
		cout<<m-m/a[1]<<endl;
		return 0;
	}
	if(n==2)
	{
		if(a[1]*a[2]>m)
		cout<<m-2<<endl;
		cout<<m-m/(a[1]*a[2])<<endl;
		return 0;
	}
	return 0;
}
