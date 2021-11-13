

long long b[105] , p[105] ; 
int N ; 
long long China_mod ( ) 
{
	long long P = 1 ; 
	for ( int i = 1 ; i <= N ; i++ ) 
	    P *= p[i] ; 
	long long ans = 0 ; 
	for ( int i = 1 ; i <= N ; i++ )
	    ans += ( P / p[i] * b[i] * inv ( P / p[i] , p[i] ) )
	ans %= P ; 
	return ans ;   
}
