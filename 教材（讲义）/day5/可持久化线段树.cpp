#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mid ((ll+rr)>>1)
using namespace std;

const int MAXN=100005 ;

int lc[MAXN*20], rc[MAXN*20], sum[MAXN*20], A[MAXN], ndnum ;

void copyNode(int a, int b){
	lc[a]=lc[b], rc[a]=rc[b], sum[a]=sum[b];
}

void update(int s){				  //同普通线段树无区别
	sum[s]=sum[lc[s]]+sum[rc[s]] ;
}

void build(int s, int ll,int rr){ //同普通线段树无区别
	if(ll==rr) { 
		sum[s] = A[ll] ;
		return ;
	}
	build(lc[s]=++ndnum, ll, mid), build(rc[s]=++ndnum, mid+1, rr) ;
	update(s) ;
}

int m_pos, m_num ;
int modify(int s,int ll,int rr){ //对以s为根的线段树进行修改，并返回新建的代替s的结点
	int t=++ndnum;
	copyNode(t,s) ;
	if(ll==rr){
		sum[t] = m_num ;
		return t;
	}
	if(m_pos<=mid) lc[t]=modify(lc[t],ll,mid) ;
	else rc[t]=modify(rc[t],mid+1,rr) ;
	update(t) ;
	return t;
}

int q_l, q_r;
int query(int s, int ll, int rr){ //同普通线段树无区别
	if(ll>=q_l && rr<=q_r) return sum[s] ;
	if(ll>q_r || rr<q_l) return 0 ;
	return query(lc[s],ll,mid) + query(rc[s],mid+1,rr) ;
}

int root[MAXN] ; //root[i]存下第i次操作之后的线段树根结点
int main(){
	//长为n的序列，m次操作，两种操作：更改序列为在第 x 次操作后的序列的基础上，将 pos 位置的值改为 val 后得到的序列 ；或求第 x 次操作后的序列上 l 到 r 的区间和
	int n, m;
	scanf("%d%d",&n,&m) ;
	for(int i=1;i<=n;++i){
		scanf("%d",&A[i]) ;
	}
	build(root[0]=++ndnum, 1, n) ;
	for(int i=1;i<=m;++i){
		int op;
		scanf("%d",&op) ;
		if(op==1){				//修改
			int x, pos, val ;
			scanf("%d%d%d",&x,&pos,&val) ;
			m_pos=pos, m_num=val, root[i]=modify(root[x],1,n) ;
		}
		else if(op==2){			//查询
			int x, l, r;
			scanf("%d%d%d",&x,&l,&r) ;
			q_l=l, q_r=r ;
			printf("%d\n",query(root[x],1,n)) ;
			root[i]=root[i-1] ; //查询操作不影响序列
		}
	}
}
