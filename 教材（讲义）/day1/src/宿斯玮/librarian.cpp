#include<bits/stdc++.h>
using namespace std;

const  int    N = 10000001 ;

int   n, q ;

int   ans[ N ] ;

void  cut( int  m ){
	int  op = m ;
	int  h = 0 , c = 1 ;
	while( m != 0 ){
		h += c * (m % 10);
		m = m / 10 ; 
		c = c*10 ;
		if( ans[ h ] > op )ans[ h ] = op ;
	}
}

int  main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	for( int  i = 0 ; i <= 10000000 ; i++ )ans[ i ] = 13333335 ;
	scanf("%d%d",&n,&q);
	for( int  i = 1 ; i <= n ; i ++ ){
		int   m  ; 
		scanf("%d",&m);
		cut( m ) ;
	}
	for( int  i = 1 ; i <= q ; i++ ){
		int  k , ii ;
		scanf("%d%d",&ii,&k);
		if( ans[ k ] != 13333335 )printf("%d\n",ans[ k ]);
		else printf("-1\n");
	}
	return 0 ;
}
/*
5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12
 */