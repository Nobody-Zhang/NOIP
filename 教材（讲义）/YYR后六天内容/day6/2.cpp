const int MAXN=500005 ;
int root, ndnum ;
int go[MAXN][26], cnt[MAXN] ;

void ins(char s[], int len){
	int now=0 ;
	for(int i=0;i<len;++i){
		int c=s[i]-'a' ;
		if(!go[now][c]){
			go[now][c] = ++ndnum ;
		}
		now = go[now][c] ;
		cnt[now] ++ ;
	}
}
