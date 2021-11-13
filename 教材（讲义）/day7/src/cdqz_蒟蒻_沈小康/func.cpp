#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int l,r;
ll mod,phi,phii;

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())<='9'&&c>='0') x=x*10+c-48; x*=sign;
}

ll quickpow(ll a,ll b,ll mod)
{
	ll ret=1%mod;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll g(int x)
{
	ll ret=0;
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0)
		{
			ret=(ret+i)%phii;
			while(x%i==0) x/=i;
		}
	}
	if(x!=1) ret=(ret+x)%phii;
	return ret;
}
ll f(int x)
{
	return quickpow(2048,quickpow(3,g(x),phi),mod)%mod;
}
void init(ll m,ll &p)
{
	ll x=m; p=m;
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0)
		{
			p=p/i*(i-1);
			while(x%i==0) x/=i;
		}
	}
	if(x!=1) p=p/x*(x-1);
}
int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	read(l);read(r);read(mod);
	init(mod,phi);
	init(phi,phii);
	ll ans=0;
	for(int i=l;i<=r;++i) ans^=f(i);
	cout<<ans<<endl;
	return 0;
}
