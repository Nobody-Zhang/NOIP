#include<cstdio>
#define maxn 500005
#define ll long long
using namespace std;
ll n,m,p1,s1,p2,s2;
ll dis[maxn];
ll tot1,tot2,delta;
ll max(ll a,ll b)
{
	return a>b?a:b;
}
int del(ll x,ll y)
{
	ll now=max(x-y,y-x);
	if(now<delta)
	{
		delta=now;
		return 1;
	}
	return 0;
}
int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%I64d",&dis[i]);
	scanf("%I64d%I64d%I64d%I64d",&m,&p1,&s1,&s2);
	dis[p1]+=s1;
	for(int i=1;i<m;i++)
	tot1+=(m-i)*dis[i];
	for(int i=m+1;i<=n;i++)
	tot2+=(i-m)*dis[i];
	delta=max(tot1-tot2,tot2-tot1);
	if(tot1<tot2)
	{
		ll ans=m;
		for(int i=1;i<m;i++)
		if(del(tot1+(m-i)*s2,tot2))
		ans=i;
		printf("%I64d",ans);
	}
	if(tot1==tot2)
	printf("%I64d",m);
	if(tot1>tot2)
	{
		ll ans=m;
		for(int i=m+1;i<=n;i++)
		if(del(tot1,tot2+(i-m)*s2))
		ans=i;
		printf("%I64d",ans);
	}
	return 0;
}
