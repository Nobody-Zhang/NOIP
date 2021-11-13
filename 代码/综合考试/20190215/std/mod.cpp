#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mid ((ll+rr)>>1)
#ifdef WIN32
#define myLL "%I64d"
#else
#define myLL "%lld"
#endif

using namespace std;

const int MAXN = 100005 ;
int n, m, A[MAXN] ;

int lc[MAXN<<2], rc[MAXN<<2], ndnum, maxn[MAXN<<2], leaf[MAXN], fa[MAXN<<2] , index[MAXN<<2];
long long sum[MAXN<<2] ;

void update(int s){
	sum[s] = sum[lc[s]] + sum[rc[s]] , maxn[s] = max(maxn[lc[s]],maxn[rc[s]]) ;
}

void build(int s,int ll,int rr){
	if(ll==rr) {
		sum[s] = A[ll] , maxn[s] = A[ll] , leaf[ll] = s, index[s] = ll ;
		return ;
	}
	build(lc[s]=++ndnum, ll, mid), build(rc[s]=++ndnum, mid+1, rr) ;
	fa[lc[s]] = fa[rc[s]] = s ;
	update(s) ;
}

int m_pos, m_num ;
void modify(int s,int ll,int rr){
	if(ll==rr){
		sum[s]=m_num , maxn[s]=m_num ; return ;
	}
	if(m_pos<=mid) modify(lc[s],ll,mid) ;
	else modify(rc[s],mid+1,rr) ;
	update(s) ;
}

int q_l, q_r ;
long long query(int s,int ll,int rr){
	if(ll>q_r || rr<q_l) return 0 ;
	if(ll>=q_l && rr<=q_r) return sum[s] ;
	return query(lc[s],ll,mid) + query(rc[s],mid+1,rr) ;
}

int findNextDown(int s, int num){
	if(!lc[s]) return index[s] ;
	if(maxn[lc[s]]>=num) return findNextDown(lc[s], num) ;
	else return findNextDown(rc[s], num) ;
}

int findNextUp(int pos, int num){ //pos之后的下一个大于等于num的数下标
	int s = leaf[pos] ;
	while(fa[s]){
		if(s==lc[fa[s]]){
			if(maxn[rc[fa[s]]] >= num){
				return findNextDown(rc[fa[s]], num) ;
				break ;
			}
		}
		s=fa[s] ;
	}
	return n+1 ;
}

int main(){
	freopen("mod.in","r",stdin) ;
	freopen("mod.out","w",stdout) ;
	scanf("%d%d",&n,&m) ;
	for(int i=1;i<=n;++i) scanf("%d",&A[i]) ;
	build(++ndnum,1,n) ;
	for(int i=1;i<=m;++i){
		int op, x, y, z ;
		scanf("%d%d%d",&op,&x,&y) ;
		if(op==1){
			q_l=x, q_r=y ;
			printf(myLL"\n", query(1,1,n)) ;
		}
		else if(op==2){
			scanf("%d",&z) ;
			int t=x ;
			while(t<=y){
				if(A[t]>=z){
					A[t]%=z ;
					m_pos=t, m_num=A[t], modify(1,1,n) ;
				}
				t = findNextUp(t, z) ;
			}
		}
		else if(op==3){
			m_pos=x, m_num=y, modify(1,1,n), A[x]=y ;
		}
	}
	return 0 ;
}
