#include<cstdio>
#define maxn 6670
using namespace std;
char s1[maxn],s2[maxn];
int dp[2][maxn],a,b;
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&a,&b);
	getchar();
	scanf("%s",s1+1);
	getchar();
	scanf("%s",s2+1);
	int now=1,pre=0;
	for(int i=1;i<=b;i++)
	{
		dp[pre][i]=max(dp[now][i],dp[pre][i-1]);
		if(s1[1]==s2[i])
		dp[pre][i]=max(dp[pre][i],dp[now][i-1]+1);
	}
	for(int i=2;i<=a;i++)
	{
		now=i&1,pre=now^1;
		for(int j=1;j<=b;j++)
		{
			dp[pre][j]=max(dp[now][j],dp[pre][j-1]);
			if(s1[i]==s2[j])
			dp[pre][j]=max(dp[pre][j],dp[now][j-1]+1);
		}
	}
	printf("%d",dp[pre][b]);
	return 0;
}
/*
5 6
abdac
adabac
*/
