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

const int MAXN=100005 ;
int n, m, last[MAXN], pre[MAXN], A[MAXN] ;
//last[i]表示值i上一次出现的位置，pre[i]表示上一个同A[i]相等的位置

struct Question{
	int l, r, index ;
}Q[MAXN];

bool cmp(const Question &a, const Question &b) { return a.r<b.r ; }


int lc[MAXN<<2], rc[MAXN<<2], ndnum;
long long lazyAdd[MAXN<<2], ans[MAXN] ;

void build(int s,int ll,int rr){
	if(ll==rr) return ;
	build(lc[s]=++ndnum, ll, mid), build(rc[s]=++ndnum, mid+1, rr) ;
}

void tagAdd(int s, long long num){
	if(!s) return ;
	lazyAdd[s] += num ;
}

void pushdown(int s){
	if(!lc[s]) return ;
	if(lazyAdd[s]!=0){
		tagAdd(lc[s], lazyAdd[s]), tagAdd(rc[s], lazyAdd[s]) ;
		lazyAdd[s]=0 ;
	}
}

int a_l, a_r, a_num;
void add(int s, int ll, int rr){
	pushdown(s) ;
	if(ll>a_r || rr<a_l) return ;
	if(ll>=a_l && rr<=a_r){
		tagAdd(s, a_num) ;
		return ;
	}
	add(lc[s],ll,mid), add(rc[s],mid+1,rr) ;
}

int q_pos ;
long long query(int s,int ll,int rr){
	if(ll==rr) return lazyAdd[s] ;
	pushdown(s) ;
	if(q_pos<=mid) return query(lc[s],ll,mid) ;
	else return query(rc[s],mid+1,rr) ;
}

int main(){
	freopen("couple20.in","r",stdin) ;
	freopen("couple.out","w",stdout) ;
	scanf("%d%d",&n,&m) ;
	for(int i=1;i<=n;++i) scanf("%d",&A[i]) ;
	for(int i=1;i<=m;++i){
		scanf("%d%d", &Q[i].l, &Q[i].r) ;
		Q[i].index=i ;
	}
	sort(Q+1,Q+m+1,cmp) ;
	for(int i=1;i<=n;++i){
		pre[i] = last[A[i]] ;
		last[A[i]] = i ;
	}
	int p=1 ;
	build(++ndnum,1,n) ;
	for(int i=1;i<=n;++i){
		a_l=pre[i]+1, a_r=i , a_num=A[i], add(1,1,n) ;
		if(pre[i]){
			a_l=pre[pre[i]]+1, a_r=pre[i], a_num=-A[i], add(1,1,n) ;
		}
		if(pre[pre[i]]){
			a_l=pre[pre[pre[i]]]+1, a_r=pre[pre[i]], a_num=3*A[i], add(1,1,n) ;
		}
		while(p<=m && Q[p].r==i){
			q_pos=Q[p].l, ans[Q[p].index]=query(1,1,n) ;
			++p ;
		}
	}
	for(int i=1;i<=n;++i)
		printf(myLL"\n",ans[i]) ;
	return 0 ;
}
