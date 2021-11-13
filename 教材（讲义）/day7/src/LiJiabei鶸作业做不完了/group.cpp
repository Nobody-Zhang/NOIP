#include<bits/stdc++.h>
using namespace std;
const int maxn=2000010;
int n,k,cnt,tot;
int a[maxn],Que[maxn],pos[maxn];
long long f[maxn],sum[maxn];
long long dp[maxn];//第i位的最优值 
int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	int head=1,tail=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	Que[++tail]=0;
	for(int i=1;i<=n;i++)
	{
		while(i-Que[head]>k&&head<tail)
		{
			head++;
		}
		dp[i]=f[Que[head]]+sum[i];
		f[i+1]=dp[i]-sum[i+1];
		while(f[Que[tail]]<f[i+1]&&head<tail)
		{
			tail--;
		}
		Que[++tail]=i+1;
	}
	printf("%I64d",dp[n]);
	return 0;
}
