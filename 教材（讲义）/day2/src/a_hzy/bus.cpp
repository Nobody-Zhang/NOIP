#include<cstdio>
#include<algorithm>
using namespace std;
#define oo 0x3f3f3f3f
#define ri register int
#define iv inline void
typedef long long ll;
const int N = 507;
int n,T,a[N],have[N][N];
template<class T>
inline void read(T &res){
    static char ch;T flag = 1;
	while( ( ch = getchar() ) < '0' || ch > '9' ) if( ch == '-' ) flag = -1;
	res = ch - 48;
	while( ( ch = getchar() ) >= '0' && ch <= '9' ) res = res * 10 + ch - 48;
	res *= flag;
}
ll dfs( int p , int timer , ll ans ){//第p个人还在等，准备发车的时间，答案 
	if( p == n + 1 ) return ans;//人走完了 
	if( timer < a[ p ] ) timer = a[ p ];//至少载一个人 
	if( have[ p ][ timer - a[ p ] ] ) return have[ p ][ timer - a[ p ] ];
	//记忆化剪枝 
	int q = p,res = 0;
	while( a[ q ] <= timer && q <= n ){
		res += a[ q ];
		q++;
	}//此时的q指向第一个时间大于发车时间的人 
	ans = ( q - p ) * timer - res + dfs( q , timer + T , 0 );
	//第一种方案，把能接的人接完 
	for( ri i = q ; i <= n ; i++ ){//其他方案，等后面的人一起  
	    res += a[ i ];
		ans = min( ans , ( i - p + 1 ) * a[ i ] - res + dfs( i + 1  , a[ i ] + T , 0 ) ); 
	}
	have[ p ][ timer - a[ p ] ] = ans; 
	return ans;
}
int main()
{
	freopen( "bus.in" , "r"  , stdin );
	freopen( "bus.out" , "w" , stdout);
    read( n );read( T );
    for( ri i = 1 ; i <= n ; i++ )
      read( a[ i ] );
    if( T <= 1 ){//特判 
    	printf( "0\n" );
    	return 0;
    }
    sort( a + 1 , a + n + 1 );
    printf( "%d\n" , dfs( 1 , 0 , 0 ) );
	return 0;
}
