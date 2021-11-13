#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int n,k,maxx=0;
int main()
{
	int i,j;
	//freopen("group.in","r",stdin);
	//freopen("group.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=k;i++)
	{
		maxx+=a[i];
	}
	for(i=n-k;i<=n;i++)
	{
		maxx+=a[i];
	}
	cout<<maxx;
	return 0;
}
