#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int jmp[maxn],n,m,T,a,b;
double dp[maxn];
void clear()
{
	memset(jmp,0,sizeof(jmp));
	memset(dp,0,sizeof(dp));
}
void solve()
{
	dp[n]=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		jmp[a]=b;
	}
	for(int i=n-1;i>=0;i--)
	{
		dp[i]=0;
		if(!jmp[i])
		{
			for(int j=1;j<=6;j++)
			dp[i]+=(dp[i+j]+1)/6;
		}
		else dp[i]=dp[jmp[i]];
	}
	printf("%.2lf\n",dp[0]);
}
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		clear();
		solve();
	}
	return 0;
}
/*
2
2 0
8 3
2 4
4 5
7 8
*/
