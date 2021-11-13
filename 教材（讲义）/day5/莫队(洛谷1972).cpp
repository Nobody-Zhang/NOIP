#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=500005, MAXM=1000005 ;
int n, m, A[MAXN], cnt[MAXM], pos[MAXN], bSize, ans[MAXN], nowAns ;

void reads(int &a){
	bool f=false ; char c=getchar() ; a=0 ;
	while(c<'0'||c>'9'){
		if(c=='-') f=true ;
		c=getchar() ;
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+c-'0' ;
		c=getchar() ;
	}
	if(f) a=-a ;
}

struct Question{
	int l, r, index ;
}Q[MAXN];

bool cmp(const Question &a, const Question &b){
	if(pos[a.l]==pos[b.l]) return a.r<b.r ;
	else return pos[a.l]<pos[b.l] ;
}

void add(int pos){
	if(++cnt[A[pos]]==1) nowAns++ ;
}

void del(int pos){
	if(--cnt[A[pos]]==0) nowAns-- ;
}

int main(){
	scanf("%d",&n) ;
	bSize = sqrt(n+0.5) ;
	for(int i=1;i<=n;++i)
		reads(A[i]), pos[i]=(i-1)/bSize+1 ;
	scanf("%d",&m) ;
	for(int i=1;i<=m;++i){
		reads(Q[i].l), reads(Q[i].r) ; Q[i].index=i ;
	}
	sort(Q+1,Q+m+1,cmp) ;
	int nowL=1, nowR=1; 
	cnt[A[1]]=1, nowAns=1 ;
	for(int i=1;i<=m;++i){
		while(nowL>Q[i].l) add(--nowL) ;
		while(nowR<Q[i].r) add(++nowR) ;
		while(nowL<Q[i].l) del(nowL++) ;
		while(nowR>Q[i].r) del(nowR--) ;
		ans[Q[i].index] = nowAns ;
	}
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]) ;
	}
	return 0 ;
}
