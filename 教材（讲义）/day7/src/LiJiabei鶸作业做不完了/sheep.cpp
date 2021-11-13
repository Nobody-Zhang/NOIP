#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int t,n,m,x,y;
double dp[maxn];//从第i个格子开始跳的期望步数 
int jump[maxn];
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(jump,0,sizeof(jump));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			jump[x]=y;
		}
		for(int i=n-1;i>=0;i--)
		{
			dp[i]=0;
			if(!jump[i])
			{
				for(int j=1;j<=6;j++)
				{
					dp[i]+=(dp[i+j]+1)/6;//所有可能的期望 
				} 
			} 
			else
			{
				dp[i]=dp[jump[i]];
			}
		}
		printf("%.2lf\n",dp[0]);
	}
	return 0; 
}
