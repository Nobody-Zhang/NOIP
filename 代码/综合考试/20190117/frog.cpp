#include<bits/stdc++.h>
using namespace std;
#define N 300
long long dp[N][N],m,n;
long long dfs(int a,int b)
{
	long long ans=dp[0][b];
	for(int i=0;i<=a;i++)
	 ans+=dp[i][b];
	return ans;
}
int main()
{
	freopen("frog.in","r",stdin);
	freopen("frog.out","w",stdout);
	cin>>m>>n;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	 dp[0][i]=i+1;
	for(int i=1;i<=m;i++)
	 dp[i][0]=dp[i-1][0]*2;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=n;j++)
	  dp[i][j]=dfs(i,j);
	cout<<dp[m][n]<<endl;
	return 0;
}
