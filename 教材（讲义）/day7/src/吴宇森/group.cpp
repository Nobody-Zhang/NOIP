#include<bits/stdc++.h>
using namespace std;
//dp[i]=max(dp[j-1]+sum[i]-sum[j])(i-k<=j<=i)
//dp[i]=max(dp[j-1]-sum[j])+sum[i](i-k<=j<=i)

const int N=2000005;
int n,k,a[N],h=1,t=0;
long long sum[N],dp[N],q[N],f[N];

long long solve()
{
	for(int i=0;i<=n;i++)
	{
		while(h<=t&&i-q[h]>k) h++;
		while(t>=h&&dp[i-1]-sum[i]>=dp[q[t]-1]-sum[q[t]]) t--;
		q[++t]=i;
		dp[i]=sum[i]+dp[q[h]-1]-sum[q[h]];
	}
	return dp[n];
}

int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	scanf("%d%d",&n,&k);
	sum[0]=0;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	//prework();
	printf("%I64d",solve());
	return 0;
}
