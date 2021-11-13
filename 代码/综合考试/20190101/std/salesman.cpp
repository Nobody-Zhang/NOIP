#include<bits/stdc++.h>
using namespace std;
typedef bool boolean;
#define INF 0xfffffff
#define smin(a, b) a = min(a, b)
#define smax(a, b) a = max(a, b)
template<typename T>
inline void readInteger(T& u){
	char x;
	int aFlag = 1;
	while(!isdigit((x = getchar())) && x != '-');
	if(x == '-'){
		x = getchar();
		aFlag = -1;
	}
	for(u = x - '0'; isdigit((x = getchar())); u = (u << 1) + (u << 3) + x - '0');
	ungetc(x, stdin);
	u *= aFlag;
}

int n;
int dis[16][16];
int f[16][(1 << 17)];
boolean vis[16][(1 << 17)];

inline void init() {
	readInteger(n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			readInteger(dis[i][j]);
	for(int i = 1; i <= n; i++)
		dis[i][0] = dis[i][1], dis[0][i] = dis[1][i];
}

int dfs(int local, int status) {
	if(vis[local][status])	return f[local][status];
	vis[local][status] = true;
	for(int i = 0; i <= n; i++) {
		if(status & (1 << i)) {
			int ret = dfs(i, status ^ (1 << i));
			smin(f[local][status], f[i][status ^ (1 << i)] + dis[i][local]);
		}
	}
	return f[local][status];
}

inline void solve() {
	memset(vis, false, sizeof(vis));
	memset(f, 0x7f, sizeof(f));
	vis[1][0] = true;
	f[1][0] = 0;
	int res = dfs(0, (1 << (n + 1)) - 2);
	printf("%d", res);
}

int main() {
	freopen("salesman.in", "r", stdin);
	freopen("salesman.out", "w", stdout);
	init();
	solve();
	return 0;
}
