#include<cstdio>
#include<cstring>
#define maxn 500005
#define oo 1125899906842624
typedef long long ll;
using namespace std;
ll n,d,k,val[maxn],dis[maxn];
ll q[maxn],f[maxn];
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool check(ll g)
{
	ll lf=max(1,d-g),rg=d+g;
	int h=1,t=0,now=0;
	for(int i=0;i<=n+10;i++)
	{
		f[i]=-oo,q[i]=0;
	}
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		while(dis[i]-dis[now]>=lf)
		{
			while(h<=t&&f[now]>=f[q[t]])t--;
			q[++t]=now++;
		}
		while(h<=t&&dis[i]-dis[q[h]]>rg)h++;
		if(h<=t)//非空队列
		f[i]=f[q[h]]+val[i];
		if(f[i]>=k)return true;
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%I64d%I64d%I64d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	scanf("%I64d%I64d",&dis[i],&val[i]);
	ll L=0,R=dis[n];
	while(L<=R)
	{
		ll mid=(L+R)>>1;
		if(check(mid))
		R=mid-1;
		else L=mid+1;
	}//二分g
	if(L<=dis[n])
	printf("%I64d",L);
	else
	printf("-1");
	return 0;
}
