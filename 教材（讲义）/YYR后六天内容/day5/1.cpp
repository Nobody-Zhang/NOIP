void copyNode(int a,int b){
	lc[a]=lc[b], rc[a]=rc[b], sum[a]=sum[b] ;
}

int m_pos, m_num ;
int modify(int s,int ll,int rr){
	int t=++ndnum ;
	copyNode(t,s) ;
	if(ll==rr){
		sum[t] = m_num ;
		return t ;
	}
	if(m_pos<=mid) lc[t] = modify(lc[t],ll,mid) ;
	else rc[t] = modify(rc[t],mid+1,rr) ;
	update(t) ;
	return t;
}

int main(){
	int n,m ;
	cin>>n>>m ;
	for(int i=1;i<=n;++i) cin>>A[i] ;
	build(root[0]=++ndnum,1,n) ;
	for(int i=1;i<=m;++i){
		int op;
		cin>>op ;
		if(op==1){ 		//ÐÞ¸Ä 
			int x, pos, val ;
			cin>>x>>pos>>val ;
			m_pos=pos, m_num=val;
			root[i]=modify(root[x],1,n) ;
		}
		else if(op==2){ //²éÑ¯ 
			int x,l,r ;
			cin>>x>>l>>r ;
			q_l=l, q_r=r;
			printf("%d\n",query(root[x],1,n)) ;
			root[i]=root[i-1] ;
		}
	}
}
