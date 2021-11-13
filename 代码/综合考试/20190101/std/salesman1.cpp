#include "cstdio"
#include "cstring"
#define min( a, b )  (a) < (b) ? (a) : (b)

int a[16][16], dp[16][(1 << 15) + 1], n, ans = 0x3f3f3f3f;

int main(void)  {
	freopen("salesman.in", "r", stdin);
	freopen("salesman.out", "w", stdout);
	scanf("%d", &n);
	for( int i = 1; i <= n; ++i )
	  for( int j = 1; j <= n; ++j )
	    scanf("%d", &a[i][j]);
	memset( dp, 0x3f, sizeof(dp));
	dp[1][1] = 0;
	for( int i = 0; i <= ( 1 << n ); ++i )  
	  for( int j = 1; j <= n; ++j )
	    if( !(1 << ( j - 1 )  & i) )
		  for( int k = 1; k <= n; ++k )
		    if( 1 << ( k - 1 ) & i )
			  dp[j][(1 << ( j - 1 )) | i] = min( dp[k][i] + a[k][j], dp[j][(1 << ( j - 1 )) | i]);
	for( int i = 2; i <= n; ++i )
	  ans = min( ans, dp[i][(1 << n) - 1] + a[i][1]);
	printf("%d\n", ans);		    
	return 0;
}
