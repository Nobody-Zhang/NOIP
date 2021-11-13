#include<bits/stdc++.h>
using namespace std;

int  d , l , r , ans  ;

int  deal( int  a , int  b , int  p ) 
{
	int  ret = 1 % p ;
	for( ; b ; b = (b >> 1) ) {
		if(b&1) ret=ret*a%p;
		a = a % p * a % p ;
	}
	return ret;
}

int  tool(int x)
{
	int  T = 0 ;
	for( int i = 2 ; i <= sqrt( x ) ; i++ ) 
		if( !( x % i ) ) {
			T += i ;
			while( !( x % i ) ) x /= i ;
		}
	if(x!=1) T+=x; 
	return T;
}

int  find(int x)
{
	int  ans = deal( 2048 , tool( x ) , d );
	return (int )(((ans*ans)%d)*ans)%(int )d;
}

int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	scanf("%d%d%d",&l,&r,&d);
	ans  = find( l ) ;
	for( int  i = l + 1 ; i <= r ; i++ ) ans = ans^find( i ) ;
	cout<<ans ;
}