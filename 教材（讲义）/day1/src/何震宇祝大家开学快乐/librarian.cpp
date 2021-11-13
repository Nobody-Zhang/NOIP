#include<algorithm>
#include<cstdio>
using namespace std;
#define ri register int
const int N = 1005;
int n,q,a[N],ch[N][20];
template<class T>
inline void read(T &res){
    static char ch;T flag = 1;
	while( ( ch = getchar() ) < '0' || ch > '9' ) 
	  if( ch == '-' ) flag = -1;
	res = ch - 48;
	while( ( ch = getchar() ) >= '0' && ch <= '9' )
	  res = res * 10 + ch - 48;
	res *= flag;
}
inline bool match( int x , int k ){
	int l = 0;int xxx[20];
	if( x > a[ k ] ) return false;
	while( x ){xxx[ l++ ] = x % 10;x /= 10;}
	for( ri i = 0 ; i <= l - 1 ; i++ )
	  if( xxx[ i ] != ch[ k ][ i ] )
	    return false;
	return true;
}//Æ¥Åä 
int main()
{
	freopen( "librarian.in" , "r"  , stdin );
	freopen( "librarian.out" , "w" , stdout );
    read( n );read( q );
    for( ri i = 1 ; i <= n ; i++ ) read( a[ i ] );
    sort( a + 1 , a + n + 1 );//ÏÈÅÅÐò£¬ÓÅ»¯ 
    for( ri i = 1 ; i <= n ; i++ ){
    	int k = a[ i ],j = 0;
    	while( k ){ch[ i ][ j++ ] = k % 10;k /= 10;}
    }//µ¹Ðò´æ´¢ 
    while( q-- ){
    	int l,x,ans = -1;read( l );read( x );
        for( ri i = 1 ; i <= n ; i++ )
		  if( match( x , i ) ){ans = a[ i ];break;}
		printf( "%d\n" , ans );
    }//ÕÒµ½´ð°¸ 
	return 0;
}
