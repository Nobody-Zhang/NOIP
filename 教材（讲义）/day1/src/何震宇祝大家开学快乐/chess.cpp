#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define oo 0x3f3f3f3f
#define ri register int
const int N = 105;
typedef long long ll;
int m,n,g[N][N],a[N][N];
int wx[4] = { 0 , 0 , -1 , 1 },wy[4] = { 1 , -1 , 0 , 0 };
bool v[N][N];
queue<int> q1,q2,q3;

template<class T>
inline void read(T &res){
    static char ch;T flag = 1;
	while( ( ch = getchar() ) < '0' || ch > '9' ) if( ch == '-' ) flag = -1;
	res = ch - 48;
	while( ( ch = getchar() ) >= '0' && ch <= '9' ) res = res * 10 + ch - 48;
	res *= flag;
}

int main()
{
//	freopen( "chess.in" , "r"  , stdin );
//	freopen( "chess.out" , "w" , stdout);
    read( m );read( n );
	memset( g , -1 , sizeof( g ) );memset( a , oo , sizeof( a ) );
    for( ri i = 1 ; i <= n ; i++ ){
    	int x,y,col;read( x );read( y );read( col );
    	g[ x ][ y ] = col;
    }a[ 1 ][ 1 ] = 0;
    q1.push( 1 );q2.push( 1 );q3.push( g[ 1 ][ 1 ] );v[ 1 ][ 1 ] = true;
    while( !q1.empty() ){
    	int x = q1.front(),y = q2.front(),col = q3.front();
        q1.pop();q2.pop();q3.pop();
        for( int i = 0 ; i <= 3 ; i++ ){
        	int x1 = x + wx[ i ],y1 = y + wy[ i ];
        	if( x1 < 1 || x1 > n || y1 < 1 || y1 > n ) continue;
        	if( g[ x1 ][ y1 ] == -1 && g[ x ][ y ] == -1 ) continue;//不能 
        	if( g[ x1 ][ y1 ] == -1 && a[ x1 ][ y1 ] > a[ x ][ y ] + 2 ){
        		if( !v[ x1 ][ y1 ] ){
        		    q1.push( x1 );q2.push( y1 );q3.push( col );
        	  	    v[ x1 ][ y1 ] = true;
        		}
        	  	a[ x1 ][ y1 ] = a[ x ][ y ] + 2;
        	}//下一个无色 
        	else if( col == g[ x1 ][ y1 ] && a[ x1 ][ y1 ] > a[ x ][ y ] ){
        		if( !v[ x1 ][ y1 ] ){
        		    q1.push( x1 );q2.push( y1 );q3.push( g[ x1 ][ y1 ] );
        	  	    v[ x1 ][ y1 ] = true;
        		}
        		a[ x1 ][ y1 ] = a[ x ][ y ];
        	}//同色
        	else if( col != g[ x1 ][ y1 ] && a[ x1 ][ y1 ] > a[ x ][ y ] + 1 ){
        		if( !v[ x1 ][ y1 ] ){
        		    q1.push( x1 );q2.push( y1 );q3.push( g[ x1 ][ y1 ] );
        	  	    v[ x1 ][ y1 ] = true;
        		}
        		a[ x1 ][ y1 ] = a[ x ][ y ] + 1;
        	}//异色 
        }
    }
    printf( "%d\n" , a[ m ][ m ] == oo ? -1 : a[ m ][ m ] );
	return 0;
}
