#include<bits/stdc++.h>
using namespace std;
//第k个人不选 ,区间和最大 
const int maxn=2000005 ;
int a[maxn], head, tail, que[maxn] ;
long long sum[maxn], dp[maxn], f[maxn] ;
int reads()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') {
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
//由题可以得出dp[i]=max(dp[j-1]-sum[j])+sum[i] 
int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	int n,k;
	n=reads(),k=reads();
	for(int i=1;i<=n;i++)
	{
		a[i]=reads();	
		sum[i]=sum[i-1]+a[i];
	}
	que[tail++]=0;
	for(int i=1;i<=n;i++)//dp[i]仅考虑前i个人的最大收益 
	{
		while(head<tail&&i-que[head]>k) head++;//移动头指针，调整上界 
		dp[i]=f[que[head]]+sum[i];//f[i]=dp[j-1]-sum[j] 
		f[i+1]=dp[i]-sum[i+1];
		while(head<tail&&f[que[tail-1]]<f[i+1]) tail--;
		que[tail++]=i+1;
	}
	printf("%I64d\n",dp[n]);
}
/*
5 2
1 2 3 4 5
*/
