#include<stdio.h>
#define N 2000007
#define ll long long

int n,k,head=1,tail=0,Q[N];
ll a,sum[N],dp[N];
template<class T>
inline void read(T &x){
	x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-48;c=getchar();}
}
template <class T>
inline T maxx(T x,T y){return x>y? x:y;}
int main(){
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	read(n);read(k);
	for(int i=1;i<=n;i++){
		read(a);
		sum[i]=sum[i-1]+a;
	}
	ll rest;
	for(int i=1;i<=n;i++){
		rest=0;
		while(head<=tail&&Q[head]<i-k) head++;
		rest=dp[i-1]-sum[i];
		while(head<=tail&&rest>dp[Q[tail]-1]-sum[Q[tail]]) tail--;
		Q[++tail]=i;
		if(i<=k) dp[i]=sum[i];
		else{
			rest=dp[Q[head]-1]-sum[Q[head]];
			dp[i]=sum[i]+rest;
		}
	}
	printf("%I64d",dp[n]);
}
/*
4 1
27944 2642 19584 23523 
*/
