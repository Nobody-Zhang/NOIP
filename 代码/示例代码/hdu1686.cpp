#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1000005 ;
const unsigned long long BASE = 10007 ;
unsigned long long pre[MAXN], pows[MAXN] ;
int len1, len2 ;
char s1[MAXN], s2[MAXN] ;

void init(){
	scanf("%s%s",s1+1,s2+1) ;
	len1 = strlen(s1+1), len2=strlen(s2+1) ;
	for(int i=1;i<=len2;++i){
		pre[i] = pre[i-1] * BASE + s2[i] ;
	}
}

unsigned long long getHash(int l,int r){
	return pre[r] - pre[l-1] * pows[r-l+1] ;
}

void solve(){
	int ans=0 ;
	unsigned long long hash=0 ;
	for(int i=1;i<=len1;++i) hash = hash * BASE + s1[i] ;
	for(int i=1;i+len1-1<=len2;++i){
		if(getHash(i,i+len1-1)==hash) ans ++ ;
	}
	printf("%d\n",ans) ;
}

int main(){
	int T ;
	scanf("%d",&T) ;
	pows[0]=1 ;
	for(int i=1;i<MAXN;++i) pows[i] = pows[i-1] * BASE ;
	while(T--){
		init() ;
		solve() ;
	}
}
