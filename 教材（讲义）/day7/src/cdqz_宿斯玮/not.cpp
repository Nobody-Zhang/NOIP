#include<bits/stdc++.h>
using namespace std;

int   m , n ;

int  ans[ 1000001  ] , tot = 0 , k[ 11 ];

int  a[ 11 ] ;

inline int read()
{
    int s = 0,w = 1;
    char g = getchar();
    while(g<'0'||g>'9'){if(g=='-')w*=-1;g = getchar();}
    while(g>='0'&&g<='9'){s = s*10+g-'0';g = getchar();}
    return s*w;
}

void  ak1(){
	for( int  i = 1 ; i <= m ; i++){
		int  key = 1 ;
		for( int  j = 1 ; j <= n ; j ++ )
			if( i % a[ j ] == 0 ){
				key = 0 ;
				break;
			}
		if( key == 1 )
			tot++ ; 
	}
}

void  ak345(){
	int  k1 = m / a[ 1 ] ;
	int  k2 = m / a[ 2 ] ;
	int  ku = m /(a[ 1 ]*a[ 2 ]) ;
	tot = m - k1 - k2 + ku ;
}

void  ak0(){
	int  k1 = m / a[ 1 ] ;
	int  k2 = m / a[ 2 ] ;
	int  k3 = m / a[ 3 ] ;
	int  k12 = m /(a[ 1 ]*a[ 2 ]) ;
	int  k23 = m /(a[ 2 ]*a[ 3 ]) ;
	int  k13 = m /(a[ 1 ]*a[ 3 ]) ;
	int  k123 = m /(a[ 1 ]*a[ 2 ]*a[ 3 ]) ;
	tot = m - k1 - k2 - k3 + k12 + k23 + k13 - k123 ;  
}

int  main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	n = read() ; m = read() ;
	for( int  i = 1 ; i <= n; i++ )a[ i ] = read() ;
	if( m <= 1e6 ){
		ak1() ;
		printf("%d",tot) ;
		return 0 ;
	}
	if( n == 1 ){
		int  k1 = m / a[ 1 ] ;
		printf("%d", m -  k1 ) ;
		return 0 ;
	}
	if( n == 2 ){
		ak345();
		cout<<tot ;
		return 0 ;
	}
	if( n == 3 ){
		ak0() ;
		cout<<tot ;
		return 0 ; 
	}
	if( n > 3 ){
		for( int  i = 1 ; i <= n ; i++ )k[ i ] = m/a[ 1 ] ;
		for( int  i = 1 ; i <= n ; i++ ){
			if( i % 3 == 0 )
				tot += k[ i ] ;
			else tot -= k[ i ] ;
		}
		int  op = max( m - tot , 1 ) ;
		cout<< op ;
	}
    return 0 ;
}