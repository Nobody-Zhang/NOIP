#include<cstdio>
using namespace std;
#define ri register int
#define BASE1 9999991
#define BASE2 10007 
const int N = 1000007;
typedef long long ll;
int n,a[N],ans = 1;
struct Tree{
	Tree *ls,*rs,*fa;
	int size,v;
	unsigned long long hashl,hashr;//保存以这个点为根的所有子树的信息 
	Tree(){
		ls = rs = fa = NULL;
		size = v = 0;
	}
}tree[N],*root;

template<class T>
inline void read(T &res){
    static char ch;T flag = 1;
	while( ( ch = getchar() ) < '0' || ch > '9' ) if( ch == '-' ) flag = -1;
	res = ch - 48;
	while( ( ch = getchar() ) >= '0' && ch <= '9' ) res = res * 10 + ch - 48;
	res *= flag;
}

inline int max( int a , int b ){
	return a > b ? a : b;
}

void dfs( Tree *node ){
	node->size = 1;
	if( node->ls != NULL ){
		dfs( node->ls );
		node->size += node->ls->size;
	}
	if( node->rs != NULL ){
	    dfs( node->rs );
	    node->size += node->rs->size;
	}
	if( node->ls != NULL && node->rs != NULL && node->ls->hashl == node->rs->hashr )
	  ans = max( ans , node->size );
	int ll,lr,rl,rr,mid = node->v,a[4],b[4];
	if( node->ls == NULL ) ll = lr = 1000000007;
	else{
	    ll = node->ls->hashl;
		lr = node->ls->hashr;
	}
	if( node->rs == NULL ) rl = rr = 1000000007;
	else{
	    rl = node->rs->hashl;
		rr = node->rs->hashr;
	}a[ 2 ] = b[ 2 ] = mid;a[ 1 ] = ll;a[ 3 ] = rl;b[ 1 ] = rr;b[ 3 ] = lr;
	//hashl为左中右，hashr为右中左，即将其按从左到右和从右到左的顺序保存 
	//必须同时维护两个hash才能保证能顺利递归 
	for( int k = 1 ; k <= 3 ; k++ ){
		node->hashl = ( node->hashl * BASE2 + a[ k ] ) * BASE1;
		node->hashr = ( node->hashr * BASE2 + b[ k ] ) * BASE1;
	}
}

int main()
{
	freopen( "tree.in" , "r"  , stdin );
	freopen( "tree.out" , "w" , stdout);
    read( n );
    for( ri i = 1 ; i <= n ; i++ ) read( tree[ i ].v );
    for( ri i = 1 ; i <= n ; i++ ){
    	int l,r;
		read( l );read( r );
    	if( l != -1 ){
    	    tree[ i ].ls = &tree[ l ];
    	    tree[ l ].fa = &tree[ i ];
    	}
    	if( r != -1 ){
    	    tree[ i ].rs = &tree[ r ];
    	    tree[ r ].fa = &tree[ i ];
    	}
    }
    for( ri i = 1 ; i <= n ; i++ )
      if( tree[ i ].fa == NULL ){
          root = &tree[ i ];
          break; 
      }
    dfs( root );
    printf( "%d\n" , ans );
	return 0;
}
