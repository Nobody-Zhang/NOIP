#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1005 ;
int n, K, dp[MAXN][MAXN] ; //dp[i][j]表示以i为根，联通块大小为j时最少删边数
int first[MAXN] , nexts[MAXN<<1] , to[MAXN<<1] , egnum , size[MAXN] ;

void addEdge(int a,int b){
	nexts[++egnum] = first[a] ;
	first[a] = egnum ;
	to[egnum]=b;
}

void dfs(int a,int fa){
	int cnt=0 ;
	size[a]=1 ;
	for(int i=first[a];i;i=nexts[i]) if(to[i]!=fa) ++cnt ;
	dp[a][1] = cnt ;
	for(int i=first[a];i;i=nexts[i]){
		int b=to[i];
		if(b==fa) continue ;
		dfs(b,a) ;
		int lj = min(K, size[a]+size[b]) ;
		for(int j=lj; j>=1; --j){
			int lk1 = max(1, j-size[a]) , lk2 = min(K, size[b]) ;
			for(int k=lk1; k<=lk2; ++k){
				dp[a][j] = min(dp[a][j-k]+dp[b][k]-1, dp[a][j]) ;
			}
		}
		size[a] += size[b] ;
	}
}

int main(){
	scanf("%d%d",&n, &K) ;
	for(int i=1;i<n;++i){
		int a, b;
		scanf("%d%d",&a,&b) ;
		addEdge(a,b) , addEdge(b,a) ;
	}
	memset(dp,0x3f,sizeof(dp)) ;
	dfs(1,0) ;
	int ans = dp[1][K] ;
	for(int i=2;i<=n;++i) ans = min(ans, dp[i][K]+1) ;
	printf("%d\n",ans) ;
	return 0 ;
}
