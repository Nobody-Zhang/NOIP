#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 5005 ;
int n, Q, first[MAXN], nexts[MAXN<<1], to[MAXN<<1], egnum, color[MAXN] ;
int f[MAXN][MAXN], g[MAXN][MAXN], size[MAXN] , minn[MAXN] , maxn[MAXN] ;
//f[i][j]: 以i为根的大小为j的联通块中，黑点最少数目
//g[i][j]: 以i为根的大小为j的联通块中，黑点最多数目
//minn[i]: 大小为i的联通块黑点最少数目
//maxn[i]: 大小为i的联通块黑点最多数目

void addEdge(int a,int b){
	nexts[++egnum]=first[a] , first[a]=egnum , to[egnum]=b ;
}

void dfs(int a, int fa){
	size[a]=1 ;
	if(color[a]) f[a][1]=g[a][1]=1 ;
	else f[a][1]=g[a][1]=0 ;
	for(int i=first[a];i;i=nexts[i]){
		int b=to[i] ;
		if(b==fa) continue ;
		dfs(b,a) ;
		int lj = size[a]+size[b] ;
		for(int j=lj ; j>=1 ; --j){
			// j-k <= size[a]
			int lk1=max(1,j-size[a]) , lk2=min(size[b],j-1) ;
			for(int k=lk1 ; k<=lk2 ; ++k){
				f[a][j] = min(f[a][j], f[a][j-k]+f[b][k]) ;
				g[a][j] = max(g[a][j], g[a][j-k]+g[b][k]) ;
			}
		}
		size[a]+=size[b] ;
	}
}

void init(){
	memset(first,0,sizeof(first)) ;
	memset(f,0x3f,sizeof(f)) ;
	memset(g,0,sizeof(g)) ;
	memset(minn,0x3f,sizeof(minn)) ;
	memset(maxn,0,sizeof(maxn)) ;
	egnum=0 ;
	////
}

void solve(){
	freopen("tree.in","r",stdin) ;
	freopen("tree.out","w",stdout) ;
	scanf("%d%d", &n, &Q) ;
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b) ;
		addEdge(a,b), addEdge(b,a) ;
	}
	for(int i=1;i<=n;++i) scanf("%d",&color[i]) ;
	dfs(1,0) ;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			minn[j] = min(minn[j], f[i][j]), maxn[j] = max(maxn[j], g[i][j]) ;
	for(int i=1;i<=Q;++i){
		int x,y;
		scanf("%d%d",&x,&y) ;
		if(y>=minn[x] && y<=maxn[x])
			printf("YES\n") ;
		else printf("NO\n") ;
	}
}

int main(){
	init() ;
	solve() ;
	return 0 ;
}
