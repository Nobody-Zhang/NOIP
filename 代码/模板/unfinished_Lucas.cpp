#include<bits/stdc++.h>
using namespace std;
int n,m,mod;
#define maxn 100001
long long pre[maxn],inv[maxn];
void solve()
{
	memset(inv,0,sizeof(inv));
	memset(pre,0,sizeof(pre));
	inv[1]=1;
	for(int i=2;i<=max(m,n);++i)
		inv[i]=(((mod-mod/i)*inv[mod%i])%mod+mod)%mod;
	pre[0]=1;
	for(int i=1;i<=max(m,n);++i)
		pre[i]=(pre[i-1]*inv[i])%mod;
	long long ans=(pre[m]*pre[n])%mod;
	for(int i=1;i<=(m+n);++i)
	ans=(ans*i)%mod;
	printf("%lld\n",ans);
	return; 
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&mod);
		solve();
	}
}
