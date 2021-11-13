#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2000005;

int n,k,q[maxn],h,t;
ll a[maxn],dp[maxn],sum[maxn];

template<class T> void read(T &re)
{
	re=0;
	T sign=1;
	char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;
	re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=(re<<3)+(re<<1)+(tmp-'0');
	re*=sign;
}

int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	read(n);read(k);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	h=1;
	for(int i=1;i<=min(n,k);i++)
	{
		while(h<=t && i-q[h]>k)	h++;
		while(t>=h && dp[i-1]-sum[i]>=dp[q[t]-1]-sum[q[t]])	t--;
		q[++t]=i;
		dp[i]=sum[i];
	}
	for(int i=k+1;i<=n;i++)
	{
		while(h<=t && i-q[h]>k)	h++;
		while(t>=h && dp[i-1]-sum[i]>=dp[q[t]-1]-sum[q[t]])	t--;
		q[++t]=i;
		dp[i]=sum[i]+dp[q[h]-1]-sum[q[h]];
	}
	printf("%I64d",dp[n]);
	return 0;
}
