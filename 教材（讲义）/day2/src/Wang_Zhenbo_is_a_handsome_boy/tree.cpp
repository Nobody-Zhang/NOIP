#include<cstdio>
#define maxn 1000005
using namespace std;
struct node
{
	int l,r;
}tr[maxn];
int n,sum,tot,ans[maxn],val[maxn],son[maxn];
int max(int a,int b)
{
	return a>b?a:b;
}
void deep(int x)
{
	if(tr[x].l==-1&&tr[x].r==-1)
	return;
	if(tr[x].l!=-1)
	{
		deep(tr[x].l);
		son[x]+=son[tr[x].l];
	}
	if(tr[x].r!=-1)
	{
		deep(tr[x].r);
		son[x]+=son[tr[x].r];
	}
}
int check(int ls,int rs)
{
	if(ls==-1&&rs==-1)
	return 1;
	if(ls!=-1&&rs!=-1&&val[ls]==val[rs]&&check(tr[ls].l,tr[rs].r)&&check(tr[rs].l,tr[ls].r))
	return 1;
	return 0;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	son[i]=1;
	for(int i=1;i<=n;i++)
	scanf("%d",&val[i]);
	for(int i=1;i<=n;i++)
	{
		int ls,rs;
		scanf("%d%d",&ls,&rs);
		tr[i].l=ls;
		tr[i].r=rs;
	}
	deep(1);
	for(int i=1;i<=n;i++)
	{
		if(son[i]%2==0)continue;
		if(son[i]<=tot)continue;
		if(check(tr[i].l,tr[i].r))
		tot=max(tot,son[i]);
	}
	printf("%d",tot);
	return 0;
}
