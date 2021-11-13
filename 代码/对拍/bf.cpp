#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mid ((int)(((long long)ll+rr)>>1))
using namespace std;

const int MAXN=100005, LLIM=-2147483648, HLIM=2147483647 ;
int n , m , A[MAXN] ;

char getChar(){
	char c ;
	while((c=getchar()) != EOF && isspace(c)) ;
	return c ;
}

int lc[MAXN*33], rc[MAXN*33], size[MAXN*33], q_k, ndnum , root ;

void update(int s){ size[s] = size[lc[s]] + size[rc[s]] ; }

int query(int s, int ll, int rr){
	if(ll==rr) return ll ;
	if(q_k <= size[lc[s]]) return query(lc[s], ll, mid) ;
	else {
		q_k -= size[lc[s]] ;
		return query(rc[s], mid+1, rr) ;
	}
}

int a_pos , a_num ; //a_pos为修改的值, a_num为+-1表示新增值或删除值

void add(int &s, int ll, int rr){
	if(!s) s=++ndnum ;
	if(ll==rr) { size[s] += a_num ; return ; }
	if(a_pos <= mid) add(lc[s], ll, mid) ;
	else add(rc[s], mid+1, rr) ;
	update(s) ;
}

int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.ans","w",stdout);
	scanf("%d%d",&n,&m) ;
	for(int i=1;i<=n;++i) scanf("%d",&A[i]) , a_pos=A[i] , a_num=1, add(root,LLIM,HLIM) ;
	for(int i=1;i<=m;++i){
		char op = getChar() ;
		int x, y ;
		if(op == 'M'){
			scanf("%d%d",&x,&y) ;
			a_pos = A[x] , a_num = -1 , add(root,LLIM,HLIM) ;
			a_pos = y , a_num = 1 , add(root,LLIM,HLIM) ;
			A[x] = y ;
		}
		else if(op == 'Q'){
			scanf("%d",&q_k) ;
			printf("%d\n",query(root,LLIM,HLIM)) ;
		}
	}
	return 0 ;
}
