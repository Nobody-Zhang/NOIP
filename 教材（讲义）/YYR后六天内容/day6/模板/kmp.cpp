const int MAXN=100005 ;
int fail[MAXN] ;
void getFail(char s[], int len)
{
	fail[0]=fail[1]=0 ;
	for(int i=1;i<len;++i){
		int t=fail[i] ;
		while(t && s[t]!=s[i])	t=fail[t] ;
		fail[i+1] = (s[t]==s[i] ? t+1 : 0) ;
	}
}

int find(char s[], int len1, char t[], int len2){ //t串中s串出现次数
	getFail(s, len1) ;
	int ans=0 , now=0 ;
	for(int i=0; i<len2; ++i){
		while(now && t[i]!=s[now]) now=fail[now] ;
		if(t[i] == s[now]) now++ ;
		if(now==len1){
			ans++ , now=fail[now] ;
		}
	}
	return ans ;
}
