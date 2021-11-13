#include<cstdio>
#include<iostream>
using namespace std;
#define oo 0x3f3f3f3f
#define ri register int
#define iv inline void
typedef long long ll;
ll n,m,a[12],ans = 0,p[12];
template<class T>
inline void read(T &res){
    static char ch;T flag = 1;
	while( ( ch = getchar() ) < '0' || ch > '9' ) if( ch == '-' ) flag = -1;
	res = ch - 48;
	while( ( ch = getchar() ) >= '0' && ch <= '9' ) res = res * 10 + ch - 48;
	res *= flag;
}
inline ll gcd( ll a , ll b ){
	return b == 0 ? a : gcd( b , a % b );
}
void dfs( int beg , int f , int above ){
	if( f == above + 1 ){
		ll exlcm = 1;
		for( ri i = 1 ; i <= above ; i++ ){
			exlcm = p[ i ] * exlcm / gcd( p[ i ] , exlcm );
			if( exlcm > m ) return;
		} 
		if( above % 2 ) ans += m / exlcm;
		else ans -= m / exlcm;
		return;
	}
	for( ri i = beg ; i <= n ; i++ ){
		p[ f ] = a[ i ];//±£´æÅÅÁÐ 
		dfs( i + 1 , f + 1 , above ); 
	}
}
int main()
{
	freopen( "not.in"  , "r" , stdin  );
	freopen( "not.out" , "w" , stdout );
    read( n );read( m );
    for( ri i = 1 ; i <= n ; i++ )
      read( a[ i ] );
    for( ri i = 1 ; i <= n ; i++ )
      dfs( 1 , 1 , i );
    cout<<m - ans;
	return 0;
}
