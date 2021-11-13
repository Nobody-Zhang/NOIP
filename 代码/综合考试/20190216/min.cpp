#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void redi(T&t)
{
	register int c=getchar();t=0;
	bool flag=false;
	if(c=='-') flag=true;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=10*t+c-'0',c=getchar();
	if(flag) t=-t;
}
template <typename T,typename... Args> inline void redi(T&t,Args&... args)
{
	redi(t);
	redi(args...);
}
#define maxn 100001
struct tree{
	int data,last;
}t[maxn*4];
int n,m,head[maxn],inc,in[maxn],lar[maxn];
int edge[maxn],ser[maxn];
struct Node{
	int minn;
	Node *ls,*rs;
}tree[maxn*4+5],*tail=tree,*root;
void add(int a,int b)
{
	inc++;
	t[inc].last=head[a];
	t[inc].data=b;
	head[a]=inc;
	return;
}
void dfs(int now,int fa)
{
	edge[++edge[0]]=now;
	ser[now]=edge[0];
	lar[now]=1;
	for(int i=head[now];i;i=t[i].last)
	{
		int son=t[i].data;
		if(son==fa) continue;
		dfs(son,now);
		lar[now]+=lar[son];
	}
	return;
}
Node *build(int l,int r)
{
	Node *nd=tail++;
	if(l==r){
		nd->minn=in[edge[l]];
		return nd;
	}
	int mid=(l+r)>>1;
	nd->ls=build(l,mid);
	nd->rs=build(mid+1,r);
	nd->minn=min(nd->ls->minn,nd->rs->minn);
	return nd;
}
void change(Node *nd,int l,int r,int x,int y)
{
	if(l==r){
		nd->minn=y;
		return;
	} 
	int mid=(l+r)>>1;
	if(x<=mid){
		change(nd->ls,l,mid,x,y);
		nd->minn=min(nd->ls->minn,nd->rs->minn);
	}
	else{
		change(nd->rs,mid+1,r,x,y);
		nd->minn=min(nd->ls->minn,nd->rs->minn);
	}
	return;
}
int query(Node *nd,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
	{
		return nd->minn;
	}
	int mid=(l+r)>>1;
	int now=0x7fffffff;
	if(mid>=x)
		now=min(now,query(nd->ls,l,mid,x,y));
	if(mid<y)
		now=min(now,query(nd->rs,mid+1,r,x,y));
	return now;
}
//int n,m,head[maxn],inc,in[maxn],lar[maxn];
//int edge[maxn],ser[maxn];
void rebuild(int x)
{
	inc=0;
	memset(lar,0,sizeof(lar));
	memset(edge,0,sizeof(edge));
	memset(ser,0,sizeof(0));
	tail=tree;
	dfs(x,x);
	root=build(1,n);
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	redi(n,m);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		redi(a,b);
		in[i]=b;//�洢Ȩֵ 
		if(a==0) continue;
		add(a,i);
		add(i,a);
	}
	dfs(1,1);
	root=build(1,n);
	for(int i=1;i<=m;i++)
	{
		int flag;
		redi(flag);
		if(flag==1)
		{
			int x,y;
			redi(x,y);
			in[x]=y;
			change(root,1,n,x,y);
		}
		if(flag==2)
		{
			int x;
			redi(x);
			cout<<query(root,1,n,ser[x],ser[x]+lar[x]-1)<<endl;
		}
		if(flag==3)
		{
			int x;
			redi(x);
			rebuild(x);
		}
	}
}
