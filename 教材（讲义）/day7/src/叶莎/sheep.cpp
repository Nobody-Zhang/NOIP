#include<bits/stdc++.h>
using namespace std;
double dp[100003];
int tann[100003];
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		memset(tann,0,sizeof(tann));
		int n,m;
		scanf("%d%d",&n,&m);
		int a,b;
		for(int i=1;i<=m;i++) 
		{
			scanf("%d%d",&a,&b);
		    tann[a]=b;
		}
		
		for(int i=n-1;i>=0;i--)//dp[i]位置在i时扔骰子的期望次数
		{
			dp[i]=0;
			if(!tann[i])
			for(int j=1;j<=6;j++)
			{
				
				dp[i]+=(dp[i+j]+1)/6;
				
			}else dp[i]=dp[tann[i]];
		} 
		printf("%.2lf\n",dp[0]);
	}
}
/*
2
2 0
8 3
2 4
4 5
7 8
*/

