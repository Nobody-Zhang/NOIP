#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;

const int MAXN=1000005 ;
int n , K , cnt ;
int q_l[MAXN] , q_r[MAXN] , q_c[MAXN] , fa[MAXN] ;
int A[MAXN] ;

void reads(int &a){
	char t=getchar() ;
	a=0 ;
	bool f=false ;
	while(t<'0'||t>'9') {
		if(t=='-') f=true ;
		t=getchar() ;
	}
	while(t>='0'&&t<='9'){
		a=(a<<1)+(a<<3)+t-'0' ;
		t=getchar() ;
	}
	if(f) a=-a ;
}

int getFa(int a){
	++cnt ;
	if(fa[a]==a) return a;
	return fa[a]=getFa(fa[a]) ;
}

void getUnion(int a,int b){
	if(getFa(a)!=getFa(b)) fa[fa[a]]=fa[b] ;
}

void paint(int pos,int c){
	A[pos]=c ;
	if(pos!=1 && A[pos-1]) getUnion(pos-1,pos) ;
	if(pos!=n && A[pos+1]) getUnion(pos,pos+1) ;
}

int main(){
	freopen("paint.in","r",stdin) ;
	freopen("paint.out","w",stdout) ;
	reads(n) , reads(K) ;
	for(int i=1;i<=K;++i){
		reads(q_l[i]) , reads(q_r[i]) , reads(q_c[i]) ;
	}
	for(int i=1;i<=n;++i) fa[i]=i ;
	for(int i=K;i>=1;--i){
		int now=q_l[i] ;
		while(now<=q_r[i]){
			if(!A[now]) paint(now,q_c[i]) ;
			now=getFa(now)+1 ;
		}
	}
	for(int i=1;i<=n;++i) cout << A[i] << ' ';
	printf("\n") ;
	return 0;
}
