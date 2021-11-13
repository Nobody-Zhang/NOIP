#include<cstdio>
#include<iostream>
using namespace std;
#define ri register int
const int N = 1000005;
typedef long long ll;
ll n,m,p1,s1,s2,ans;
ll sideA,sideB,minx,ch,a[N];
template<class T>
inline void read(T &res){
    static char ch;T flag = 1;
	while( ( ch = getchar() ) < '0' || ch > '9' ) if( ch == '-' ) flag = -1;
	res = ch - 48;
	while( ( ch = getchar() ) >= '0' && ch <= '9' ) res = res * 10 + ch - 48;
	res *= flag;
}
inline ll abs( ll a ){
	return a >= 0 ? a : -a;
}
int main()
{
	freopen( "fight.in" , "r"  , stdin );
	freopen( "fight.out" , "w" , stdout);
    read( n );
    for( ri i = 1 ; i <= n ; i++ ) read( a[ i ] );
    read( m );read( p1 );read( s1 );read( s2 );a[ p1 ] += s1;
    for( ri i = 1 ; i <= m - 1 ; i++ ) sideA += a[ i ] * ( m - i );
    for( ri i = m + 1 ; i <= n ; i++ ) sideB += a[ i ] * ( i - m );
    ch = sideA - sideB;minx = abs( ch );ans = m;
    for( ri i = 1 ; i <= n ; i++ )
      if( abs( ch + ( m - i ) * s2 ) < minx ){
      	  minx = abs( ch + ( m - i ) * s2 );
      	  ans = i;
      }cout<<ans;
	return 0;
}
