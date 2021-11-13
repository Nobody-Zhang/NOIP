#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

int N , M , scc[105] , scc_cnt , f[105][505] ;
bool connec[105][105] ; // 是否已经建边
struct Data{
	int siz , val , f ;
}ori[105] , ops[105] ; // ori为原物品 , ops为缩点后物品

int tp , head[105] , deg[105] ;
struct Path{
	int pre , to ;
	Path( int x = 0 , int y = 0 ) : pre(x) , to(y) {} ;
}p[505] ;

void In( int t1 , int t2 ){
	p[++tp] = Path( head[t1] , t2 ) , head[t1] = tp ;
}

int dfn[105] , dfs_c , sta[105] , topp ;
int dfs( int u ){
	int lowu = dfn[u] = ++dfs_c ;
	sta[++topp] = u ;
	for( int i = head[u] ; i ; i = p[i].pre ){
		int v = p[i].to ;
		if( !dfn[v] ) lowu = min( lowu , dfs( v ) ) ;
		else if( !scc[v] ) lowu = min( lowu , dfn[v] ) ;
	}
	if( lowu == dfn[u] ){
		scc_cnt ++ ;
		while( 1 ){
			int x = sta[topp--] ;
			scc[x] = scc_cnt ;
			ops[scc_cnt].siz += ori[x].siz ;
			ops[scc_cnt].val += ori[x].val ;
			if( x == u ) break ;
		}
	}
	return lowu ;
}

void tarjan(){
	for( int i = 1 ; i <= N ; i ++ )
		if( !dfn[i] ) dfs( i ) ;
}

void reBuild(){
	tp = 0 ;
	memset( head , 0 , sizeof( head ) ) ;
	for( int i = 1 ; i <= N ; i ++ ){
		int u = scc[ ori[i].f ] , v = scc[i] ;
		if( u != v && !connec[u][v] ){
			In( u , v ) ; deg[v] ++ ; // 存新点的入度
			connec[u][v] = true ;
		}
	}
	for( int i = 1 ; i <= scc_cnt ; i ++ )
		if( !deg[i] ) In( 0 , i ) ; // 添加超级源点 0
}

void dpDfs( int u ){
	for( int i = M ; i >= ops[u].siz ; i -- )
		f[u][i] = ops[u].val ;
	for( int i = head[u] ; i ; i = p[i].pre ){
		int v = p[i].to ;
		dpDfs( v ) ;
		for( int j = M ; j >= ops[u].siz ; j -- )
			for( int k = 0 ; k <= j - ops[u].siz ; k ++ )
				f[u][j] = max( f[u][j] , f[u][j-k] + f[v][k] ) ;
	}
}

int main(){
	scanf( "%d%d" , &N , &M ) ;
	for( int i = 1 ; i <= N ; i ++ )
		scanf( "%d" , &ori[i].siz ) ;
	for( int i = 1 ; i <= N ; i ++ )
		scanf( "%d" , &ori[i].val ) ;
	for( int i = 1 ; i <= N ; i ++ )
		scanf( "%d" , &ori[i].f ) , In( ori[i].f , i ) ;
	tarjan() ;
	reBuild() ;
	dpDfs( 0 ) ;
	printf( "%d" , f[0][M] ) ;
}
