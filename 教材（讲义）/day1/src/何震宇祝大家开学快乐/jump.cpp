#include<cstdio>
#include<cstring>
using namespace std;
#define oo 1125899906842624
#define ri register int
const int N = 500005;
typedef long long ll;
int n,d,k,dis[N],w[N],q[N];
ll dp[N];
inline ll max( ll a , ll b ){return a > b ? a : b; }
template<class T>
inline void read(T &res){
    static char ch;T flag = 1;
	while( ( ch = getchar() ) < '0' || ch > '9' ) if( ch == '-' ) flag = -1;
	res = ch - 48;
	while( ( ch = getchar() ) >= '0' && ch <= '9' ) res = res * 10 + ch - 48;
	res *= flag;
}
inline bool check( int g ){
	for( ri i = 0 ; i <= n + 10 ; i++ ) dp[ i ] = -oo,q[ i ] = 0;//初始化不能是0 
	dp[ 0 ] = 0;
	int L = max( 1 , d - g ),R = d + g,len;ll ans = 0;
	int head = 1,tail = 0,cur = 0;
	for( ri i = 1 ; i <= n ; i++ ){
		while( dis[ i ] - dis[ cur ] >= L ){
		    while( head <= tail && dp[ cur ] >= dp[ q[ tail ] ] ) tail--;
		    q[ ++tail ] = cur++;
		}
		while( head <= tail && dis[ i ] - dis[ q[ head ] ] > R ) head++;
		if( head <= tail )
		  dp[ i ] = dp[ q[ head ] ] + w[ i ];
		if( dp[ i ] >= k ) return true;
	}
	return false;
}
int main()
{
	freopen( "jump.in" , "r"  , stdin  );
	freopen( "jump.out" , "w" , stdout );
    read( n );read( d );read( k );
    for( ri i = 1 ; i <= n ; i++ ){read( dis[ i ] );read( w[ i ] );}
    int l = 0,r = dis[ n ];
    while( l <= r ){
    	int mid = ( l + r ) >> 1;
    	if( check( mid ) ) r = mid - 1;
    	else l = mid + 1;
    }
    printf( "%d\n" , l <= dis[ n ] ? l : -1 );
	return 0;
}
