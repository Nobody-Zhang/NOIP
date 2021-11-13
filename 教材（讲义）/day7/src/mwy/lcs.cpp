#include<bits/stdc++.h>
using namespace std;
int dp[3][6666],len1,len2;
char s[6666],t[6666];
int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&len1,&len2);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=len1;i++)
	{
		int now=i&1,pre=now^1;
		for(int j=1;j<=len2;j++)
		{
			if(s[i]==t[j])
			 dp[now][j]=dp[pre][j-1]+1;//如果是+=就要清0 
			else 
			 dp[now][j]=max(dp[pre][j],dp[now][j-1]);
		}
	}
	printf("%d\n",dp[len1&1][len2]);
}
/*
5 6
abdac
adabac
*/
