#include<cstdio>
using namespace std;
#define rg register int
#define ll long long
#define V inline void
#define I inline int
#define F1(i,a,b) for(rg i=a;i<=b;++i)
#define F2(i,a,b) for(rg i=a;i>=b;--i)
#define bl putchar(' ')
#define ed putchar('\n')
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
const int N=100005;
template<typename TP>V read(TP &x)
{
	TP f=1;x=0;register char c=getchar();
	for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
	x*=f;
}
template<typename TP>V print(TP x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+'0'); 
}
int d,l,r,tot,pri[N],phi[N],f,f2,g[N];
ll ans;
bool vis[N];
template<typename TP>inline ll ksm(TP a,TP b,TP mod)
{
	ll ans=1ll;
	for(rg i=b;i;i>>=1)
	{
		if(i&1) ans=(ll)1ll*(ans*1ll*a)%mod;
		a=(ll)1ll*(a*1ll*a)%mod;
	}
	return ans%mod;
}
template<typename TP>V init(TP n)
{
	phi[1]=1;
	F1(i,2,n)
	{
		if(!vis[i]) pri[++tot]=i,phi[i]=i-1;
		for(rg j=1;j<=tot&&pri[j]*i<=n;++j)
		{
			vis[pri[j]*i]=1;
			if(i%pri[j]==0)
			{
				phi[pri[j]*i]=pri[j]*phi[i];
				break;
			}
			phi[pri[j]*i]=(pri[j]-1)*phi[i];
		}
	}
}
template<typename TP>I ph(TP x)
{
	TP sum=x;
	for(rg i=2;i*i<=x;++i)
	{
		if(x%i==0) sum=sum/i*(i-1);
		while(x%i==0) x/=i;
	}
	if(x>1) sum=sum/x*(x-1);
	return sum;
}
template<typename TP>I di(TP x)
{
	TP sum=0;
	F1(i,1,phi[x])
	{
		if(x%pri[i]==0) sum+=pri[i];
		while(x%pri[i]==0) x/=pri[i];
	}
	return sum;
}
int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	read(l),read(r),read(d),init(r),g[1]=1;
	f=ph(d),f2=ph(f);
	F1(i,2,r) g[i]=di(i);
	F1(i,l,r) g[i]%=f2;
	F1(i,l,r) g[i]=ksm(3,g[i],f);
	F1(i,l,r) g[i]=ksm(2048,g[i],d),ans^=g[i];
	print(ans);
	return 0;
}
