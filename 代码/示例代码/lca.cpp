void dfs( int u, int f ) {
	anc[u][0] = f;
	for( int p = 1; p <= P; p++ )
		anc[u][p] = anc[anc[u][p-1]][p-1];
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == f ) continue;
		dep[v] = dep[u] + 1;
		dis[v] = dis[u] + wght[t];
		dfs( v, u );
	}
}
int lca( int u, int v ) {
	if( dep[u] < dep[v] ) swap(u,v);
	int t = dep[u] - dep[v];
	for( int p = 0; t; t>>=1, p++ )
		if( t & 1 ) u = anc[u][p];
	if( u == v ) return u;
	for( int p = P; anc[u][0] != anc[v][0]; p-- )
		if( anc[u][p] != anc[v][p] )
			u = anc[u][p], v = anc[v][p];
	return anc[u][0];
}