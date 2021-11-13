#include<cstdio>
using namespace std;
int main()
{
	freopen( "title.in" , "r"  , stdin );
	freopen( "title.out" , "w" , stdout);
    char s;int ans = 0;
    while( ( scanf( "%c" , &s ) == true ) )
      if( s != ' ' && s != '\n' ) ans++;
    printf( "%d\n" , ans );
	return 0;
}
