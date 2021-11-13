#include<cstdio>
#define maxn 2000005
using namespace std;
int n,k;
long long val[maxn],q[maxn],sum[maxn],dp[maxn];
int h=1,t,p=1;
int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&val[i]);
		sum[i]=sum[i-1]+val[i];
	}
	for(int i=1;i<=k;i++)
	dp[i]=sum[i];
	for(int i=k+1;i<=n;i++)
	{
		while(h<=t&&i-q[h]>k)h++;
		while(p<=i)
		{
			while(h<=t&&dp[p-1]-sum[p]>dp[q[t]-1]-sum[q[t]])t--;
	    	q[++t]=p++;
		}
		dp[i]=dp[q[h]-1]-sum[q[h]]+sum[i];
	}
	printf("%I64d",dp[n]);
	return 0;
}
/*
for(int i=1;i<=n;i++)
    {
        while(h<=t&&i-q[h]>=k)h++;//判断队首有没有超过区间范围
    	if(i>=k)f_mx[i-k+1]=max(a[q[h]],a[i]);//求解
    	while(h<=t&&a[i]>=a[q[t]])t--;//判断队尾是否大于队首
    	q[++t]=i;
    }
单调队列

10 3
1 2 3 4 5 6 7 8 9 10
*/
