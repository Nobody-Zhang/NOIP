#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#ifdef WIN32
#define myLL "%I64d"
#else
#define myLL "%lld"
#endif
using namespace std;

const int MAXN=2000005 ;
int n, K, A[MAXN], head, tail, que[MAXN] ;
long long sum[MAXN], dp[MAXN], f[MAXN] ;
//dp[i] = dp[j-1]+sum[i]-sum[j]

int reads(){
	int x=0 ;
	char c=getchar() ;
	while(c<'0'||c>'9') c=getchar() ;
	while(c>='0'&&c<='9') { x=x*10+c-'0', c=getchar() ; }
	return x;
}

int main(){
	freopen("group.in","r",stdin) ;
	freopen("group.out","w",stdout) ;
	n=reads(), K=reads() ;
	for(int i=1;i<=n;++i){
		A[i]=reads(), sum[i]=sum[i-1]+A[i] ;
	}
	que[tail++]=0 ;
	for(int i=1;i<=n;++i){
		while(head<tail && i-que[head]>K) head++ ;
		dp[i] = f[que[head]] + sum[i] ;
		f[i+1] = dp[i]-sum[i+1] ;
		while(head<tail && f[que[tail-1]]<f[i+1]) tail-- ;
		que[tail++]=i+1 ;
	}
	printf(myLL"\n",dp[n]) ;
	return 0 ;
}
