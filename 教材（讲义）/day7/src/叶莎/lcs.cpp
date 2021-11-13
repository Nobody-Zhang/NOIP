#include<bits/stdc++.h>
using namespace std;
char s1[7000],s2[7000];
int dp[2][6670];
int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	int n,m;
	int now,pre;
	scanf("%d%d",&n,&m);
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	for(int i=1;i<=n;i++)
	{
		now=i&1; pre=now^1;//通过位运算01转换,一定保证now和pre不同 
		for(int j=1;j<=m;j++)
		{
			if(s1[i]==s2[j]) 
			  dp[pre][j]=dp[now][j-1]+1;
			else dp[pre][j]=max(dp[now][j],dp[pre][j-1]);
		}
	}
	printf("%d",dp[n&1^1][m]);
	return 0;
}
/*
5 6
abdac
adabac
*/

