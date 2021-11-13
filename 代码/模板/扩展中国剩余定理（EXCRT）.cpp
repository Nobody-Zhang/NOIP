#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define myll "%lld"
#define ri register int
#define maxn 100005
template <typename T> inline void redi(T& t)
{
	ri c=getchar();t=0;bool flag=false;
	if(c=='-') flag=true;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=t*10+c-'0',c=getchar();
	if(flag) t=-t;
}
template <typename T,typename... Args> inline void redi(T& t,Args& ...args)
{
	redi(t);
	redi(args...);
}
ll a[maxn],b[maxn];
int n;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll tmp=exgcd(b,a%b,x,y);
	ll xx=x,yy=y;
	x=yy;
	y=xx-(ll)ceil(a/b)*yy;
	return tmp;
}
ll qmul(ll a,ll b,ll mod)
{
	ll ans=0;
	while(b>0)
	{
		if(b&1) ans=(ans+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return ans;
}
ll excrt()
{
	ll ans=b[1],M=a[1];
	for(ri i=2;i<=n;i++)
	{
		ll k,m,exp=((b[i]-ans)%a[i]+a[i])%a[i];
		ll gcd=exgcd(M,a[i],k,m);
		k=qmul(k,exp/gcd,a[i]);
		ans+=M*k;
		M=M*(a[i]/gcd);
		ans=(ans%M+M)%M;
	}
	return (ans%M+M)%M;
}
int main()
{
	redi(n);
	for(ri i=1;i<=n;i++)
		redi(a[i],b[i]);
	for(ri i=1;i<=n;i++)
		b[i]%=a[i];
	printf(myll,excrt());
} 
