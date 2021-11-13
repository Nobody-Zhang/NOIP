#include<cstdio>

const unsigned long long BASE = 10007 ;

unsigned long long strHash(char s[], int len){
	unsigned long long hash=0 ;
	for(int i=0;i<len;++i){
		hash = hash * BASE + s[i];
	}
	return hash ;
}

const int MAXN = 100055 , MOD = 100005 ;
long long origin[MAXN] ;
int numHash(long long a){  //a>0
	int t=a%MOD ;
	while(origin[t] && origin[t]!=a) t=(t+107)%MOD ; //可优化
	if(!origin[t]) origin[t] = a;
	return t;
}


int main(){
	;
}
