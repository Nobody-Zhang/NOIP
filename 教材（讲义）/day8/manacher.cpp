const int MAXN=100005 ;
char s[MAXN<<1], t[MAXN] ;
void init(){
	s[0]='-' ;
	for(int i=1;i<2*len;i+=2){
		s[i]='#' ;
		s[i+1]=t[i/2] ;
	}
	s[2*len+1]='#';
	s[2*len+2]='+';
	s[2*len+3]='\0';
	len=2*len+1;
}

void manacher(){
	int mx=0, id ;
	for(int i=1;i<=len;++i){
		if(mx>=i) pal[i]=min(mx-i+1, pal[2*id-i]) ;
		else pal[i]=1 ;
		while(s[i-pal[i]] == s[i+pal[i]]) ++pal[i] ;
		if(i+pal[i]-1 > mx){
			mx = i+pal[i]-1, id=i ;
		}
	}
}
