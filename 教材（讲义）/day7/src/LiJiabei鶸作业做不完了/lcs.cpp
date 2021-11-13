#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
const int N=7500;
long long dp[2][N];//到达i位置,j位置的最多匹配值 
char s[maxn];
char l[maxn];
int n,m,sum;
int main()
{	
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,l+1);
	for(int i=1;i<=n;i++)
	{
		int now=i&1,pre=now^1;
		for(int j=1;j<=m;j++)
		{
			if(s[i]==l[j])
			{
				dp[now][j]=dp[pre][j-1]+1;
			}
			else
			{
				dp[now][j]=max(dp[pre][j],dp[now][j-1]);
			}
		}
	}
	cout<<dp[n&1][m];
	return 0;
}

