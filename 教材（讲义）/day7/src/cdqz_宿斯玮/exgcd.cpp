#include<bits/stdc++.h>
using namespace std;

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
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	int  k ;
	scanf("%d",&k);
	while( k ){
		k-- ;
		int a , b , c ; 
		scanf ( "%d%d%d" , &a , &b , &c ) ;
		int x , y ; 
		exgcd ( x , a , y , b ) ; 
		y = -y;
		int  kk = c / ( a*x - b*y ) ;
		int  gcd = a*x - b*y ;
		int  lc = a/gcd*b ;
		if( c % ( a*x - b*y ) == 0 ){
			x = x*kk ; y = y*kk ;
			while( x < 0  ){
				y+=lc/b ; x+=lc/a ;
			}
			while( y < 0  ){
				y+=lc/b ; x+=lc/a ;
			}
			while( x - lc/a >0 && y - lc/b >= 0 ){
				x -= lc/a ; y -= lc/b ;
			}
			if( x < 0 || y <0 )printf("no\n");
			else
			printf("%d\n",x);
		}
		
		else printf("no\n"); 	
	}
	return 0 ;
}

