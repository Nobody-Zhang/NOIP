#include<bits/stdc++.h>
using namespace std;
#define maxn 6667
int dp[2][maxn];
int len1,len2;
char s1[maxn],s2[maxn];
int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&len1,&len2);
	cin>>s1>>s2;
	for(int i=len1;i>=1;i--)
		s1[i]=s1[i-1];
	for(int i=len2;i>=1;i--)
		s2[i]=s2[i-1];
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			if(i%2==0)
			{
				if(s1[i]==s2[j]) dp[0][j]=dp[1][j-1]+1;
				else dp[0][j]=max(dp[1][j],dp[0][j-1]);
			}
			else{
				if(s1[i]==s2[j]) dp[1][j]=dp[0][j-1]+1;
				else dp[1][j]=max(dp[0][j],dp[1][j-1]);
			}
		}
	}
	printf("%d\n",dp[len1%2][len2]);
	return 0;
}
