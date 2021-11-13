#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
struct node{
	set<int> s;
	int mi,ma;	
	node *pl,*pr;
}tree[MAXN*12],*root=tree,*ncnt=tree;
bool used[MAXN];
struct block{
	int l,r,id,flag,x;
	block() {}
	block(int l1,int r1,int id1,int flag1,int x1):l(l1),r(r1),id(id1),flag(flag1),x(x1) {}
	bool operator < (const block&a) const{
		if(x==a.x)
			return l<a.l;
		return x<a.x;
	}
}blo[MAXN*2];
void build(node *x,int l,int r){
	x->mi=-1,x->ma=-1;
	if(l==r)	
		return ;
	int mid=(l+r)>>1;
	x->pl=++ncnt;
	build(x->pl,l,mid);
	x->pr=++ncnt;
	build(x->pr,mid+1,r);
}
void pushup(node *x){
	if(x->pl==NULL&&x->pr==NULL){
		if(x->s.empty()){
			x->ma=x->mi=-1;
			return;	
		}
		x->ma=*x->s.rbegin();
		x->mi=x->ma;
		if(used[x->ma]==1)
			x->ma=-1;
	}
	else{
		int &mi=x->mi,&ma=x->ma;
		mi=min(x->pl->mi,x->pr->mi),x->ma=max(x->pl->ma,x->pr->ma);
		if(x->s.empty())
			return ;
		int xs=*x->s.rbegin();
		mi=max(mi,xs);
		if(ma<xs){
			if(used[xs]==1)
				ma=-1;
			else{
				if(xs<mi)
					ma=-1;
				else
					ma=xs;
			}
		}
	}
}
void add(node *x,int l,int r,int l1,int r1,int val,int idx){
	if(l>=l1&&r<=r1){
		if(val==-1)
			x->s.erase(idx);
		else
			x->s.insert(idx);
		pushup(x);
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=l1)
		add(x->pl,l,mid,l1,r1,val,idx);
	if(mid<r1)
		add(x->pr,mid+1,r,l1,r1,val,idx);
	pushup(x);
}
void Update(node *x,int l,int r,int l1,int r1,int idx){
	if(l>=l1&&r<=r1){
		pushup(x);	
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=l1)
		Update(x->pl,l,mid,l1,r1,idx);
	if(mid<r1)
		Update(x->pr,mid+1,r,l1,r1,idx);
	pushup(x);
}
int n,sumx,sumy;
int apx[MAXN*6],apy[MAXN*6];
int ls[MAXN],rs[MAXN];
void pushx(int x){
	apx[++sumx]=x;
	apx[++sumx]=x-1;
	apx[++sumx]=x+1;
}
void pushy(int y){
	apy[++sumy]=y;
	apy[++sumy]=y-1;
	apy[++sumy]=y+1;	
}
int main(){
	SF("%d",&n);	
	int sx,sy,ex,ey,cnt=0;
	for(int i=1;i<=n;i++){
		SF("%d%d%d%d",&sx,&sy,&ex,&ey);
		ex--,ey--;
		blo[++cnt]=block(sy,ey,i,1,sx);
		blo[++cnt]=block(sy,ey,i,-1,ex+1);
		pushx(sx);
		pushx(ex+1);
		pushy(sy);
		pushy(ey);
	}
	sort(apx+1,apx+1+sumx);
	sort(apy+1,apy+1+sumy);
	sumx=unique(apx+1,apx+1+sumx)-(apx+1);
	sumy=unique(apy+1,apy+1+sumy)-(apy+1);
	for(int i=1;i<=cnt;i++){
		blo[i].l=lower_bound(apy+1,apy+1+sumy,blo[i].l)-apy;
		blo[i].r=lower_bound(apy+1,apy+1+sumy,blo[i].r)-apy;
		blo[i].x=lower_bound(apx+1,apx+1+sumx,blo[i].x)-apx;
	}
	for(int i=1;i<=cnt;i++){
		ls[blo[i].id]=blo[i].l;
		rs[blo[i].id]=blo[i].r;
	}
	sort(blo+1,blo+1+cnt);
	int las=1;
	build(root,1,sumy);
	/*for(int i=1;i<=cnt;i++)
		PF("{%d %d %d %d %d}\n",blo[i].l,blo[i].r,blo[i].x,blo[i].id,blo[i].flag);*/
	for(int i=1;i<=sumx;i++){
		while(las<=cnt&&blo[las].x==i){
			//PF("{%d %d %d %d}\n",blo[las].l,blo[las].r,blo[las].x,blo[las].id);
			add(root,1,sumy,blo[las].l,blo[las].r,blo[las].flag,blo[las].id);
			las++;
		}
		while(root->ma!=-1){
			int x=root->ma;
			used[x]=1;
			Update(root,1,sumy,ls[x],rs[x],x);
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++)
		if(used[i]==1)
			ans++;
	PF("%d",ans);
}
