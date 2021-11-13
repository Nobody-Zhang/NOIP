void ins(char s[], int len){
	int now=0 ;
	for(int i=0;i<len;++i){
		int c=s[i]-'a' ;
		if(!go[now][c]) go[now][c]=++ndnum ;
		now=go[now][c] ;
	}
}

const int MAXN=100005 ;
int head, tail, que[MAXN] ;
void getFail(){
	head=tail=0 ;
	for(int i=0;i<26;++i)
		if(go[0][i]) que[tail++]=go[0][i] ;
	while(head<tail){
		int a=que[head++] ;
		for(int i=0;i<26;++i){
			if(go[a][i]){
				int t=fail[a] ;
				while(t && !go[t][i]) t = fail[t] ;
				fail[go[a][i]] = go[t][i] ;
				que[tail++] = go[a][i] ;
			}
		}
	}
}
