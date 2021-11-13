#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mid ((ll+rr)>>1)
using namespace std;

const int MAXN=100005 ;
int n , m , A[MAXN] , rx[MAXN] , ry[MAXN] , B[MAXN<<1] , bnum ;
char op[MAXN] ;

char getChar(){
	char c ;
	while((c=getchar()) != EOF && isspace(c)) ;
	return c ;
}

int lc[MAXN<<2], rc[MAXN<<2], size[MAXN<<2], q_k, ndnum ;

void build(int s, int ll,int rr){ //注意初始size均为0
	if(ll == rr) return ;
	build(lc[s]=++ndnum , ll, mid) , build(rc[s]=++ndnum, mid+1, rr);
}

void update(int s){ size[s] = size[lc[s]] + size[rc[s]] ; }

int query(int s, int ll, int rr){
	if(ll==rr) return B[ll] ;
	if(q_k <= size[lc[s]]) return query(lc[s], ll, mid) ;
	else {
		q_k -= size[lc[s]] ;
		return query(rc[s], mid+1, rr) ;
	}
}

int a_pos , a_num ; //a_pos为修改的值, a_num为+-1表示新增值或删除值

void add(int s, int ll, int rr){
	if(ll==rr) { size[s] += a_num ; return ; }
	if(a_pos <= B[mid]) add(lc[s], ll, mid) ;
	else add(rc[s], mid+1, rr) ;
	update(s) ;
}

int main(){
	scanf("%d%d",&n,&m) ;
	for(int i=1;i<=n;++i) scanf("%d",&A[i]) , B[++bnum] = A[i] ;
	for(int i=1;i<=m;++i){
		op[i] = getChar() ;
		if(op[i] == 'M'){
			scanf("%d%d",&rx[i],&ry[i]) , B[++bnum] = ry[i] ;
		}
		else if(op[i] == 'Q'){
			scanf("%d",&rx[i]) ;
		}
	}
	sort(B+1 , B+bnum+1) ;
	bnum = unique(B+1, B+bnum+1) - B - 1 ;
	build(++ndnum , 1 , bnum) ;
	for(int i=1;i<=n;++i) a_pos = A[i] , a_num = 1 , add(1,1,bnum) ;
	for(int i=1;i<=m;++i){
		if(op[i] == 'M'){
			a_pos = A[rx[i]] , a_num = -1 , add(1,1,bnum) ;
			a_pos = ry[i] , a_num = 1 , add(1,1,bnum) ;
			A[rx[i]] = ry[i] ;
		}
		else if(op[i] == 'Q'){
			q_k = rx[i] ;
			printf("%d\n",query(1,1,bnum)) ;
		}
	}
	return 0 ;
}
