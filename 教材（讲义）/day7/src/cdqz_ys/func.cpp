#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int tot=0;
int not_prime[100003],prime[100000];
ll g[100005];
void su(int n)
{
	for(int i=2;i<=n;i++)
    {
    	if(!not_prime[i]) prime[++tot]=i;
    	for(int j=1;j<=tot&&i*prime[j]<=n;j++)
    	{
    		not_prime[i*prime[j]]=1;
    		if(i%prime[j]==0) break;
    	}
    }
}
ll findd(ll x)
{
	if(x==1) return 1;
	ll ans=0;
	su(x);
	for(int i=2;i<=x;i++)
	{
		if(x%i==0&&!not_prime[i]) ans+=i;
	}
	return ans;
}
ll kuai(ll x,ll a,ll mod)
{
	ll ans=1;
	ll k=a;
	while(k)
	{
		if(k%2==1) ans=ans*x%mod;
		k=k/2;
		x=x*x%mod;
	}
	ans=ans%mod;
	return ans;
}
int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	ll l,r,d;
	scanf("%I64d%I64d%I64d",&l,&r,&d);
	ll u=2048%d;
	ll v=((u%d)*(u%d)*(u%d))%d;//v=2048^3
	if(l==r)
	{
		ll G=findd(l);
		printf("%I64d",kuai(v,G,d));
		return 0;
	}
	ll G=findd(l);
	ll sum=kuai(v,G,d)%d;
	for(int i=l+1;i<=r;i++)
	{
		ll G=findd(i);
		if(g[i]) sum=(sum^g[i])%d;
		else 
		{
			g[i]=(kuai(v,G,d))%d;
			sum=(sum^g[i])%d;
		}
	}
    printf("%I64d",sum);
}
