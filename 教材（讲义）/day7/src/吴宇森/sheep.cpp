#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int T,n,to[N],m;
double dp[N];

double solve()
{
	for(int i=n-1;i>=0;i--)
	{
		if(to[i]) 
		{
			dp[i]=dp[to[i]];
			continue;
		}
		for(int j=1;j<=6;j++)
		dp[i]=(double)dp[i]+dp[i+j]*1.0/6;
		dp[i]++;
	}
	return dp[0];
}

int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+7;i++)
		dp[i]=0,to[i]=0;
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			to[a]=b;
		}
		printf("%.2lf\n",solve());
	}
	return 0;
} 
