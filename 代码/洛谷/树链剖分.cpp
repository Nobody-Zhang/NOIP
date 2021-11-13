#include<bits/stdc++.h>
using namespace std;
#define maxn 3000005
struct ttt{
	int data,last;
}t[maxn];
struct Node{
	int sum,tag;
	Node *ls,*rs;
	Node(){
		sum=tag=0;
		ls=rs=NULL;
	}
}tr[maxn*2+5],*root,*tail=tr;
int m,n,mod,p,num[maxn],head[maxn],inc;//p是根节点编号 
int son[maxn],father[maxn],seg[maxn],dep[maxn];
int size[maxn],rev[maxn],top[maxn];
int ans_sum;
void pushdown(Node *nd)
{
	if(nd->tag==0) return; 
	nd->ls->tag+=nd->tag;
	nd->rs->tag+=nd->tag;
	nd->tag=0;
	return;
}
void add(int a,int b)
{
	inc++;
	t[inc].data=b;
	t[inc].last=head[a];
	head[a]=inc;
	return;
}
void dfs1(int u,int f)
{
	size[u]=1;
	dep[u]=dep[f]+1;
	father[u]=f;
	for(int i=head[u];i;i=t[i].last)
	{
		int x=t[i].data;
		if(x==f) continue;
		dfs1(x,u);
		size[u]+=size[x];
		if(size[u]>size[son[u]]) son[u]=x;
	}
	return;
}
void dfs2(int u,int f)
{
	if(son[u]!=0)
	{
		inc++;
		seg[inc]=son[u];
		rev[son[u]]=inc;
		top[son[u]]=top[u];
		dfs2(son[u],u);
	}
	for(int i=head[u];i;i=t[i].last)
	{
		int x=t[i].data;
		if(x!=0&&top[x]==0)//表示没有更新 
		{
			inc++;
			seg[inc]=x;
			rev[x]=inc;
			top[x]=x;
			dfs2(x,u);
		} 
	}
	return;
}
Node *build(int l,int r)
{
	Node *nd=++tail;
	if(l==r)
	{
		nd->sum=num[seg[l]];
		return nd;
	}
	int mid=(l+r)>>1;
	nd->ls=build(l,mid);
	nd->rs=build(mid+1,r);
	nd->sum=nd->ls->sum+nd->rs->sum;
	return nd;
}
void modify(Node *nd,int l,int r,int x,int y,int val)
{
	if(x<=l&&r<=y)
	{
		nd->tag+=val;
		nd->sum+=val*(l-r+1);
		return;
	}
	pushdown(nd);
	int mid=(l+r)>>1;
	if(x<=mid) modify(nd->ls,l,mid,x,y,val);
	if(y>mid) modify(nd->rs,mid+1,r,x,y,val);
	nd->sum=(nd->ls->sum+nd->rs->sum)%mod;
	return;
} 
void query(Node*nd,int l,int r,int x,int y)
{
	if(l>=x&&r<=y) {
		ans_sum+=nd->sum;
		return;
	}
	int mid=(l+r)>>1;
   	pushdown(nd);
	if(mid>=x) query(nd->rs,l,mid,x,y);
	if(mid<y) query(nd->rs,mid+1,r,x,y);
	return;
}
void ask(int x,int y)
{
	int fx=father[x],fy=father[y];
	while(fx!=fy)
	{
		if(dep[fx]<dep[fy])
		{
			swap(fx,fy);
			swap(x,y);
		} 
		query(root,1,m,seg[fx],seg[x]);
		x=fx;
		fx=top[x];
	}
	if(dep[x]<dep[y]) swap(x,y);
	query(root,1,m,seg[x],seg[y]);
	return;
}
int main()
{
	freopen("test.in","r",stdin);
	scanf("%d%d%d%d",&m,&n,&p,&mod);
	for(int i=1;i<=m;i++)
	 scanf("%d",&num[i]);
	for(int i=1;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs1(p,0);
	inc=1;
	seg[inc]=p;
	rev[p]=inc;
	top[p]=p;
	dfs2(p,p);
	root=build(1,m);
	for(int i=1;i<=n;i++)
	{
		int point;
		scanf("%d",&point);
		if(point==1)
		{
			int x,y,val;
			scanf("%d%d%d",&x,&y,&val);
			modify(root,1,m,x,y,val);
			continue;
		}
		if(point==3)
		{
			int tp,val;
			scanf("%d%d",&tp,&val);
			modify(root,1,m,rev[tp],rev[tp]+size[tp]-1,val);
			continue;
		}
		if(point==2)
		{
			ans_sum=0;
			int x,y;
			scanf("%d%d",&x,&y);
			ask(x,y);
			printf("%d\n",ans_sum);
			continue;
		}
		if(point==4)
		{
			ans_sum=0;
			int x;
			scanf("%d",&x);
			query(root,1,m,rev[x],rev[x]+size[x]-1);
			printf("%d\n",ans_sum);
		}
	}
	return 0;
}
