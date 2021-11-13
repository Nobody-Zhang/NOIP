#include <cstdio>
int exgcd ( int &x , int a , int &y , int b ) 
{
	if ( b == 0 ) { x = 1 ; y = 0 ; return a ; }
	int xx , yy ; 
	int gc = exgcd ( xx , b , yy , a % b ) ;
	x = yy ; 
	y = xx - a / b * yy ; 
	return gc ; 
}
 
int main ( )
{
	int a , b ; 
	scanf ( "%d%d" , &a , &b ) ;
	int x , y ; 
	exgcd ( x , a , y , b ) ; 
	printf ( "%d %d" , x , y ) ; 
}

