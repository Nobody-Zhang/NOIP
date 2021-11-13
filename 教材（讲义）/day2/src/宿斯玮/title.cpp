#include<bits/stdc++.h>
using namespace std;

int  ans = 0 ;

char  c ;

int  main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	for( int  i = 1 ; i <= 100000 ; i++  ){
		scanf("%c",&c);
		if( c == ' ')continue ;
		if( c == '\n')continue ;
		if( c >= 'a' && c <= 'z')ans++ ;
		if( c >= 'A' && c <= 'Z')ans++ ;
		if( c >= '0' && c<= '9')ans++ ;
	}
	cout<<ans ;
	return  0 ;
}