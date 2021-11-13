#include<bits/stdc++.h>

using namespace std;

const int maxn=6667;
int n,m,dp[5][maxn];
char a[maxn],b[maxn];

int get(int x)
{
	if(x==0)
	return 4;
	return x;
}
int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>a+1;cin>>b+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j]) 
			dp[i%4][j]=max(max(dp[get(i%4)-1][j],dp[i%4][j-1]),dp[get(i%4)-1][j-1]+1);
			else 
			dp[i%4][j]=max(dp[get(i%4)-1][j],dp[i%4][j-1]);
		}
	}
	printf("%d",dp[n%4][m]);
	return 0;
}
