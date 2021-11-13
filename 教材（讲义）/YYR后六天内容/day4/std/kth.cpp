#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#ifdef WIN32
#define myLL "%I64d"
#else
#define myLL "%lld"
#endif
using namespace std;

const int MAXN = 100005 ;

struct Information{
	int ll, rr, r, pos ;

	Information(int _ll=0, int _rr=0, int _r=0, int _pos=0){
		ll=_ll, rr=_rr, r=_r, pos=_pos ;
	}
};

int minPos[MAXN][22], lg2[MAXN], n, K, L, R, A[MAXN] ;
long long sum[MAXN], minn[MAXN][22] ;
priority_queue <Information> que ;

bool operator< (const Information &a, const Information &b){
	return sum[a.r]-sum[a.pos] < sum[b.r]-sum[b.pos] ;
}

void init(){
	lg2[0]=-1;
	for(int i=0;i<=n;++i){
		if(i>0) lg2[i] = ( i & (i-1) ) ? lg2[i-1] : lg2[i-1]+1 ;
		minn[i][0] = sum[i], minPos[i][0] = i ;
	}
	for(int k=1;k<=20;++k){
		for(int i=0;i<=n;++i){
			if(i+(1<<(k-1))<=n){
				minn[i][k] = min(minn[i][k-1], minn[i+(1<<(k-1))][k-1]) ;
				minPos[i][k] = (minn[i][k-1]>minn[i+(1<<(k-1))][k-1]) ? minPos[i+(1<<(k-1))][k-1] : minPos[i][k-1] ;
			}
			else
				minn[i][k] = minn[i][k-1], minPos[i][k] = minPos[i][k-1] ;
		}
	}
}

int query(int l, int r){ //返回minPos
	l=max(l,0) ;
	if(l>r) return -1 ;
	int t=lg2[r-l+1] ;
	return (minn[l][t]>minn[r-(1<<t)+1][t]) ? minPos[r-(1<<t)+1][t] : minPos[l][t] ;
}

void add(int ll, int rr, int r){
	int pos = query(r-rr,r-ll) ;
	if(pos!=-1) que.push(Information(ll,rr,r,pos)) ;
}

int main(){
	freopen("kth.in","r",stdin) ;
	freopen("kth.out","w",stdout) ;
	scanf("%d%d%d%d",&n,&K,&L,&R) ;
	for(int i=1;i<=n;++i){
		scanf("%d",&A[i]), sum[i]=sum[i-1]+A[i] ;
	}
	init() ;
	for(int i=1;i<=n;++i) add(L,R,i) ;
	long long ans=0 ;
	for(int i=1;i<=K;++i){
		Information a = que.top() ;
		que.pop() ;
		ans += (sum[a.r] - sum[a.pos]) ;
		int len = a.r-a.pos ;
		if(len!=a.ll) add(a.ll,len-1,a.r) ;
		if(len!=a.rr) add(len+1,a.rr,a.r) ;
	}
	printf(myLL"\n",ans) ;
	return 0 ;
}
