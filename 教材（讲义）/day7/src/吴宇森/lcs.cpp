#include<bits/stdc++.h>
using namespace std;

const int N=6670;
int n,m,dp[3][N];
char a[N],b[N];

int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",a+1),getchar(),scanf("%s",b+1);
	for(int i=1;i<=m;i++)
	dp[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int now=i&1,pre=now^1;
			if(a[i]==b[j]) dp[now][j]=dp[pre][j-1]+1;
			else dp[now][j]=max(dp[pre][j],dp[now][j-1]);
		}
	}
	printf("%d",dp[n&1][m]);
	return 0;
}
