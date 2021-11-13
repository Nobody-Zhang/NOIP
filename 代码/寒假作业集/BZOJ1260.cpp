#include<bits/stdc++.h>
using namespace std;
char c[51];
int n,dp[51][51];
int main()
{
	scanf("%d",&n);
	memset(dp,8,sizeof(dp));
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%c",&c[i]);
//		dp[i][i]=1;
//	}
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		c[i]=s[i-1];
		dp[i][i]=1;
	}
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=n;j++)
		{
			if(j+i>n) break;
			int a=j,b=j+i;//a是当前的标号，b是最终标号 
			if(c[a]==c[b]) {
				dp[a][b]=min(dp[a+1][b],dp[a][b-1]);
				continue;
			}
			else{
				for(int k=a;k<=b;k++)
					dp[a][b]=min(dp[a][b],dp[a][k]+dp[k+1][b]);
				continue;
			}
		}
	printf("%d",dp[1][n]);
	return 0;
 } 
