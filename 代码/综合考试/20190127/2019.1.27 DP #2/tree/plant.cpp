#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 13, MAXM = 5005, MOD = 100000000 ;
int n, m, dp[MAXN][MAXM], A[MAXN] ;

inline bool check(const int &x){ return (x&(x<<1))==0 ; }

inline bool check(const int &a, const int &b){ return check(a) && check(b) && ((a&b)==0) ; }

inline void getMod(int &x){ if(x>=MOD) x-=MOD ; }

inline bool getNext(int &x, const int &S) { 
	x = (x-1) & S ;
	return true ;
}

int main(){
	scanf("%d%d",&n,&m) ;
	int tmp ;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
			scanf("%d",&tmp) , A[i] |= (tmp<<(j-1)) ;
	int M = (1<<m)-1 ;
	for(int sta=A[1]; sta ; sta=(sta-1)&A[1] ){
		if(check(sta)) dp[1][sta]=1 ;
	}
	dp[1][0]=1 ;
	for(int i=2; i<=n; ++i){
		int sta = A[i] ;
		do{
			int sta2 = A[i-1] ;
			do{
				if(check(sta, sta2)) dp[i][sta] += dp[i-1][sta2] ;
				getMod(dp[i][sta]) ;
			}while(sta2 && getNext(sta2, A[i-1])) ;
		}while(sta && getNext(sta, A[i])) ;
	}
	int ans=0;
	for(int j=0; j<=M ; ++j)
		ans += dp[n][j] , getMod(ans) ;
	printf("%d\n",ans) ;
	return 0 ;
}
