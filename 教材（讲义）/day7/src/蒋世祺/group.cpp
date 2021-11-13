#include<bits/stdc++.h>
using namespace std;

const int maxn=2e6+5;
int n,k,head,tail;
int a[maxn],sta[maxn];
long long dp[maxn],sum[maxn];

int main(){
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	head=1,tail=0;
	for(int i=1;i<=k;i++)dp[i]=sum[i];
	for(int i=1;i<=k;i++){
		while(head<=tail&&i-sta[head]>k) head++;
		while(head<=tail&&dp[i-1]-sum[i]>=dp[sta[tail]-1]-sum[sta[tail]]) --tail;
		sta[++tail]=i;
	}
	for(int i=k+1;i<=n;i++){
		while(head<=tail&&i-sta[head]>k) head++;
		dp[i]=dp[sta[head]-1]-sum[sta[head]]+sum[i];
		//printf("%d ",sta[head]);
		while(head<=tail&&dp[i-1]-sum[i]>=dp[sta[tail]-1]-sum[sta[tail]]) --tail;
		sta[++tail]=i;
	}
	printf("%I64d",dp[n]);
}
