#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mid ((ll+rr)>>1)
using namespace std;

const int MAXN = 100005, INF=(1<<30)-1 ;
int n, m, nexts[MAXN], to[MAXN], first[MAXN], dSeq[MAXN], dnum, dIndex[MAXN], size[MAXN], A[MAXN], root=1, egnum, fa[MAXN][20] ;

void addEdge(int a,int b){
	nexts[++egnum]=first[a], first[a]=egnum, to[egnum]=b ;
}

void dfs(int a){
	dSeq[++dnum] = a, dIndex[a] = dnum, size[a] = 1 ;
	for(int i=first[a];i;i=nexts[i]){
		dfs(to[i]) ;
		size[a] += size[to[i]], fa[to[i]][0] = a;
	}
}

int lc[MAXN<<2], rc[MAXN<<2], minn[MAXN<<2], ndnum ;

void update(int s){
	minn[s] = min(minn[lc[s]],minn[rc[s]]) ;
}

void build(int s, int ll,int rr){
	if(ll==rr){
		minn[s] = A[dSeq[ll]] ;
		return ;
	}
	build(lc[s]=++ndnum, ll, mid), build(rc[s]=++ndnum, mid+1, rr) ;
	update(s) ;
}

int q_l, q_r ;
int query(int s,int ll,int rr){
	if(ll>q_r || rr<q_l || ll>rr) return INF ;
	if(ll>=q_l && rr<=q_r){
		return minn[s] ;
	}
	return min(query(lc[s],ll,mid), query(rc[s],mid+1,rr)) ;
}

int m_pos, m_num ; //注意映射
void modify(int s,int ll,int rr){
	if(ll==rr){ minn[s]=m_num; return ; }
	if(m_pos<=mid) modify(lc[s],ll,mid) ;
	else modify(rc[s],mid+1,rr) ;
	update(s) ;
}

int main(){
	freopen("min.in","r",stdin) ;
	freopen("min.out","w",stdout) ;
	scanf("%d%d",&n,&m) ;
	for(int i=1;i<=n;++i){
		int f;
		scanf("%d%d",&f,&A[i]) ;
		if(f) addEdge(f,i) ;
	}
	dfs(1) ;
	for(int k=1;k<=20;++k){
		for(int i=1;i<=n;++i) fa[i][k] = fa[fa[i][k-1]][k-1];
	}
	build(++ndnum,1,n) ;
	for(int i=1;i<=m;++i){
		int op, x, y;
		scanf("%d%d",&op,&x) ;
		if(op==1){
			scanf("%d",&y) ;
			m_pos = dIndex[x], m_num = y, modify(1,1,n) ;
		}
		else if(op==2){
			int ans = INF ;
			if(root==x){
				q_l = 1, q_r = n, ans=query(1,1,n) ;
			}
			else if(dIndex[root]>dIndex[x] && dIndex[root]<dIndex[x]+size[x]){
				int t = root ;
				for(int k=20;k>=0;--k){
					if(fa[t][k] && dIndex[fa[t][k]]>dIndex[x]) t=fa[t][k] ;
				}
				q_l = 1, q_r = dIndex[t]-1, ans=query(1,1,n) ;
				q_l = dIndex[t]+size[t], q_r = n , ans=min(ans, query(1,1,n)) ;
			}
			else{
				q_l = dIndex[x], q_r = dIndex[x]+size[x]-1, ans=query(1,1,n) ;
			}
			printf("%d\n",ans) ;
		}
		else if(op==3){
			root = x ;
		}
	}
	return 0 ;
}
