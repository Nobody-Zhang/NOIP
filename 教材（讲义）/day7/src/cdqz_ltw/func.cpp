#include<cstdio>
#define ll long long
using namespace std;

ll l,r,d,ans;

ll poww (ll x,ll y,ll mod)
{
	ll ans=1;
	while (y>0)
	{
		if (y&1)
			ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans%mod;
}
ll powww (ll x,ll y)
{
	ll ans=1;
	while (y>0)
	{
		if (y&1)
			ans=ans*x;
		x=x*x;
		y>>=1;
	}
	return ans;
}
ll g (ll x)
{
	ll sum=0;
	for (ll i=2;i*i<=x;i++)
		if (x%i==0)
		{
			sum+=i;
			while (!(x%i))
				x/=i;
		}
	return sum+x;
}
ll f (ll x)
{
	return poww (2048,powww (3,g (x)),d);
}

int main()
{
	freopen ("func.in","r",stdin);
	freopen ("func.out","w",stdout); 
	scanf ("%lld%lld%lld",&l,&r,&d);
	ans=f (l);
	for (register ll i=l+1;i<=r;i++)
		ans=ans^(f (i));
	printf ("%lld",ans);
}
