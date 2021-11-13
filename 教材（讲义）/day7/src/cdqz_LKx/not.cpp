#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
#define ll long long
bool vis[maxn];
ll cnt=0;
ll a[maxn];
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	ll n,m;
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=1;j*a[i]<=m;j++)
		vis[j*a[i]]=1;
	}
	for(int i=1;i<=m;i++)
	{
		if(vis[i]!=1)
		cnt++;	
	}
	printf("%I64d\n",cnt);	 
}
/*
4 100
5 6 48 40
*/
/*
2 12
2 4
*/
