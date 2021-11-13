#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
int in[maxn],inc;
struct Node{
	int data;
	Node *ls,*rs;
	Node(){
		this->data=0;
		this->ls=this->rs=NULL;
	}
}tree[maxn*15+5],*tail=tree,*root[maxn];
void copy(Node *to,Node *from)
{
	to->ls=from->ls;
	to->rs=from->rs;
	to->data=from->data;
	return;
}
Node *build(int l,int r)
{
	Node *nd=tail++;
	if(l==r)
	{
		nd->data=in[l];
		return nd;
	}
	int mid=(l+r)>>1;
	nd->ls=build(l,mid);
	nd->rs=build(mid+1,r);
	return nd;
}
Node *modify(Node *nd,int l,int r,int loc,int val)
{
	Node *tmp=tail++;
	copy(tmp,nd);
	if(l==r)
	{
		tmp->data=val;
		return tmp;
	}
	int mid=(l+r)>>1;
	if(loc<=mid) tmp->ls=modify(tmp->ls,l,mid,loc,val);
	else tmp->rs=modify(tmp->rs,mid+1,r,loc,val);
	return tmp;
}
int query(Node *nd,int l,int r,int loc)
{
	if(l==r){
		return nd->data;
	}
	int mid=(l+r)>>1;
	if(loc<=mid) return query(nd->ls,l,mid,loc);
	return query(nd->rs,mid+1,r,loc);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&in[i]);
	root[0]=build(1,n);
	for(int i=1;i<=m;i++)
	{
		int his,typ;
		scanf("%d%d",&his,&typ);
		if(typ==1)
		{
			int loc,val;
			scanf("%d%d",&loc,&val);
			root[i]=modify(root[his],1,n,loc,val);
		}
		if(typ==2)
		{
			int loc;
			scanf("%d",&loc);
			printf("%d\n",query(root[his],1,n,loc));
			root[i]=root[his];
		}
	}
	return 0;
}
