#include<stdio.h>
#include<ctype.h>
#define N 1000003
struct Node{
	int l,r;
	int size,val;
}tr[N];
int n,maxx;

inline void read(int &x){
    x=0;int f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    x*=f;
}
inline void dfs(int u){
	tr[u].size=1;
	if(tr[u].l!=-1){
		dfs(tr[u].l);
		tr[u].size+=tr[tr[u].l].size;
	}
	if(tr[u].r!=-1){
		dfs(tr[u].r);
		tr[u].size+=tr[tr[u].r].size;
	}
}
inline int max(int x,int y){
	return x>y? x:y;
}
inline bool check(int u,int v){
	if(u==-1&&v==-1) return true;
	if(tr[u].size!=tr[v].size) return false;
	if(tr[v].val!=tr[u].val) return false;
	return check(tr[u].l,tr[v].r)&&check(tr[u].r,tr[v].l);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(tr[i].val);
	for(int i=1;i<=n;i++) read(tr[i].l),read(tr[i].r);
	dfs(1);
	for(int i=1;i<=n;i++)
		if(check(tr[i].l,tr[i].r))
			maxx=max(maxx,tr[i].size);
	printf("%d",maxx);
}
