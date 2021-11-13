#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
const int MOD=1000007, MAXN=100005, MAXM=1000055 ;
int origin[MAXM] ;

int numHash(int a, bool f){
	int t = (a + (a>>1) + (a>>3)) % MOD ;
	while(origin[t]!=-1 && origin[t]!=a){
		t+=107 ;
		if(t>=MOD) t-=MOD ;
	}
	if(f) origin[t]=a ;
	return t ;
}

int main(){
	memset(origin,-1,sizeof(origin)) ;
	scanf("%d%d",&n,&m) ;
	for(int i=1;i<=n;++i){
		int a;
		scanf("%d",&a) ;
		numHash(a,1) ;
	}
	for(int i=1;i<=m;++i){
		int a;
		scanf("%d",&a) ;
		if(origin[numHash(a,0)]!=-1) printf("YES\n") ;
		else printf("NO\n") ;
	}
}
