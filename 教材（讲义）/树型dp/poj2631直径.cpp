#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

int tp , head[200005] ;
struct Path{
	int pre , to , len ;
	Path( int x = 0 , int y = 0 , int z = 0 ) : pre(x) , to(y) , len(z){} ;
} p[200005] ;


void In( int t1 , int t2 , int t3 ){
	p[++tp] = Path( head[t1] , t2 , t3 ) , head[t1] = tp ;
	p[++tp] = Path( head[t2] , t1 , t3 ) , head[t2] = tp ;
}

void Input_(){
	int u , v , len ;
	while( scanf( "%d%d%d" , &u , &v , &len ) != EOF )
		In( u , v , len ) ;
}

int f[200005] , g[200005] , ans ;
void dfs( int u , int fa ){
	for( int i = head[u] ; i ; i = p[i].pre ){
		int v = p[i].to ;
		if( v == fa ) continue ;
		dfs( v , u ) ;
		if( f[v] + p[i].len >= f[u] )
			g[u] = f[u] , f[u] = f[v] + p[i].len ;
		else if ( f[v] + p[i].len > g[u] ) 
			g[u] = f[v] + p[i].len ;
	} ans = max( ans , f[u] + g[u] ) ;
}

void solve(){
	dfs( 1 , 1 ) ;
	printf( "%d" , ans ) ;
}

int main(){
	Input_() ;
	solve() ;
}
