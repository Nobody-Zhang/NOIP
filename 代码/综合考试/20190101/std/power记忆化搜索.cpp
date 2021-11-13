#include<bits/stdc++.h>
using namespace std;int n,c;
int qianzuihe[60],dp[60][60][3],d[60];
int  dfs(int l,int r,int f)
{
	int vec=l;
	if(f==1)vec=r;
	if(dp[l][r][f]!=0x7f7f7f7f)return dp[l][r][f];
	if(l==1&&r==n)return dp[l][r][f]=0;
	if(l-1>=1)
	{
		int dis=abs(d[l-1]-d[vec]);
		dp[l][r][f]=min(dp[l][r][f],dfs(l-1,r,0)+dis*(qianzuihe[n]-(qianzuihe[r]-qianzuihe[l-1])));
	}
	if(r+1<=n)
	{
		int dis=abs(d[r+1]-d[vec]);
		dp[l][r][f]=min(dp[l][r][f],dfs(l,r+1,1)+dis*(qianzuihe[n]-(qianzuihe[r]-qianzuihe[l-1])));
	}
	return dp[l][r][f];
}
int main()
{
	freopen("power.in","r",stdin);
	 freopen("power.out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		int w;
		scanf("%d%d",&d[i],&w);
		qianzuihe[i]=qianzuihe[i-1]+w;
	}
	memset(dp,0x7f7f7f7f,sizeof(dp));
	dfs(c,c,1);
	cout<<min(dp[c][c][1],dp[c][c][0]);
	
}
