#include<bits/stdc++.h>
using namespace std;
int n,m,dp[7000][7000];
char a[7000],b[7000];
int main()
{
	int i,j;
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][0]=0;
	}
	for(i=1;i<=m;i++)
	{
		cin>>b[i];
		dp[0][j]=0;	
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
		cout<<dp[n][m];
	return 0;
}
