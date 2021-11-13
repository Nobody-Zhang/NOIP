#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[11];
ll lc[1<<11];

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())<='9'&&c>='0') x=x*10+c-48; x*=sign;
}

ll gcd(ll a,ll b) { return b ? gcd(b,a%b) : a;}
void solve1()
{
	cout<<m-m/a[1]<<endl;
}
void solve2()
{
	ll ans=m;
	ans=ans-m/a[1]-m/a[2];
	ans+=m/(a[1]*a[2]/gcd(a[1],a[2]));
	cout<<ans<<endl;
}
void solve3()
{
	int ans=0;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(i%a[j]==0) goto u;
		}
		ans++;
		u:;
	}
	cout<<ans<<endl;
}
void solve4()
{
	int ans=m;
	for(int i=1;i<=n;++i) lc[1<<(i-1)]=a[i],ans-=m/a[i];
	for(int i=2;i<=n;++i)//枚举每一轮 
	{
		for(int j=1;j<(1<<n);++j)//枚举每一种状态 
		{
			int k=j,p=0;
			while(k)
			{
				p++;
				k-=(k&(-k));
			}
			if(p!=i) continue;//数量不等 
			for(int q=1;q<=n;++q)//由哪一个扩展来的 
			{
				if(!((1<<(q-1))&j)) continue;//包含
				int w=j&(~(1<<(q-1)));
				lc[j]=lc[w]/gcd(lc[w],a[q])*a[q];
				if(lc[j]>m||lc[j]<0) lc[j]=m+1;
				break;
			}
			if(i%2) ans-=m/lc[j];
			else ans+=m/lc[j];
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;++i) read(a[i]);
	
	if(m<=1000000) solve3();
	else if(n==2) solve2();
	else if(n==1) solve1();
	else solve4();

	return 0;
}
