#include <cstdio>

const int N = 1000010;
const int Mod = 1000000007;

typedef long long dnt;

int n;
dnt der[N];

int main() {
	freopen("derange.in","r",stdin);
	freopen("derange.out","w",stdout);
	scanf( "%d", &n );
	der[1] = 0;
	der[2] = 1;
	for( int i = 3; i <= n; i++ ) {
		der[i] = (i - 1) * (der[i-1] + der[i-2]) % Mod;
	}
	printf( "%d\n", (int)der[n] );
	return 0;
}

