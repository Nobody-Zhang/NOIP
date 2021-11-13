#define LL long long
LL fm ( LL x , LL y , LL Mod ) 
{
	LL ans = 0 ; 
	while ( k ) 
	{
		if ( k % 2 ) ans = ( ans + x ) % Mod ; 
		x = ( x + x ) % Mod ; 
		k = k / 2 ;  
	}
	return ans ; 
}

LL fp ( LL x , LL k , LL Mod )
{
	LL ans = 1 ; 
	while ( k ) 
	{
		if ( k % 2 ) ans = fm ( ans , x , Mod ) ; 
		x = fm ( x , x , Mod ) ; 
		k = k / 2 ; 
	}
	return ans ; 
}

int test[30] = { 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 } ;
bool Miller_Rabin ( LL x ) 
{
	if ( x <= 47 )
	{
		for ( int i = 0 ; i <= 14 ; i++ ) if ( x == test[i] ) return true ; 
		return false ; 
	} 
	LL xx = x - 1 ; 
	while ( xx % 2 == 0 ) xx = xx / 2 ;  
	for ( int i = 0 ; i <= 14 ; i++ ) 
	{
		bool Millers_judge = false ; 
		if ( fp2 ( test[i] , xx , x ) == 1 ) Millers_judge = true ;
		for ( int k = 1 ; k <= ( x - 1 ) / xx && ( !Millers_judge ) ; k *= 2 )
		    if ( fp2 ( test[i] , xx * k , x ) == x - 1 ) Millers_judge = true ; 
		if ( !Millers_judge ) return false ;   
	}
	return true ;  
}

int Detal , que[10005] , cnt ;  
LL Fx ( LL x , LL Mod ) { return ( fm ( x , x , Mod ) + Detal ) % Mod ; }

void Pollard_Rho ( LL x ) 
{
	LL p = 1 ; Detal = 15 ; 
	if ( x == 1 ) return ;   
	if ( Miller_Rabin ( x ) ) { que[++cnt] = x ; return ; }
	while ( --Detal ) 
	{
		LL a = rand ( ) ; 
		a = fm ( a , 100000000000000007 , x ) ;	
		LL b = a ; a = Fx ( a , x ) ;
		LL C = 1 , lp = 2 ;  
		while ( a != b ) 
		{
			C++ ; 
			LL d = a - b ; if ( d < 0 ) d = -d ; d = d % x ;  
		    p = gcd ( x , d ) ; 
		    if ( p != 1 && p != x ) break ; 
			a = Fx ( a , x ) ; 
			if ( C == lp ) { b = a ; a = Fx ( a , x ) ; lp = lp << 1 ; }  
		}   
		if ( p != 1 && p != x ) break ;
	}
	Rho ( x / p ) ; 
	Rho ( p ) ; 
}

