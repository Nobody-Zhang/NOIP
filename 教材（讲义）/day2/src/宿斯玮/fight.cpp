#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll  n , s[ 100005 ] , m   , p1 ;

ll  tot1 , tot2 , s2 , s1;


int  main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
    cin>>n  ;
    for( int  i = 1 ; i <= n ; i++  )cin>>s[ i ] ;
    cin>>m>>p1>>s1>>s2 ;
    for( int  i = 1 ; i < m ; i++ )tot1 += (ll)1LL*s[ i ]*( m - i ) ;
    for( int  i = m + 1 ; i <= n ; i++ )tot2 += (ll)1LL*s[ i ]*( i - m ) ;
    if( p1 < m )tot1 += s1*(m - p1) ;
    if( p1 > m )tot2 += s1*(p1 - m) ;
    ll  key = 0 ;
    if( tot1 > tot2 )key = -1 ;
    if( tot1 == tot2 ){printf("%d",m);return 0;}
    if( tot1 < tot2 )key = 1 ;
    ll cha = max( tot1 - tot2 , tot2 - tot1 ) ;
    ll wwlw = (ll)cha / (ll)s2 ;
    ll  op ;
    if( ( (wwlw +1)* s2  - cha) > ( cha - wwlw *s2 ) )op = wwlw ;
    else op = wwlw+1 ;
    if( key == 1 ){
    	if( ( (wwlw +1)* s2  - cha) == ( cha - wwlw *s2 ) ) op++ ;
        printf("%lld",max(1ll,m-op));
    }
    else{
    	if(( (wwlw +1)* s2  - cha) == ( cha - wwlw *s2 ) )op-- ;
        printf("%lld",min(n,m+op));
    }
	return  0 ;
}