#include<cstdio>
#include<iostream>
using namespace std;
#define oo 0x3f3f3f3f
#define ri register int
typedef long long ll;
const int N = 2000007;
int n,k,h,t,p;
ll a[N],sum[N],dp[N],q[N];

template<class T>
inline void read(T &res){
    static char ch;T flag = 1;
	while( ( ch = getchar() ) < '0' || ch > '9' ) if( ch == '-' ) flag = -1;
	res = ch - 48;
	while( ( ch = getchar() ) >= '0' && ch <= '9' ) res = res * 10 + ch - 48;
	res *= flag;
}

int main()
{
	freopen( "group.in" , "r"  , stdin );
	freopen( "group.out" , "w" , stdout);
    scanf( "%d %d" , &n , &k );
    for( ri i = 1 ; i <= n ; i++ ){
    	read( a[ i ] );
    	sum[ i ] = sum[ i - 1 ] + a[ i ];
    }
    h = 1;//touzhizhen
    t = 0;//weizhizhen
    p = 1;//zhixiangdangqiandairuduideyuansu
    for( ri i = 1 ; i <= k ; i++ )
      dp[ i ] = sum[ i ];
    for( ri i = k + 1 ; i <= n ; i++ ){
    	while( h <= t && q[ h ] < i - k )
		  h++;//qingchuguoshiyuansu 
    	while( p <= i ){
    		while( h <= t && dp[ p - 1 ] - sum[ p ] > 
			dp[ q[ t ] - 1 ] - sum[ q[ t ] ] )
			  t--;
    		q[ ++t ] = p++;
    	}//banengruduidedourudui
    	dp[ i ] = sum[ i ] - sum[ q[ h ] ] + dp[ q[ h ] - 1 ];//zhuanyi
    }
    cout<<dp[ n ];//shuchuda'an
	return 0;
}
