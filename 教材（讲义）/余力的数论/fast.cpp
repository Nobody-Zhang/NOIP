int fp ( long long x , long long k , int mod )
{
	x = x % mod ; 
	long long ans = 1 ; 
	while ( k ) 
	{
		if ( k % 2 ) ans = ans * x % mod ; 
		x = x * x % mod ; 
		k = k / 2 ; 
	}
	return ans ; 
}

long long fm ( long long x , long long y , long long mod ) 
{
	long long ans = 0 ; 
	while ( k ) 
	{
		if ( k % 2 ) ans = ( ans + x ) % mod ; 
		x = ( x + x ) % mod ; 
		k = k / 2 ;  
	}
	return ans ; 
}
