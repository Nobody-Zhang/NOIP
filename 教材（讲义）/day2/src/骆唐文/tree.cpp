#include<cstdio>
#include<algorithm>
using namespace std;

struct sir
{
	int lson,rson,val,siz;
};
sir poi[1000001];
int n,ans=0;

void getsize (int node)
{
	poi[node].siz=1;
	if (poi[node].lson!=-1)
	{
		getsize (poi[node].lson);
		poi[node].siz+=poi[poi[node].lson].siz;
	}
	if (poi[node].rson!=-1)
	{
		getsize (poi[node].rson);
		poi[node].siz+=poi[poi[node].rson].siz;
	}
}
bool dfs (int l,int r)
{
	if (l==-1&&r==-1)
		return 1;
	if (l==-1||r==-1)
		return 0;
	if (poi[l].val==poi[r].val)
		return dfs (poi[l].rson,poi[r].lson)&&dfs (poi[l].lson,poi[r].rson);
	return 0;
}

int main()
{
	freopen ("tree.in","r",stdin);
	freopen ("tree.out","w",stdout);
	scanf ("%d",&n);
	for (register int i=1;i<=n;i++)
		scanf ("%d",&poi[i].val);
	for (register int i=1;i<=n;i++)
		scanf ("%d%d",&poi[i].lson,&poi[i].rson);
	getsize (1);
	for (register int i=1;i<=n;i++)
		if (dfs(poi[i].lson,poi[i].rson))
			ans=max (ans,poi[i].siz);
	printf ("%d",ans);
	return 0;
}
