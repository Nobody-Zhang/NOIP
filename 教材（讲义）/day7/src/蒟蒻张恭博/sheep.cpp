#include<bits/stdc++.h>
using namespace std;
#define maxn 100007
#define maxm 1001
double dp[maxn];
//dp表示已经走过i步了，还需走的期望步数 
int t,n,m,mp[maxn];
int jumpfrom[maxn];
void solve1()
{
	for(int i=n-1;i>=0;i--)
	{
		double ans=0;
		for(int j=1;j<=6;j++){
			ans+=(double)(dp[i+j]+1);
		}
		dp[i]=(double)1/6*ans;
	}
	printf("%.2lf\n",dp[0]);
}
void solve2()
{
	for(int i=n-1;i>=0;i--)
	{
		if(mp[i]) {
			dp[i]=dp[mp[i]] ;
			continue;
		}
		double ans=0;
		for(int j=1;j<=6;j++){
			ans+=(double)(dp[i+j]+1);
		}
		dp[i]=(double)1/6*ans;
	}
	printf("%.2lf\n",dp[0]);
}
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(mp,0,sizeof(mp));
		memset(jumpfrom,0,sizeof(jumpfrom));
		scanf("%d%d",&n,&m);
		if(m==0) {
			solve1();
			continue;
		}
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			mp[a]=b;
			jumpfrom[b]=a;
		} 
		solve2();
	}
}
