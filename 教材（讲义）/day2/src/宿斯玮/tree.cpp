#include<bits/stdc++.h>
using namespace std ;

const  int  N = 1000005 ;

int  n , w[ N ] , ls[ N ] , rs[ N ] , size[ N ] , maxtot = 0 ; 

inline int read()
{
    int s = 0,w = 1;
    char g = getchar();
    while(g<'0'||g>'9'){if(g=='-')w*=-1;g = getchar();}
    while(g>='0'&&g<='9'){s = s*10+g-'0';g = getchar();}
    return s*w;
}

void dfs( int  u )
{
    size[ u ] = 1 ;
    if (ls[ u ] != -1 ){
        dfs( ls[ u ] ) ;
        size[ u ] += size[ ls[ u ] ] ;
    }
    if (rs[ u ] != -1 ){
        dfs( rs[ u ] ) ;
        size[ u ] += size[ rs[ u ] ];
    }
}

bool  check( int  l , int  r ){
	if( l == -1 && r == -1 )return true ;
	if( l != -1 && r != -1 ){
		if( w[ l ] == w[ r ] )
			if( check( ls[ l ] , rs[ r ] )  && check( ls[ r ] , rs[ l ] ) )
				return true ;
	}
	return false ;
}

int  main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n = read() ;
	for( int  i = 1 ; i <= n ; i++ )w[ i ] = read() ;
	for( int  i = 1 ; i <= n ; i++ ){
		ls[ i ] = read() ; rs[ i ] = read() ;
	}

	dfs( 1 ) ;

    for( int  i = 1 ; i <= n ; i ++ )
        if( check( ls[i] , rs[i] ) ) maxtot = max( size[ i ] , maxtot ) ;
    printf("%d",maxtot);
	return 0 ;
}