#include<bits/stdc++.h>
using namespace std;
#define maxn 501
#define maxm 101
#define maxx 0x7f7f7f7f
long long dp[maxn][maxm*2];//表示第i个人等待j时间的最小值 
int t[maxn],n,m;
long long ask(int line,int to)
{
	long long ans=maxx;
	for(int i=0;i<=to;i++)
		ans=min(ans,dp[line][i]);
	return ans;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>t[i];
	sort(t+1,t+1+n);
	for(int i=0;i<=2*m;i++)
		dp[1][i]=i;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=2*m;j++)
		{
			dp[i][j]=maxx;
			int tmp=t[i]-t[i-1]+j;
			if(tmp>=0&&tmp<=2*m)
				dp[i][j]=min(dp[i][j],dp[i-1][tmp]+j);
			if(tmp>=m)
				dp[i][j]=min(dp[i][j],ask(i-1,min(tmp-m,2*m))+j);
		}
	long long ans=maxx;
	for(int i=0;i<=2*m;i++)
		ans=min(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}
