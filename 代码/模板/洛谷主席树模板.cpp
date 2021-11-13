#pragma GCC optimize(2)
#include<stdio.h>
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define maxn 200005*2
#define maxl 1;
#define maxr 200005*2
//const int maxl=-2147483648,maxr=2147483647;
map<int,int>mp;
struct Node{ 
	int size;
	Node *ls,*rs;
	Node(){
		size=0,ls=rs=NULL;
	}
	void update(){
		size=0;
		if(ls){
			size+=ls->size;
		}
		if(rs){
			size+=rs->size;
		}
	}
}tree[maxn*10],*root[maxn],*tail=tree,*null;
int n,m,in[maxn],fid[maxn];
void copy(Node *to,Node *(&from))
{
	if(!from) from=null;
	to->ls=from->ls;
	to->rs=from->rs;
	to->size=from->size;
	return;
}
Node *add(Node *nd,int l,int r,int x)
{
	Node *tmp=tail++;
	copy(tmp,nd);
	if(l==r) {
		tmp->size++;
		return tmp;
	}
	int mid=((long long)l+r)>>1;
	if(mid>=x) tmp->ls=add(nd->ls,l,mid,x);
	else tmp->rs=add(nd->rs,mid+1,r,x);
	tmp->update();
	return tmp;
}
int query(Node *nd1,Node *nd2,int l,int r,int k)
{
	if(l==r) return l;
	//if(!nd1) nd1=null;
	if(!nd1->ls) nd1->ls=null;
	if(!nd1->rs) nd1->rs=null;
	if(!nd2->ls) nd2->ls=null;
	if(!nd2->rs) nd2->rs=null;
	int tmp=nd2->ls->size-nd1->ls->size;
	int mid=((long long)l+r)>>1;
	if(tmp>=k) return query(nd1->ls,nd2->ls,l,mid,k);
	else return query(nd1->rs,nd2->rs,mid+1,r,k-tmp);
}
struct s{
	int pos,num,th;
}data[maxn];
int inc;
bool cmp(s a,s b)
{
	return a.num<b.num;
}
int id[maxn],tmpp[maxn];
int main()
{
	null=tail++;
	null->ls=null->rs=NULL;
	null->size=0;
	root[0]=null;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		root[i]=null;
		scanf("%d",&in[i]);
		data[++inc].pos=i;
		data[inc].num=in[i];
	}
	sort(data+1,data+inc+1,cmp);
	for(int i=1;i<=inc;i++)
	{
		if(!mp[data[i].num]){
			mp[data[i].num]=i;//ÅÅÐòµÄÐòÁÐ±àºÅ 
			tmpp[data[i].pos]=i;
			fid[i]=data[i].pos;
			//root[i]=add(root[i-1],1,maxr,tmpp[i]);
		}
		else{
			tmpp[data[i].pos]=mp[data[i].num];
			fid[i]=data[i].pos;
			//root[i]=add(root[i-1],1,maxr,tmpp[i]);
		}
	}
	for(int i=1;i<=inc;i++) 
		root[i]=add(root[i-1],1,maxr,tmpp[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		printf("%d\n",in[fid[query(root[x-1],root[y],1,maxr,k)]]);
	}
}
