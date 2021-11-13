#include<bits/stdc++.h>
#define N 65
using namespace std;
int dp[N][N][2],m,n,front[N],d[N];//三种状态 
int dfs(int l,int r,int whe)
{
	int pos=l;
	if(whe==1)//表示当前在右边 
	 pos=r;
	if(dp[l][r][whe]!=0x7f) return dp[l][r][whe];
	if(l==1&&r==n) return dp[l][r][whe]=0;
	if(l>=2)
	{
		int tmp=abs(d[l-1]-d[pos]);
		dp[l][r][whe]=min(dp[l][r][whe],dfs(l-1,r,0)+tmp*(front[n]-(front[r]-front[l-1])));
	}
	if(r<=n-1)
	{
		int tmp=abs(d[pos]-d[r+1]);
		dp[l][r][whe]=min(dp[l][r][whe],dfs(l,r+1,1)+tmp*(front[n]-(front[r]-front[l-1])));
	}
	return dp[l][r][whe];
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		front[i]=front[i-1]+b;
		d[i]=a;
	}
	memset(dp,0x7f,sizeof(dp));
	dfs(n,n,1);
	cout<<min(dp[n][n][1],dp[n][n][0]);
	return 0;
}
