void dfs1( int u ) {
	siz[u] = 1;
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == fat[u] ) continue;
		fat[v] = u;
		dep[v] = dep[u]+1;
		dfs1(v);
		siz[u] += siz[v];
		if( siz[v] > siz[son[u]] ) son[u] = v;
	}
}
dep[1] = 1;
fat[1] = 1;
dfs1(1);


void dfs2( int u, int tp ) {
	in[u] = ++idc;
	top[u] = tp;
	if( son[u] ) dfs2( son[u], tp );
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == fat[u] || v == son[u] ) continue;
		dfs2( v, v );
	}
	out[u] = idc;
}
idc = 0;
dfs2(1,1);

int lca( int u, int v ) {
	while( top[u] != top[v] ) {
		if( dep[top[u]] < dep[top[v]] ) swap(u,v);
		u = fat[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

