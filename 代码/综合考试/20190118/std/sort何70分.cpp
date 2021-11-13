#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,cnt = 1;
int ans[ 35 ];
void print( int c ){
	for( register int j = 1 ; j <= c - 1 ; j++ ) 
	  printf( "%d " , ans[ j ] );
	printf( "%d" , ans[ c ] );
	exit( 0 );
}
void dfs( int c , int last ){
	for( register int i = last + 1 ; i <= n ; i++ ){
		ans[ c ] = i;
		if( ++cnt == k ) print( c );
		dfs( c + 1 , i );
	}
}
int main()
{
	freopen( "sort.in" , "r" , stdin );
	freopen( "sort.out" , "w" , stdout);
    scanf( "%d%d" , &n , &k );
    if( k == 1 ){cout<<0;return 0;}
    if( k == ( 1 << n ) ){cout<<n;return 0;}
    dfs( 1 , 0 );
	return 0;
}
