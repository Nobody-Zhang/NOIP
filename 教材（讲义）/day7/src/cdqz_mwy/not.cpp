#include<bits/stdc++.h>
using namespace std;
int a[12];
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	int ans=0,n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ans+=(a[1]-1);
	for(int i=a[1];i<=m;i++)
	{
		int flag=0;
		for(int j=1;j<=n;j++)
	     if(i%a[j]==0)
	      { flag=1; break; } 
	    if(!flag) ans++;
	}
	printf("%d\n",ans);
}
/*
4 100
5 6 40 48 
*/
