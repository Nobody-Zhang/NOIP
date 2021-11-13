#include <map>
#include <cmath>
using namespace std ; 

int fp ( long long x , long long k , int mod )
{
	x = x % mod ; 
	long long ans = 1 ; 
	while ( k ) 
	{
		if ( k % 2 ) ans = ans * x % mod ; 
		x = x * x % mod ; 
		k = k / 2 ; 
	}
	return ans ; 
}

int exgcd ( int &x , int a , int &y , int b ) 
{
	if ( b == 0 ) { x = 1 ; y = 0 ; return a ; }
	int xx , yy ; 
	int gc = gcd ( xx , b , yy , a % b ) ;
	x = yy ;  
	y = xx - a / b * yy ; 
} 

map < int , int > mp ;
int BSGS ( int a , int b , int p ) 
{
	mp.clear ( ) ;
	int sz = sqrt ( p ) ; int pz = 1 ;  
	for ( int i = 1 ; i <= sz ; i++ ) pz = 1ll * pz * a % p , mp[pz] = i ;  
	for ( int i = 0 ; i <= sz ; i++ ) 
	{
		int a_isz = fp ( x , i * sz , p ) ; 
		int m , n ; 
		exgcd ( m , a_isz , n , p ) ; 
		m = ( m * b % p + p ) % p ;
		if ( mp[m] ) return i * sz + mp[m] ;   
	} 
	return 0 ; 
} 
