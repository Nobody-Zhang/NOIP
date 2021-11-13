#include<bits/stdc++.h>
#define maxn 2000005
#define ll long long
using namespace std;
int head=0,tail=1,n,k;
ll dp[maxn],f[maxn],sum[maxn];
int a[maxn],q[maxn];
int read()
{
	int x=0 ; char c=getchar() ;
	while(c<'0'||c>'9') c=getchar() ;
	while(c>='0'&&c<='9') { x=x*10+c-'0', c=getchar() ; }
	return x;
}
int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) 
	{
		a[i]=read();
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(head<tail&&i-q[head]>k) head++;
		dp[i]=f[q[head]]+sum[i];
		f[i+1]=dp[i]-sum[i+1];
		while(head<tail&&f[q[tail-1]]<f[i+1]) tail--;
		q[tail++]=i+1;
	}
    printf("%I64d",dp[n]);
	return 0;
}
/*
5 2
1 2 3 4 5
*/
