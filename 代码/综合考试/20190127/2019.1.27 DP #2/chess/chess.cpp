#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105;
int n , K;
const int MOD=1000000007 ;
long long m, C[MAXN][MAXN], Coe[MAXN][MAXN] ; //Coe[i][j]表示放置第i列时，C(n,j)的某次幂的值。
long long dp[MAXN][MAXN*MAXN] ;

long long powMod(long long a,long long b){
	long long ret=1 ;
	while(b){
		if(b&1) ret=ret*a%MOD ;
		b>>=1 , a=a*a%MOD ;
	}
	return ret;
}

int main(){
	cin >> n >> m >> K ;
	C[0][0]=1 ;
	for(int i=1;i<=100;++i){
		C[i][0]=C[i][i]=1 ;
		for(int j=1;j<i;++j){
			C[i][j]=C[i-1][j-1]+C[i-1][j] ;
			if(C[i][j]>=MOD) C[i][j]-=MOD ;
		}
	}
	for(int i=1;i<=n;++i){
		long long p=(m-i)/n+1 ;
		for(int j=0;j<=n;++j){
			Coe[i][j]=powMod(C[n][j],p) ;
		}
	}
	dp[0][0]=1 ;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i*n && j<=K;++j){
			int L=min(n,j) ;
			for(int k=0;k<=L;++k){
				dp[i][j]+=dp[i-1][j-k]*Coe[i][k]%MOD ;
				if(dp[i][j]>=MOD) dp[i][j]-=MOD ;
			}
		}
	}
	cout << dp[n][K] << '\n' ;
	return 0 ;
}
