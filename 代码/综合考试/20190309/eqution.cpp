#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxn 1003
int n,m,mod;
long long inv[maxn],pre[maxn];
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0){
		x=1,y=0;
		return a;
	}
	long long gcd=exgcd(b,a%b,x,y);
	long long xx=y;
	long long yy=(x-(long long)ceil(a/b)*y);
	x=xx;
	y=yy;
	return gcd;
}
void solve()
{
	memset(inv,0,sizeof(inv));
	inv[1]=1;
	for(int i=2;i<=max(m,n-1);++i)
		inv[i]=((mod-mod/i)*inv[mod%i])%mod; 
	memset(pre,0,sizeof(pre));
	pre[0]=1;
	for(int i=1;i<=max(m,n-1);++i)
		pre[i]=(pre[i-1]*inv[i]%mod+mod)%mod;
	long long ans=1;
	for(int i=1;i<=m-1+n;++i)
		ans=(ans*i%mod+mod)%mod;
	ans=(ans*pre[m]%mod+mod)%mod;
	ans=(ans*pre[n-1]%mod+mod)%mod;
	printf("%I64d\n",ans);
	return;
}
int main()
{
	freopen("eqution.in","r",stdin);
	freopen("eqution.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&mod);//n是有多少的板子 
		solve();
	}
}
