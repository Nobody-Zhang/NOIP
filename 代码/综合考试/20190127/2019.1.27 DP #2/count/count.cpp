#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long dp[20][175][175][2] ; //长为i，各位数字和为j，数对mod取模后为k，是否压着上界 的个数
int bits[20] , bnum ;

long long solve(long long L){  //1~t
	long long ans=0 ;
	bnum=0 ;
	while(L) bits[++bnum]=L%10 , L/=10 ;
	reverse(bits+1,bits+bnum+1) ;
	int maxn=min(bnum*9,163) ;
	for(int mod=1;mod<=maxn;++mod){
		memset(dp,0,sizeof(dp)) ;
		dp[0][0][0][1]=1 ;
		for(int i=0;i<bnum;++i){
			for(int j=0;j<=mod;++j){
				for(int k=0;k<mod;++k){
					if(dp[i][j][k][0]){
						for(int t=0;t<=9;++t){
							dp[i+1][j+t][(k*10+t)%mod][0]+=dp[i][j][k][0] ;
						}
					}
					if(dp[i][j][k][1]){
						for(int t=0;t<bits[i+1];++t){
							dp[i+1][j+t][(k*10+t)%mod][0]+=dp[i][j][k][1] ;
						}
						dp[i+1][j+bits[i+1]][(k*10+bits[i+1])%mod][1]+=dp[i][j][k][1] ;
					}
				}
			}
		}
		ans+=dp[bnum][mod][0][0]+dp[bnum][mod][0][1] ;
	}
	return ans ;	
}

int main(){
	long long a, b;
	cin >> a >> b ;
	cout << solve(b)-solve(a-1) << '\n' ;
}
