#include<bits/stdc++.h>
using namespace std;

int n, m, dp[2][7000];
char s[7000],c[7000];

int max(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	scanf("%s",c);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int now=(i&1), pre=(now^1);
			if(s[i-1]==c[j-1])
				dp[now][j]=max(dp[pre][j-1]+1,max(dp[pre][j],dp[now][j-1]));
			else
				dp[now][j]=max(dp[pre][j],dp[now][j-1]);
		}
	printf("%d",dp[n&1][m]);
	return 0;
}
