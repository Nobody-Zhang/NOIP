#include<cstdio>
#include<cstring>
#define maxn 100005
#define maxm 1005
using namespace std;
int n,m,go[maxm][3],from[maxm][3],flag[maxn];
double dp[maxn];
double min(double a,double b)
{
	return a<b?a:b;
}
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(flag,0,sizeof(flag));
		memset(go,0,sizeof(go));
		scanf("%d%d",&n,&m);
    	for(int i=1;i<=m;i++)
    	{
    		scanf("%d%d",&go[i][1],&go[i][2]);
    		flag[go[i][1]]=i;
    	}
    	for(int i=n;i<=n+5;i++)
    	dp[i]=0;
    	for(int i=n-1;i>=0;i--)
    	{
    		if(flag[i])
    		{
    			dp[i]=dp[go[flag[i]][2]];
    			continue;
    		}
    		for(int j=i+6;j>=i+1;j--)
    		dp[i]+=dp[j];
    		dp[i]=(dp[i]/6)+1.0;
    	}
    	printf("%0.2lf\n",dp[0]);
	}
	return 0;
}
/*
2
2 0
8 3
2 4
4 5
7 8

1
8 3
2 4
4 5
7 8
*/
