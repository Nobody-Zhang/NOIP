#include<bits/stdc++.h>
using namespace std;
const  int  N =  100000 + 17 ;
inline int read()
{
    int s = 0,w = 1;
    char g = getchar();
    while(g<'0'||g>'9'){if(g=='-')w*=-1;g = getchar();}
    while(g>='0'&&g<='9'){s = s*10+g-'0';g = getchar();}
    return s*w;
}

int  n ;
double  a[ N ] , f[ N ] , f2[N], d[ N ] ,ans  ;
int  main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	n = read() ,a[0] = 0,d[ 0 ] = 0 ,f[ 0 ] = 0 ;
	for( int  i = 1 ; i <= n ; i++ )scanf("%lf",&a[ i ]) ;
	for( int  i = 1 ; i <= n ; i++ )d[ i ] = a[ i ] * ( (double) d[ i - 1 ] + 1.0 ) ;
	for( int  i = 1 ; i <= n ; i++ )f2[ i ] = a[ i ]*( f2[ i - 1 ] + 2 *d[ i - 1 ] + 1 ) ;
	for( int  i = 1 ; i <= n ; i++ )f[ i ] =  (double)a[ i ]*( 3.0*f2[ i - 1 ] + 3.0*d[ i -1 ] + 1 ) ;
	for( int  i = 1 ; i <= n ; i++  )ans += f[ i ] ;
	printf("%0.1lf",ans);
	return  0 ;
}