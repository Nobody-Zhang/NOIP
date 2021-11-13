#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

int N , tp , head[20005] , val[20005] ;
struct Path{
	int pre , to ;
	Path( int x = 0 , int y = 0 ) : pre(x) , to(y) {} ;
} p[40005] ;

void In( int t1 , int t2 ){
	p[++tp] = Path( head[t1] , t2 ) , head[t1] = tp ;
	p[++tp] = Path( head[t2] , t1 ) , head[t2] = tp ;
}

long long ans = - ( 1LL << 60 ) , f[20005] ;
void dfs( int u , int fa ){
	f[u] = val[u] ;
	for( int i = head[u] ; i ; i = p[i].pre ){
		int v = p[i].to ;
		if( v == fa ) continue ;
		dfs( v , u ) ;
		f[u] += f[v] ;
	} f[u] = max( f[u] , 0LL ) ;
	ans = max( f[u] , ans ) ;
}

void solve(){
	dfs( 1 , 1 ) ;
	printf( "%lld" , ans ) ;
}

int main(){
	scanf( "%d" , &N ) ;
	for( int i = 1 ; i <= N ; i ++ )
		scanf( "%d" , &val[i] ) ;
	for( int i = 1 , u , v ; i < N ; i ++ ){
		scanf( "%d%d" , &u , &v ) ;
		In( u , v ) ;
	} solve() ;
}
