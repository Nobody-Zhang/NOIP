#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 1000005, MAXM = 1005 ;
int n, Q, A[MAXN], bSize, bNum, delta[MAXM], pos[MAXN] ;
vector<int> vec[MAXM] ;

char getChar(){
	char c;
	while((c=getchar())!=EOF && isspace(c)) ;
	return c;
}

void refresh(int b){ //重新更新第b个块的B数组
	vec[b].clear() ;
	for(int i=(b-1)*bSize+1;i<=b*bSize && i<=n;++i){
		vec[b].push_back(A[i]) ;
	}
	sort(vec[b].begin(),vec[b].end()) ;
}

void add(int l,int r,int x){
	for(int i=l;i<=pos[l]*bSize&&i<=r;++i) A[i]+=x ;
	refresh(pos[l]) ;
	if(pos[r]!=pos[l]) {
		for(int i=r;i>(pos[r]-1)*bSize;--i) A[i]+=x ;
		refresh(pos[r]) ;
	}
	for(int i=pos[l]+1;i<pos[r];++i){
		delta[i]+=x ;
	}
}

int queryBlock(int b, int x){
	return vec[b].end()-lower_bound(vec[b].begin(),vec[b].end(),x-delta[b]) ;
}

int query(int l,int r,int x){
	int ans=0 ;
	for(int i=l;i<=pos[l]*bSize&&i<=r;++i){
		if(A[i]+delta[pos[l]] >= x) ans++ ;
	}
	if(pos[r]!=pos[l]) for(int i=r;i>(pos[r]-1)*bSize;--i){
		if(A[i]+delta[pos[r]] >= x) ans++ ;
	}
	for(int i=pos[l]+1;i<pos[r];++i){
		ans += queryBlock(i, x) ;
	}
	return ans ;
}

int main(){
	scanf("%d%d", &n, &Q) ;
	bSize = (int)sqrt(n+0.5), bNum = (n-1)/bSize+1 ;
	for(int i=1;i<=n;++i) scanf("%d",&A[i]), pos[i]=(i-1)/bSize+1 ;
	for(int i=1;i<=pos[n];++i) refresh(i) ;
	for(int i=1;i<=Q;++i){
		char op = getChar() ;
		int l, r, x ;
		scanf("%d%d%d",&l,&r,&x) ;
		if(op=='M'){
			add(l,r,x) ;
		}
		else if(op=='A'){
			printf("%d\n",query(l,r,x)) ;
		}
	}
}
