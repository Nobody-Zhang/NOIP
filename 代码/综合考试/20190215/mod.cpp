#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxn 100004
struct tr{
	long long data;
	tr *ls,*rs;
	void update()
	{
		data=(ls->data+rs->data);
		return;
	}
}tree[maxn*2+5],*root,*tail=tree;
int n,m,in[maxn];
template <typename T> inline void redi(T&t)
{
	register int c=getchar();t=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=10*t+c-'0',c=getchar();
}
template <typename T,typename... Args> inline void redi(T&t,Args&... args)
{
	redi(t);
	redi(args...);
}
tr *build(int l,int r)
{
	tr *nd=tail++;
	if(l==r) nd->data=in[l];
	else{
		int mid=(l+r)>>1;
		nd->ls=build(l,mid);
		nd->rs=build(mid+1,r);
		nd->update();
	}
	return nd;
}
long long query(tr *nd,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
		return nd->data;
	int mid=(l+r)>>1;
	long long ans=0;
	if(x<=mid){
		ans+=query(nd->ls,l,mid,x,y);
	}
	if(y>mid){
		ans+=query(nd->rs,mid+1,r,x,y);
	}
	return ans;
}
void modify(tr *nd,int l,int r,int x,int y,int z)
{//modz
	if(nd->data<z) return;
	if(l==r){
		nd->data%=z;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
	{
		modify(nd->ls,l,mid,x,y,z);
	}
	if(y>mid)
	{
		modify(nd->rs,mid+1,r,x,y,z);
	}
	nd->update();
	return;
}
void change(tr *nd,int l,int r,int x,int y)
{
	if(l==r)
	{
		nd->data=y;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid){
		change(nd->ls,l,mid,x,y);
	}
	else{
		change(nd->rs,mid+1,r,x,y);
	}
	nd->update();
}
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	redi(n,m);
	for(int i=1;i<=n;i++) redi(in[i]);
	root=build(1,n);
	for(int i=1;i<=m;i++)
	{
		int point;
		redi(point);
		if(point==1)
		{
			int x,y;
			redi(x,y);
			cout<<query(root,1,n,x,y)<<endl;
		}
		if(point==2)
		{
			int x,y,z;
			redi(x,y,z);
			modify(root,1,n,x,y,z);
		}
		if(point==3)
		{
			int x,y;
			redi(x,y);
			change(root,1,n,x,y);
		}
	}
}
