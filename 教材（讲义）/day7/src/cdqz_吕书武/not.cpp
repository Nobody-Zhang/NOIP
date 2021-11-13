#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;
#define N 11
int ans=0,n,m,dp[N],num=0;
ll q[N],a[N];
inline void dfs(int step,int cnt,int u,ll sum){
	if(sum>m) return;
	if(cnt==u){
		dp[u]+=m/sum;
		return;
	}
	for(int i=step+1;i<=num;i++)
		dfs(i,cnt+1,u,sum*q[i]);
}
int main(){
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		bool flag=false;
		for(int j=num;j>=1;j--)
			if(a[i]%a[j]==0){
				flag=true;
				break;
			}
		if(flag) continue;
		q[++num]=a[i];
	}
	for(int i=1;i<=num;i++)
		dfs(0,0,i,1);
	for(int i=1;i<=num;i++)
		if(i&1) ans+=dp[i];
		else ans-=dp[i];
	printf("%d",m-ans);
}
