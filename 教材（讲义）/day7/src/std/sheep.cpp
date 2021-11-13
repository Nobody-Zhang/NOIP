#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100055 ;
int n, m, jmp[MAXN] ;
double dp[MAXN] ;

void init(){
	memset(jmp,0,sizeof(jmp)) ;
	memset(dp,0,sizeof(dp)) ;
}

void solve(){
	scanf("%d%d",&n,&m) ;
	for(int i=1;i<=m;++i){
		int a,b;
		scanf("%d%d",&a,&b) ;
		jmp[a]=b ;
	}
	for(int i=n-1;i>=0;--i){
		dp[i]=0 ;
		if(!jmp[i]) for(int j=1;j<=6;++j)
			dp[i]+=(dp[i+j]+1)/6 ;
		else dp[i]=dp[jmp[i]] ;
	}
	printf("%.2f\n",dp[0]) ;
}

int main(){
	freopen("sheep.in","r",stdin) ;
	freopen("sheep.out","w",stdout) ;
	int T;
	scanf("%d",&T) ;
	while(T--){
		init() ;
		solve() ;
	}
	return 0 ;
}
