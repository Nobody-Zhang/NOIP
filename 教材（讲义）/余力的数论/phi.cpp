#include <cstdio>
#include <algorithm>
using namespace std ; 

int cnt , zhishu[100005] ;
bool not_zhishu[100005] ; 
int phi[100005] , N ; 

void Euler_zhishu ( )
{
	for ( int i = 2 ; i <= N ; i++ ) 
	{
		if ( not_zhishu[i] == false ) 
		{
			zhishu[++cnt] = i ; 
			phi[i] = i - 1 ; 
		}
		for ( int j = 1 ; j <= cnt && zhishu[j] <= N / i ; j++ ) 
		{
			not_zhishu[zhishu[j] * i] = true ; 
			if ( i % zhishu[j] == 0 ) 
			{
				phi[i * zhishu[j]] = phi[i] * zhishu[j] ; 
				break ; 
			}
			else 
			{
				phi[i * zhishu[j]] = phi[i] * phi[zhishu[j]] ; 
			}
		}
	}
}

int main ( ) 
{
	scanf ( "%d" , &N ) ;  
	Euler_zhishu ( ) ; 
	
}
