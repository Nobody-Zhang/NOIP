#include<vector>

const int MAXN=100005, MAXM=1005 ;
int bSize, bNum, pos[MAXN], A[MAXN], delta[MAXM] ;
vector<int> vec[MAXM] ;

void refresh(int b){ //重新更新第b个块的vec数组 
	vec[b].clear() ;
	for(int i=(b-1)*bSize+1;i<=b*bSize&&i<=n;++i){
		vec[b].push_back(A[i]) ;
	}
	sort(vec[b].begin(),vec[b].end()) ;
}

int queryBlock(int b, int x){
	return vec[b].end()-lower_bound(vec[b].begin(),vec[b].end(),x-delta[b]) ;
}

int query(int l,int r,int x){
	int ans=0 ;
	for(int i=l;i<=pos[l]*bSize && i<=r;++i){
		if(A[i]+delta[pos[l]] >= x) ans++ ; 
	}
	if(pos[r]!=pos[l]) for(int i=r;i>(pos[r]-1)*bSize;--i){
		if(A[i]+delta[pos[l]] >= x) ans++ ; 
	}
	for(int i=pos[l]+1;i<pos[r];++i){
		ans += queryBlock(i, x) ;
	}
	return ans ;
}

void add(int l,int r,int x){
	for(int i=l;i<=pos[l]*bSize && i<=r;++i){
		A[i]+=x ;
	}
	refresh(pos[l]) ;
	if(pos[r]!=pos[l]) {
		for(int i=r;i>(pos[r]-1)*bSize;--i){
			A[i]+=x ;
		}
		refresh(pos[r]) ;
	}
	for(int i=pos[l]+1;i<pos[r];++i){
		delta[i]+=x ;
	}
}

int main(){
	cin>>n>>Q ;
	bSize=(int)sqrt(n+0.5), bNum = (n-1)/bSize+1 ;
	for(int i=1;i<=n;++i) scanf("%d",&A[i]), pos[i] = (i-1)/bSize+1 ;
	for(int i=1;i<=pos[n];++i) refresh(i) ;
	
	return 0 ;
}
