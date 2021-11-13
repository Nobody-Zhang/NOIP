#include<cstdio>
using namespace std;
int main()
{
	freopen( "score.in" , "r"  , stdin );
	freopen( "score.out" , "w" , stdout);
    int a,b,c;
    scanf( "%d %d %d" , &a , &b , &c );
    printf( "%d\n" , a / 5 + b * 3 / 10 + c / 2 );
	return 0;
}
