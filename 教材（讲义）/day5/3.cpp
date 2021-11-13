const int MAXN=500005 ;
struct Question{
	int l, r, index ;
}Q[MAXN];

int n, bSize ;

bool cmp(const Question &a, const Question &b){
	if(pos[a.l]==pos[b.l]) return a.r<b.r ;
	else return pos[a.l]<pos[b.l] ;
}

int nowL, nowR, nowAns, cnt[1000005], ans[MAXN] ;

void add(int pos){
	if(++cnt[A[pos]]==1) nowAns++ ;
}

void del(int pos){
	if(--cnt[A[pos]]==0) nowAns-- ;
}

int main(){
	scanf("%d",&n) ;
	bSize = sqrt(n+0.5) ;
	for(int i=1;i<=n;++i){
		scanf("%d",&A[i]) , pos[i]=(i-1)/bSize+1 ;
	}
	scanf("%d",&m) ;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&Q[i].l,&Q[i].r) ;
		Q[i].index=i ;
	}
	sort(Q+1,Q+m+1,cmp) ;
	nowL=1, nowR=1, cnt[A[1]]=1, nowAns=1 ;
	for(int i=1;i<=m;++i){
		while(nowL>Q[i].l) add(--nowL) ;
		while(nowR<Q[i].r) add(++nowR) ;
		while(nowL<Q[i].l) del(nowL++) ;
		while(nowR>Q[i].r) del[nowR--) ;
		ans[Q[i].index] = nowAns ;
	}
	for(int i=1;i<=m;++i)
		printf("%d\n",ans[i]) ;
}
