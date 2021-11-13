#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 100005 ;
int n , A[MAXN], B[MAXN] , T[MAXN] , f[MAXN] ;

int main(){
	freopen("match.in","r",stdin) ;
	freopen("match.out","w",stdout) ;
	scanf("%d",&n) ;
	for(int i=1;i<=n;++i) scanf("%d",&A[i]) , T[A[i]] = i ;
	for(int i=1;i<=n;++i) scanf("%d",&B[i]) , B[i] = T[B[i]] ;
	memset(f,0x3f,sizeof(f)) ;
	for(int i=1;i<=n;++i){
		int *p = lower_bound(f+1,f+n+1,B[i]) ;
		(*p) = B[i] ;
	}
	int ans=0 ;
	for(int i=1;i<=n;++i) if(f[i]!=f[0]) ans=i;
	printf("%d\n",ans) ;
	return 0 ;
}
