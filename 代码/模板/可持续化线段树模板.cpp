#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
struct Node{
    int data;
    Node *ls,*rs;
    Node(){
        ls=rs=NULL;
        data=0;
    }
}tree[maxn*15+5],*root[maxn],*tail=tree;
int n,m,in[maxn];
Node *build(int l,int r)
{
    Node *nd=tail++;
    if(l==r){
        nd->data=in[l];
        return nd;
    }
    int mid=(l+r)>>1;
    nd->ls=build(l,mid);
    nd->rs=build(mid+1,r);
    return nd;
}
void copy(Node *to,Node *from)
{
    to->data=from->data;
    to->ls=from->ls;
    to->rs=from->rs;
    return;
}
Node *modify(Node *nd,int l,int r,int pos,int x)
{
    Node *tmp=tail++;
    copy(tmp,nd);
    if(l==r)
    {
        tmp->data=x;
        return tmp;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) tmp->ls=modify(tmp->ls,l,mid,pos,x);
    else tmp->rs=modify(tmp->rs,mid+1,r,pos,x);
    return tmp;
}
int query(Node *nd,int l,int r,int pos)
{
    if(l==r){
        return nd->data;
    }
    int mid=(l+r)>>1;
    if(mid>=pos) return query(nd->ls,l,mid,pos);
    return query(nd->rs,mid+1,r,pos);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&in[i]);
    root[0]=build(1,n);
    for(int i=1;i<=m;i++)
    {
        int inc,typ;
        scanf("%d%d",&inc,&typ);
        if(typ==1){
            int loc,val;
            scanf("%d%d",&loc,&val);
            root[i]=modify(root[inc],1,n,loc,val);
        }
        else{
            int loc;
            scanf("%d",&loc);
            printf("%d\n",query(root[inc],1,n,loc));
            root[i]=root[inc];
        }
    }
}
