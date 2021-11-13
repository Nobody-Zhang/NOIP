const int MAXN=100005 ;
int root, ndnum ;
int go[MAXN][26] , cnt[MAXN] ;

void init(){
	ndnum=0 ;
	root=++ndnum ;
}

void ins(char s[], int len)
{
	int now=root ;
	for(int i=0;i<len;++i){
		int c=s[i]-'a' ;
		if(!go[now][c]){
			go[now][c] = ++ndnum ;
		}
		now = go[now][c] ;
		cnt[now] ++ ;
	}
}
