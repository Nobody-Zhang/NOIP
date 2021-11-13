#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mid ((ll+rr)>>1)
using namespace std;

const int MAXN = 100005, MOD=1000000007 ;
int n, m, A[MAXN] ;

inline void getMod(long long &a){ if(a>=MOD) a-=MOD; }

long long lazyAdd[MAXN<<2], lazyMul[MAXN<<2], sum[MAXN<<2], sum2[MAXN<<2] ;
int lc[MAXN<<2], rc[MAXN<<2], ndnum , size[MAXN<<2] ;

void update(int s){
	sum[s] = sum[lc[s]] + sum[rc[s]] , getMod(sum[s]) ;
	sum2[s] = sum2[lc[s]] + sum2[rc[s]] , getMod(sum2[s]) ;
}

void build(int s,int ll,int rr){
	lazyMul[s]=1; //初始化乘标记
	if(ll==rr){
		sum[s] = A[ll] , sum2[s] = (long long)A[ll]*A[ll]%MOD , size[s]=1 ;
		return ;
	}
	build(lc[s]=++ndnum, ll, mid), build(rc[s]=++ndnum, mid+1, rr) ;
	update(s) , size[s]=size[lc[s]] + size[rc[s]] ;
}

void tagAdd(int s,long long num){
	if(!s) return ;
	lazyAdd[s] += num , getMod(lazyAdd[s]) ;
	sum2[s] += (num*num%MOD*size[s]%MOD + 2*num*sum[s]%MOD) , sum2[s]%=MOD ;
	sum[s] += size[s]*num%MOD , getMod(sum[s]) ;
}

void tagMul(int s,long long num){
	if(!s) return ;
	lazyAdd[s] = lazyAdd[s] * num % MOD ;
	lazyMul[s] = lazyMul[s] * num % MOD ;
	sum[s] = sum[s] * num % MOD ;
	sum2[s] = sum2[s] * num % MOD * num % MOD ;
}

void pushdown(int s){
	if(lazyMul[s]!=1){
		tagMul(lc[s], lazyMul[s]), tagMul(rc[s], lazyMul[s]) ;
		lazyMul[s]=1 ;
	}
	if(lazyAdd[s]!=0){
		tagAdd(lc[s], lazyAdd[s]), tagAdd(rc[s], lazyAdd[s]) ;
		lazyAdd[s]=0 ;
	}
}

int a_l, a_r, a_num ;
void add(int s,int ll,int rr){
	pushdown(s) ;
	if(ll>a_r || rr<a_l) return ;
	if(ll>=a_l && rr<=a_r){
		tagAdd(s, a_num) ;
		return ;
	}
	add(lc[s],ll,mid) , add(rc[s],mid+1,rr) ;
	update(s) ;
}

int m_l, m_r, m_num ;
void mul(int s,int ll,int rr){
	pushdown(s) ;
	if(ll>m_r || rr<m_l) return ;
	if(ll>=m_l && rr<=m_r){
		tagMul(s, m_num) ;
		return ;
	}
	mul(lc[s],ll,mid) , mul(rc[s],mid+1,rr) ;
	update(s) ;
}

int q_l, q_r ;
int query(int s,int ll,int rr){
	pushdown(s) ;
	if(ll>q_r || rr<q_l) return 0;
	if(ll>=q_l && rr<=q_r){
		return (int)sum2[s] ;
	}
	return (query(lc[s],ll,mid)+query(rc[s],mid+1,rr))%MOD;
}

int main(){
//	freopen("sum.in","r",stdin) ;
//	freopen("sum.out","w",stdout) ;
	scanf("%d%d",&n,&m) ;
	for(int i=1;i<=n;++i) scanf("%d",&A[i]) ;
	build(++ndnum,1,n) ;
	for(int i=1;i<=m;++i){
		int op, x, y, z ;
		scanf("%d%d%d",&op,&x,&y) ;
		if(op==1){
			scanf("%d",&z) ;
			a_l=x, a_r=y, a_num=z , add(1,1,n) ;
		}
		else if(op==2){
			scanf("%d",&z) ;
			m_l=x, m_r=y, m_num=z , mul(1,1,n) ;
		}
		else if(op==3){
			q_l=x, q_r=y ;
			printf("%d\n",query(1,1,n)) ;
		}
	}
	return 0 ;
}
