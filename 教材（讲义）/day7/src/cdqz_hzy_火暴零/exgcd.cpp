#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll spa,T,a,b,c,x,y,lcm,k,delta_x;
template<class T>inline void read(T &res){
    static char ch;T flag = 1;
	while( ( ch = getchar() ) < '0' || ch > '9' ) if( ch == '-' ) flag = -1;
	res = ch - 48;
	while( ( ch = getchar() ) >= '0' && ch <= '9' ) res = res * 10 + ch - 48;
	res *= flag;
}
ll exgcd( ll &x , ll &y , ll a , ll b ){
	if( b == 0 ){
		x = 1;y = 0;
		return a;
	}
	ll gcd = exgcd( x , y , b , a % b );
	ll c = y;y = x - a / b * y;
	x = c;return gcd;
}
int main()
{
	freopen( "exgcd.in"  , "r" , stdin  );
	freopen( "exgcd.out" , "w" , stdout );
	read( T );
	while( T-- ){
		read( a );read( b );read( c );x = y = 0;
	    spa = exgcd( x , y , a , b );//找到一组特殊解 
        if( c % spa ){
    	    printf( "no\n" );
    	    continue;
        }//不存在解 
        k = c / spa;x *= k;y *= k;
		lcm = a * b / spa;delta_x = lcm / a;
        if( x <= 0 ) cout<<( x + ( -x / delta_x + 1 )*delta_x )<<endl;
        else cout<<( x - ( x / delta_x ) * delta_x )<<endl;
	}
	return 0;
}
