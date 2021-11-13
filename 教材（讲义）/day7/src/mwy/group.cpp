#include<bits/stdc++.h>
using namespace std;
#define N 2000005
#define ll long long
ll n,k,a[N],dp[N],sum[N],q[N],f[N];
int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	scanf("%I64d%I64d",&n,&k);
	for(int i=1;i<=n;i++)
	 scanf("%I64d",&a[i]),sum[i]=sum[i-1]+a[i];
	int h=0,t=0;
	q[++t]=0;
	for(int i=1;i<=n;i++)
	{
		while(h<t&&i-q[h]>k) h++;
		dp[i]=sum[i]+f[q[h]];
		f[i+1]=dp[i]-sum[i+1];
		while(h<t&&f[i+1]>f[q[t-1]]) t--;
		q[t++]=i+1;
	}
	/*for(int i=1;i<=n;++i){
		while(head<tail && i-que[head]>K) head++ ;
		dp[i] = f[que[head]] + sum[i] ;
		f[i+1] = dp[i]-sum[i+1] ;
		while(head<tail && f[que[tail-1]]<f[i+1]) tail-- ;
		que[tail++]=i+1 ;
	}*/
	printf("%I64d\n",dp[n]);
}
/*
5 2 
1 2 3 4 5
*/
