#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mid ((ll+rr)>>1)
using namespace std;

const int MAXN = 100005, MOD=1000000007 ;
int n, m;
long long A[MAXN] ;

int main(){
	scanf("%d%d",&n,&m) ;
	for(int i=1;i<=n;++i) scanf("%lld",&A[i]) ;
	for(int i=1;i<=m;++i){
		int op, x, y, z ;
		scanf("%d%d%d",&op,&x,&y) ;
		if(op==1){
			scanf("%d",&z) ;
			for(int i=x;i<=y;++i) A[i]=(A[i]+z)%MOD ;
		}
		else if(op==2){
			scanf("%d",&z) ;
			for(int i=x;i<=y;++i) A[i]=(A[i]*z)%MOD ;
		}
		else if(op==3){
			long long ans=0 ;
			for(int i=x;i<=y;++i){
				ans += A[i]*A[i]%MOD ;
				ans %= MOD ;
			}
			cout << ans << '\n' ;
		}
	}
	return 0 ;
}
