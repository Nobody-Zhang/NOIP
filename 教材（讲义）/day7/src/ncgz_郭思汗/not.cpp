#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[15],ans;
bool vis[15];

inline int read()
{
	int ans=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}

int gcd(int a,int b){if(b) return gcd(b,a%b);return a;}

inline int lcm(int a,int b){return a/gcd(a,b)*b;}

void dfs(int x)
{
	int sum=1,tot=0;
	for(int i=1;i<=n;++i)
		if(vis[i])
		{
			sum=lcm(a[i],sum);
			if(sum>m) return;
			tot++;
		}
		assert(sum>0);
	if(tot&1) ans+=m/sum;
	else ans-=m/sum;
	if(x==n+1)return;
	for(int i=x;i<=n;++i)
		vis[i]=1,dfs(i+1),vis[i]=0;
}

signed main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	dfs(1);
	printf("%lld",-ans); 
}
