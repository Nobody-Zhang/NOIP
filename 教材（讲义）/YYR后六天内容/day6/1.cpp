const unsigned long long BASE = 10007, MAXN = 100005 ;

unsigned long long pre[MAXN] ;
unsigned long long strHash(char s[], int len){
	unsigned long long hash=0 ;
	for(int i=0;i<len;++i){
		hash = hash * BASE + s[i] ;
		pre[i] = hash ;
	}
	return hash ;
}





const int MAXN = 100055, MOD = 100007 ;
long long origin[MAXN] ;
int numHash(long long a, bool f){
	int t = a%MOD ;
	while(origin[t]!=-1 && origin[t]!=a) t=(t+107)%MOD ;
	if(origin[t]==-1 && f) origin[t]=a ;
	return t; 
}
