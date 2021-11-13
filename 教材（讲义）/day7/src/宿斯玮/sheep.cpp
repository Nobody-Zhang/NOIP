#include<bits/stdc++.h>

using namespace std;

int T,n,m,tong[110000];
double dp[110000];

int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+7;i++)
		{
			dp[i]=0;
			tong[i]=0;
		}
			
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			tong[x]=y;
		}
		for(int i=n-1;i>=0;i--)
		{
			if(tong[i]!=0)
			{
				dp[i]=dp[tong[i]];
				continue;
			}
			for(int j=1;j<=6;j++)
				dp[i]=(double)dp[i]+dp[i+j]*1.0/6;
			dp[i]++;
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

1
8 3 
2 4 
4 5 
7 8
*/
