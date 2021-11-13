#include<bits/stdc++.h>
using namespace std;

const int N=505;
int n,m,t[N],dp[N][N];

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&t[i]);
	sort(t+1,t+n+1);
	for(int i=0;i<2*m;i++)
	dp[1][i]=i;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<2*m;j++)
		{
			dp[i][j]=0x3f3f3f;
			for(int k=0;k<2*m;k++)
			{
				int tmp=t[i]+j-(t[i-1]+k);
				if(tmp==0||tmp>=m)
				dp[i][j]=min(dp[i][j],dp[i-1][k]+j);
			}
		}
	}
	int ans=0x3f3f3f;
	for(int i=0;i<2*m;i++)
	ans=min(ans,dp[n][i]);
	printf("%d",ans);
	return 0;
}
