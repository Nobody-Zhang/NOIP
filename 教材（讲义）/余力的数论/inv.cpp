
int inv[100005] , P ; 
void ditui ( ) 
{
	inv[1] = 1 ; 
	for ( int i = 2 ; i <= N ; i++ ) 
	    inv[i] = ( - P / i * inv[P % i] % P + P ) % P ; 
}

int DanDu_digui ( int a ) 
{
	if ( a == 1 ) return 1 ; 
	else return ( -P / a * DanDu_digui ( P % a ) % P + P ) % P ; 
} 

long long DanDu_Fp ( long long a ) 
{
	long long K = P - 2 , ans = 1 ; 
	while ( K ) 
	{
		if ( K % 2 ) ans = ans * a % P ; 
		a = a * a % P ; 
		K = K / 2 ; 
	}
	return a ; 
}

int exgcd ( int &x , int a , int &y , int b ) 
{
	if ( b == 0 ) { x = 1 ; y = 0 ; return a ; }
	int xx , yy ; 
	int gc = gcd ( xx , b , yy , a % b ) ;
	x = yy ;  
	y = xx - a / b * yy ; 
} 

int DanDu_exgcd ( int a ) 
{
	int x , n ; 
	exgcd ( x , a , n , P ) ; 
	return ( x % P + P ) % P ; 
}
