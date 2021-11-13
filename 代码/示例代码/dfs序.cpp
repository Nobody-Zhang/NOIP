int in[N], out[N], seq[N], idc;
void dfs( int u, int f ) {
	seq[++idc] = u;
	in[u] = idc;
	for( int t = head[u]; t; t = last[t] ) {
		int v = dest[t];
		if( v == f ) continue;
		dfs( v, u );
	}
	out[u] = idc;
}
idc = 0;
dfs( root, root );
