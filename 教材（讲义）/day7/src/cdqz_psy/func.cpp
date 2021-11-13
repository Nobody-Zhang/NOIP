#include<bits/stdc++.h>
#define ll long long 
#define maxn 10005
using namespace std;
ll g[maxn],l,r,mod,ans;
ll quickpow(ll x,ll b,ll k)
{
	ll a=1;
	while(b)
	{
		if(b%2) a=a*x%k;
		b=b/2;
		x=x*x%k;
	}
	return a%k;
}
ll F(ll x)
{ 
    ll now=x;
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			while(now%i==0) now=now/i;
			g[x]+=i;
			printf("%I64d ",g[x]);
		}
	}
	if(now!=1) g[x]+=now; 
	ll poww=quickpow(3,g[x],mod-1);
	return quickpow(2048,poww,mod);
}
int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	scanf("%I64d%I64d%I64d",&l,&r,&mod);
	if(l==r) {
		printf("%I64d",F(l));
		return 0;
	}
	g[l]=0;
	ans=F(l);
	for(ll i=l+1;i<=r;i++)
	{
		g[i]=0;
		ans=ans^F(i);
	}
	printf("\n%I64d",ans);
	return 0;
}
