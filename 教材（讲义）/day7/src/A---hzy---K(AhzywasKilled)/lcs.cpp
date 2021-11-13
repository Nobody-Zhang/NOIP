#include<cstdio>
using namespace std;
#define ri register int 
typedef long long ll;
const int N = 10007;
int l1,l2,dp[7][N],cur,pre;
char s[N],t[N];
inline int max( int a , int b ){
	return a > b ? a : b;
}
inline int min( int a , int b ){
	return a < b ? a : b;
}
int main()
{
	freopen( "lcs.in" , "r"  , stdin );
	freopen( "lcs.out" , "w" , stdout);
    scanf( "%d %d" , &l1 , &l2 );
    scanf( "%s%s" , s , t );
    dp[ 0 ][ 0 ] = ( s[ 0 ] == t[ 0 ] );
    for( ri i = 1 ; i < l2 ; i++ )
      dp[ 0 ][ i ] = ( s[ 0 ] == t[ i ] ? 1 : dp[ 0 ][ i - 1 ] );
    for( ri i = 1 ; i < l1 ; i++ ){
    	cur = i & 1;
      	pre = ( cur ? 0 : 1 );
      	dp[ cur ][ 0 ] = min( 1 , dp[ pre ][ 0 ] + ( s[ i ] == t[ 0 ] ) );
        for( ri j = 1 ; j < l2 ; j++ ){
      	    dp[ cur ][ j ] = dp[ pre ][ j - 1 ] + ( s[ i ] == t[ j ] );
      	    dp[ cur ][ j ] = max( dp[ cur ][ j ] , dp[ cur ][ j - 1 ] );
      	    dp[ cur ][ j ] = max( dp[ cur ][ j ] , dp[ pre ][ j ] );
        }
    }
    printf( "%d\n" , dp[ cur ][ l2 - 1 ] );
	return 0;
}
