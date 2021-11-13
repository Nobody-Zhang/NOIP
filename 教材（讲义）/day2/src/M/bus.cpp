#include<bits/stdc++.h>
using namespace std;
const int maxn=501;
const int maxm=101;
const long long oo=1LL<<60;

long long dp[maxn][maxm*2];
//dp[i][j] 表示 第i个人等了j分钟时，前i个人的等待时间总和的最小值

int t[maxn],n,m;
inline long long f(int i,int k)//第i个人等待0~k分钟的最优答案
{
	long long ans=oo;
	for(int j=0;j<=k;j++)
		ans=min(ans,dp[i][j]);
	return ans;
}

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	sort(t+1,t+1+n);

	for(int i=0;i<=2*m;i++)
		dp[1][i]=i;

	for(int i=2;i<=n;i++)
		for(int j=0;j<=2*m;j++)
		{
			dp[i][j]=oo;
			int tmp=t[i]-t[i-1]+j;//tmp是前一个人加上第i个人等待时间的总的等待时间时间间隔
			if(tmp>=0&&tmp<=2*m)
				dp[i][j]=min(dp[i][j],dp[i-1][tmp]+j);
			if(tmp>=m)
				dp[i][j]=min(dp[i][j],f(i-1,min(tmp-m,2*m))+j);
		}

	long long ans=oo;
	for(int i=0;i<=2*m;i++)
		ans=min(ans,dp[n][i]);
	printf("%lld\n",ans);
	return 0;
}