#include<bits/stdc++.h>
using namespace std;

const int maxT = 4000005;

int n, m, t, ti, ans = 1e7, cnt[maxT], sum[maxT], f[maxT];

inline int read()
{
    int s = 0,w = 1;
    char g = getchar();
    while(g<'0'||g>'9'){if(g=='-')w*=-1;g = getchar();}
    while(g>='0'&&g<='9'){s = s*10+g-'0';g = getchar();}
    return s*w;
}

int main() {
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
    n = read() , m =read() ;
    for (int i = 1; i <= n; i++) {
        ti = read() ; t = max( t , ti ) ;
        cnt[ ti ]++ ; sum[ ti ] += ti ;
    }
    for (int i = 1; i < t + m ; i++ ) { cnt[i] += cnt[i - 1]; sum[i] += sum[i - 1]; } 
    for (int i = 1; i < t + m ; i++ ) {
        f[i] = cnt[i] * i - sum[i]; 
        for (int j = max(i - m - m + 1, 0); j <= i - m; j++) 
        	{ f[i] = std::min(f[i], f[j] + (cnt[i] - cnt[j]) * i - (sum[i] - sum[j]) ); }
    }
    for (int i = t; i < t + m; i++) { ans = min(ans, f[i]); }
    printf("%d", ans);
    return 0;
}