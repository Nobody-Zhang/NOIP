#include <cstdio>
#include <cctype>
#define min(a, b) (a) < (b) ? (a) : (b)
typedef __int64 LL;

inline LL Abs( LL a )  {  return a < 0 ? -a : a; }
template <class T>
inline bool readIn( T &x )  {
	x = 0;
	char ch = (char)getchar();
	while( !isdigit(ch) )
		ch = (char)getchar();
	while( isdigit(ch) )  {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = (char)getchar();
	}
}

template <class T>
inline void writeIn( T x )  {
     if ( x > 9 )
	 writeIn ( x / 10 );
	 putchar ( x % 10 + '0' );
}

inline LL mult( LL a, LL b)  {
	LL rt = 0;
	while( a )  {
		if( a & 1 )  rt += b;
		b <<= 1, a >>= 1;
	}
	return rt;
} 
int n, t, c, a[1001], w[1001], s[1001];
LL f[1001][1001][2];

int main(){
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
    readIn(n);readIn(c);
    for(int i = 1; i <= n; ++i) readIn(a[i]), readIn(t), s[i] = s[i-1] + t;
    for(int i = 1; i <= n; ++i) f[i][i][0] = f[i][i][1] = Abs(a[c]-a[i]) * s[n];
    for(int i = n; i >= 1; --i)
        for(int j = i + 1; j <= n; ++j)  {
            f[i][j][0] = min(f[i+1][j][0] + mult(s[i] + s[n] - s[j], a[i+1] - a[i]),
                            f[i][j-1][1] + mult(s[i-1] + s[n] - s[j-1], a[j] - a[j-1])
                            +mult(s[i-1]+s[n] - s[j], a[j] - a[i]) );
            f[i][j][1] = min(f[i][j-1][1] + mult(s[i-1] + s[n] - s[j-1], a[j] - a[j-1]),
                            f[i+1][j][0] + mult(s[i] + s[n] - s[j], a[i+1] - a[i])
                            + mult(s[i-1]+s[n]-s[j], a[j] - a[i]) );
        }
    writeIn(min(f[1][n][0],f[1][n][1]));
    putchar('\n');
}
