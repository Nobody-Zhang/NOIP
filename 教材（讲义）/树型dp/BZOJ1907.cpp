#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

int T , N , tp , head[10005] , f[10005][2] ;
struct Path{
    int pre , to ;
	Path( int x = 0 , int y = 0 ) : pre(x) , to(y) {} ;
}p[20005] ;

void clear(){
    tp = 0 ;
    memset( head + 1 , 0 , N * sizeof( int ) ) ;
}

void In( int t1 , int t2 ){
	p[++tp] = Path( head[t1] , t2 ) , head[t1] = tp ;
	p[++tp] = Path( head[t2] , t1 ) , head[t2] = tp ;
}

void dfs( int u , int fa ){
	f[u][0] = f[u][1] = 1 ;
	int tmp = 0 ;
	for( int i = head[u] ; i ; i = p[i].pre ){
		int v = p[i].to ;
		if( v == fa ) continue ;
		dfs( v , u ) ;
		f[u][1] = min( f[u][1] + f[v][1] , f[u][0] + f[v][0] - 1 ) ;
		f[u][0] = min( f[u][0] + min( f[v][1] , f[v][0] ) , tmp + f[v][0] ) ;
		tmp += f[v][1] ;
	}
}

int main(){
    scanf( "%d" , &T ) ;
    while( T -- ){
        scanf( "%d" , &N ) ;
        clear() ;
        for( int i = 1 , u , v ; i < N ; i ++ ){
            scanf( "%d%d" , &u , &v ) ;
            In( u , v ) ;
        }
        dfs( 1 , 1 ) ;
        printf( "%d\n" , min( f[1][0] , f[1][1] ) ) ;
    }
}
