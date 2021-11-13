#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
int n,in[maxn][3],fr[maxn],la[maxn];
struct zgb{
	int data,pos;
}s[maxn];
struct Node{
    int data;
    Node *ls,*rs;
    Node(){
        ls=rs=NULL;
        data=0;
    }
    void update()
    {
    	this->data=this->ls->data+this->rs->data;
    	return;
    }
}tree[maxn*15+5],*root,*tail=tree;
bool operator < (const zgb &a,const zgb &b)
{
	return a.data<b.data;
}
Node *build(int l,int r)
{
    Node *nd=tail++;
    if(l==r){
    	nd->data=0;
        return nd;
    }
    int mid=(l+r)>>1;
    nd->ls=build(l,mid);
    nd->rs=build(mid+1,r);
    return nd;
}
void modify(Node *nd,int l,int r,int pos,int dat)
{
	if(l==r)
	{
		nd->data+=dat;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=pos) modify(nd->ls,l,mid,pos,dat);
	else modify(nd->rs,mid+1,r,pos,dat);
	nd->update();
	return;
}
int query(Node *nd,int l,int r,int x,int y)
{
	if(x<=l&&r<=y) return nd->data;
	int mid=(l+r)>>1;
	int ans=0;
	if(mid>=x) ans+=query(nd->ls,l,mid,x,y);
	if(mid<y) ans+=query(nd->rs,mid+1,r,x,y);
	return ans;
}
int main()
{
	freopen("rotinv.in","r",stdin);
	freopen("rotinv.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&in[i][0]),s[i].pos=i,s[i].data=in[i][0];
	sort(s+1,s+1+n);
	for(int i=2;i<=n;i++)
	{
		/*if(s[i].data==s[i-1].data) in[s[i].pos][1]=in[s[i-1].pos][1];
		else in[s[i].pos][1]=in[s[i-1].pos][1]+1;//正向排序 */
		if(s[i].data!=s[i-1].data) fr[s[i].data]=i-1;
	}
	for(int i=n-1;i>=1;i--)
	{
		if(s[i].data!=s[i+1].data) la[s[i].data]=n-i;
		/*if(s[i].data==s[i+1].data) in[s[i].pos][2]=in[s[i+1].pos][2];
		else in[s[i].pos][2]=in[s[i+1].pos][2]+1;//反向排序 */
	}
	root=build(1,n);
	long long tmp=0;
	long long ans=0;
	for(int i=n;i>=1;i--)
	{
		tmp=(tmp+((in[i][0]>1)?query(root,1,n,1,in[i][0]-1):0));
		modify(root,1,n,in[i][0],1);
	}
	for(int i=1;i<=n;i++)
	{
		ans+=tmp;
		tmp=tmp-fr[in[i][0]]+la[in[i][0]];
	}
	cout<<ans<<endl;
	return 0;
}
