#include<bits/stdc++.h>
using namespace std;
#define maxx 100005
#define mod 1000000007
struct Node{
	long long sum,sum2,mul,modify;
	int inc;
	Node *ls,*rs;
	void mulnow(long long data)
	{
		this->mul=(this->mul*data)%mod;
		this->modify=(this->sum+data)%mod;
		this->sum=(this->sum+(data*this->inc)%mod)%mod;
		this->sum2=((this->sum2*data)%mod*data)%mod;
	}
	void addnow(long long data)
	{
		this->sum2=(this->sum2+(2*data*this->sum)%mod+(this->inc*(data*data%mod))%mod)%mod;
		this->sum=(this->sum+(this->inc*data)%mod)%mod;
		this->modify=(this->modify+data)%mod;
	}
	void pushdown()
	{
		if(this->mul!=1)
		{
			this->ls->mulnow(this->mul);
			this->rs->mulnow(this->mul);
			this->mul=1;
		}
		if(this->modify!=0)
		{
			this->ls->addnow(this->modify);
			this->rs->addnow(this->modify);
			this->modify=0;
		}
	}
	void update()
	{
		this->sum=(this->ls->sum+this->rs->sum)%mod;
		this->sum2=(this->ls->sum2+this->rs->sum2)%mod;
	}
}tree[maxx<<2],*root,*tail=tree;
int n,m,in[maxx];
Node *build(int l,int r)
{
	Node *nd=tail++;
	if(l==r)
	{
		nd->sum=in[l];
		nd->inc=1;
		nd->sum2=(in[l]*in[l])%mod;
		nd->mul=1;
		nd->modify=0;
	}
	else
	{
		int mid=(l+r)>>1;
		nd->ls=build(l,mid);
		nd->rs=build(mid+1,r);
		nd->inc=nd->ls->inc+nd->rs->inc;
		nd->update();
		nd->mul=1;
		nd->modify=0;
	}
	return nd;
}
void add(Node *nd,int l,int r,int x,int y,long long z)
{
	if(x<=l&&r<=y)
	{
		nd->addnow(z);
		return;
	}
	nd->pushdown();
	int mid=(l+r)>>1;
	if(x<=mid){
		add(nd->ls,l,mid,x,y,z);
	}
	if(mid<y){
		add(nd->rs,mid+1,r,x,y,z);
	}
	nd->update();
	return;
}
void mull(Node *nd,int l,int r,int x,int y,long long z)
{
	if(x<=l&&r<=y)
	{
		nd->mulnow(z);
		return;
	}
	nd->pushdown();
	int mid=(l+r)>>1;
	if(x<=mid){
		mull(nd->ls,l,mid,x,y,z);
	}
	if(mid<y){
		mull(nd->rs,mid+1,r,x,y,z);
	}
	nd->update();
	return;
}
long long ask(Node *nd,int l,int r,int x,int y)
{
	if(x<=l&&r<=y) return nd->sum2;
	nd->pushdown();
	int mid=(l+r)>>1;
	long long ans=0;
	if(l<=mid) ans=(ans+ask(nd->ls,l,mid,x,y)%mod)%mod;
	if(mid<r) ans=(ans+ask(nd->rs,mid+1,r,x,y)%mod)%mod;
	return ans;
}
int main()
{
	freopen("sum.in","r",stdin);
//	freopen("sum.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&in[i]);
	root=build(1,n);
	for(int i=1;i<=m;i++)
	{
		int flag;
		scanf("%d",&flag);
		if(flag==1)
		{
			int x,y;long long z;
			scanf("%d%d",&x,&y);cin>>z;
			add(root,1,n,x,y,z);
		}
		else if(flag==2)
		{
			int x,y;long long z;
			scanf("%d%d",&x,&y);cin>>z;
			mull(root,1,n,x,y,z);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			cout<<ask(root,1,n,x,y)<<endl;
		}
	}
	return 0;
}
