#include<bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;

int st[N],cnt,l,r,d,g[N],phi[N],p;
bool vis[N];

inline int read()
{
	int ans=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}

inline int mul(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1) (ans*=a)%=d;
		(a*=a)%=d;
		b>>=1;
	}
	return ans;
}

inline int mul1(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1) (ans*=a)%=p;
		(a*=a)%=p;
		b>>=1;
	}
	return ans;
}

inline int get_phi(int x)
{
	if(x<=N-5) return phi[x];
	else
	{
		int t=1;
		for(int i=1;i<=cnt;++i)
			if(x%st[i]==0)
			{
				int sum=1;
				while(x%st[i]==0)
				{
					x/=st[i];sum*=st[i];
					if(x<=N-5)
					{
						if(x%st[i]==0) return phi[x]*sum*phi[t];
						else return phi[x]*phi[sum]*phi[t];
					}
				}
				t*=sum;
			}
		return phi[t]*(x-1);
	}
}

signed main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	l=read(),r=read(),d=read();
	phi[1]=1;g[1]=1;
	for(int i=2;i<=N-5;++i)
	{
		if(!vis[i]) st[++cnt]=i,g[i]=i,phi[i]=i-1;
		for(int j=1;j<=cnt&&st[j]*i<=N-5;++j)
		{
			vis[i*st[j]]=1;
			if(i%st[j]==0) {g[i*st[j]]=g[i];phi[i*st[j]]=phi[i]*st[j];break;}
			else g[i*st[j]]=g[i]+st[j],phi[i*st[j]]=phi[i]*(st[j]-1);
		}
	}
	int ans=0;p=get_phi(d);
	for(int i=l;i<=r;++i) ans^=mul(2048,mul1(3,g[i]));
	printf("%lld",ans);
}
