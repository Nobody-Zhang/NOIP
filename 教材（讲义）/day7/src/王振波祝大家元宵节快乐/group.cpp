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
        while(h<=t&&i-q[h]>=k)h++;//�ж϶�����û�г������䷶Χ
    	if(i>=k)f_mx[i-k+1]=max(a[q[h]],a[i]);//���
    	while(h<=t&&a[i]>=a[q[t]])t--;//�ж϶�β�Ƿ���ڶ���
    	q[++t]=i;
    }
��������

10 3
1 2 3 4 5 6 7 8 9 10
*/
