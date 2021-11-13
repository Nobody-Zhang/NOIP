#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 500005 ;
int go[MAXN][26], cnt[MAXN], ndnum ;
char s[15] ;

void ins(char s[], int len){
	int now=0 ;
	for(int i=0;i<len;++i){
		int c=s[i]-'a' ;
		if(!go[now][c]) go[now][c]=++ndnum ;
		now = go[now][c] ;
		cnt[now]++ ;
	}
}

int query(char s[], int len){
	int now=0 ;
	for(int i=0;i<len;++i){
		int c=s[i]-'a' ;
		if(!go[now][c]) return 0 ;
		now = go[now][c] ;
	}
	return cnt[now] ;
}

int main(){
	while(gets(s) && s[0]>='a' && s[0]<='z') ins(s, strlen(s)) ;
	while(gets(s)) printf("%d\n",query(s, strlen(s))) ;
	return 0 ;
}
