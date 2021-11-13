#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=7005 ;
int n, m;
int dp[2][MAXN] ;
char s1[MAXN], s2[MAXN] ;
int main(){
	scanf("%d%d%s%s",&n,&m,s1+1,s2+1) ;
	for(int i=1;i<=n;++i){
		int now=i&1, pre=now^1 ;
		for(int j=1;j<=m;++j){
			if(s1[i]==s2[j]) dp[now][j]=dp[pre][j-1]+1 ;
			else{
				dp[now][j]=max(dp[pre][j],dp[now][j-1]) ;
			}
		}
	}
	printf("%d\n",dp[n&1][m]) ;
	return 0 ;
}
