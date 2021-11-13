#include<stdio.h>
#define N 10000
char s1[N],s2[N];
int dp[2][N],n,m;
inline int max(int x,int y){return x>y? x:y;}
int main(){
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	int cur=0;
	scanf("%d%d",&n,&m);
	scanf("%s%s",s1+1,s2+1);
	for(int i=1;i<=n;i++){
		cur^=1;
		for(int j=1;j<=m;j++){
			int tmp=max(dp[cur^1][j],dp[cur][j-1]);
			dp[cur][j]=tmp;
			if(s1[i]==s2[j])
				dp[cur][j]=max(tmp,dp[cur^1][j-1]+1);
		}
	}
	printf("%d",dp[cur][m]);
}
/*
5 6
abdac
adabac
*/
