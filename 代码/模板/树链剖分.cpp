#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int in[maxn],head[maxn],depth[maxn],fa[maxn],son[maxn],size[maxn],top[maxn];
int id[maxn],fid[maxn];
//id由树上节点映射到线段树上面 
//fid是反映射 
int n,m,r,mod,inc;
/*template <typename T> inline void redi(T& t)
{
	register int c=getchar();t=0;
	bool flag=false;
	if(c=='-') flag=true;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=t*10+c-'0',c=getchar();
	if(flag) t=-t;
}
template <typename T,typename... Args>inline void redi(T& t,Args&... args)
{
	redi(t);
	redi(args...);
}*/
struct tr{
	int data,last;
}edge[maxn*4+5];
struct Node{
	int sum,flag,len;
	Node *ls,*rs;
	void pushdown()
	{
		if(flag)
		{
			ls->flag=(this->flag+ls->flag)%mod;
			rs->flag=(this->flag+rs->flag)%mod;
			ls->sum=(ls->sum+this->flag*ls->len)%mod;
			rs->sum=(rs->sum+this->flag*rs->len)%mod;
			//this->sum+=len*flag;//len是管辖的区间长度 
			this->flag=0;
		}
		return;
	}
	void update()
	{
		this->sum=(this->ls->sum+this->rs->sum)%mod;
		return;
	}
}tree[maxn*4+5],*root,*tail=tree;
void add(int a,int b)
{
	inc++;
	edge[inc].data=b;
	edge[inc].last=head[a];
	head[a]=inc;
	return;
}
void dfs1(int now,int f,int deep)
{
	size[now]=1;//当前子树大小是1 
	depth[now]=deep;//存储深度 
	for(int i=head[now];i;i=edge[i].last)
	{
		int tmp=edge[i].data;
		if(tmp==f) continue;
		fa[tmp]=now;
		dfs1(tmp,now,deep+1);
		size[now]+=size[tmp];//处理子树大小 
		if(size[son[now]]<size[tmp]) son[now]=tmp;//处理重儿子 
	}
	return;
}
void dfs2(int now,int tp)
{
	id[now]=++inc;//当前节点在线段树上的编号 
	fid[inc]=now;//反映射 
	top[now]=tp;
	if(!son[now]) return;//其实我觉得可以不要，因为下面要更新 
	//这里只是减少一些运算 
	if(son[now]) dfs2(son[now],tp);
	for(int i=head[now];i;i=edge[i].last)
	{
		int tmp=edge[i].data;
		if(tmp==son[now]||tmp==fa[now]) continue;
		dfs2(tmp,tmp);
	}
	return;
}
Node *build(int l,int r)
{
	Node *nd=tail++;
	if(l==r)
	{
		nd->sum=in[fid[l]];//fid是线段树上的点在in里面的编号，在这里存储当前节点的数据  
		nd->len=1;//管辖的长度更新 
		return nd;
	}
	int mid=(l+r)>>1;
	nd->ls=build(l,mid);
	nd->rs=build(mid+1,r);
	nd->len=nd->ls->len+nd->rs->len;
	nd->update();
	return nd;
} 
void addtr(Node *nd,int l,int r,int x,int y,int z)
{
	if(x<=l&&r<=y){
		nd->sum=(nd->sum+nd->len*z)%mod;
		nd->flag=(nd->flag+z)%mod;
		return;
	}
	nd->pushdown();
	int mid=(l+r)>>1;
	if(mid>=x) addtr(nd->ls,l,mid,x,y,z);
	if(mid<y) addtr(nd->rs,mid+1,r,x,y,z);
	nd->update();
	return;
}
int query(Node *nd,int l,int r,int x,int y)
{
	int ans=0;
	if(x<=l&&r<=y){
		return nd->sum;
	}
	int mid=(l+r)>>1;
	nd->pushdown();
	if(x<=mid) ans=(ans+query(nd->ls,l,mid,x,y)%mod)%mod;
	if(mid<y) ans=(ans+query(nd->rs,mid+1,r,x,y)%mod)%mod;
	return ans;
}
void qmodify(int x,int y,int k)
{
	k%=mod;
	while(top[x]!=top[y])
	{
		if(depth[top[x]]<depth[top[y]]) swap(x,y);//x<y 
		addtr(root,1,n,id[top[x]],id[x],k);
		x=fa[top[x]];	
	}
	if(depth[x]>depth[y]) swap(x,y);
	addtr(root,1,n,id[x],id[y],k);
	return;
}
int qask(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(depth[top[x]]<depth[top[y]]) swap(x,y);
		ans=(ans+query(root,1,n,id[top[x]],id[x]))%mod;
		x=fa[top[x]];
	}
	if(depth[x]>depth[y]) swap(x,y);
	ans=(ans+query(root,1,n,id[x],id[y]))%mod;
	return ans;
}
void qtradd(int tp,int k)
{
	k%=mod;
	addtr(root,1,n,id[tp],id[tp]+size[tp]-1,k);
	return;
}
int qtrask(int tp)
{
	int ans;
	ans=query(root,1,n,id[tp],id[tp]+size[tp]-1);
	return ans;
}
int main()
{
	//freopen("test.in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&r,&mod);
	//redi(n,m,r,mod);//结点个数、操作个数、根节点序号和取模数 
	for(int i=1;i<=n;i++)
		scanf("%d",&in[i]);
		//redi(in[i]);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		//redi(a,b);
		add(a,b);
		add(b,a);//前向心存树 
	}
	dfs1(r,0,1);
	inc=0;
	dfs2(r,r);
	root=build(1,n);
	for(int i=1;i<=m;i++)
	{
		int type;
		scanf("%d",&type);
		//redi(type);
		if(type==1)
		{//1xyz表示将树从x到y结点最短路径上所有节点的值都加上z 
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			//redi(x,y,z);
			qmodify(x,y,z);
		}
		if(type==2)
		{//2xy表示求树从x到y结点最短路径上所有节点的值之和 
			int x,y;
			scanf("%d%d",&x,&y);
			//redi(x,y);
			printf("%d\n",qask(x,y));
			//cout<<qask(x,y,z)<<endl;
		}
		if(type==3)
		{//3xz表示将以x为根节点的子树内所有节点值都加上z 
			int x,y;
			scanf("%d%d",&x,&y);
			//redi(x,y);
			qtradd(x,y);
		}
		if(type==4)
		{//4x表示求以x为根节点的子树内所有节点值之和 
			int x;
			scanf("%d",&x);
			//redi(x);
			printf("%d\n",qtrask(x));
			//cout<<<<endl;
		}
	}
	return 0;
}
