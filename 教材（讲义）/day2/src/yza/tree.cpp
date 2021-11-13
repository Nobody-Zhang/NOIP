#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;

int n,ans,size[maxn];
struct tree{
	int ls,rs,val;
}tr[maxn];

int max(int x,int y)
{
	return x>y?x:y;
}

bool dfs2(int l,int r)
{
	if(l==-1 && r==-1)	return 1;
	if(tr[l].val!=tr[r].val || l==-1 || r==-1)	return 0;
	if(size[l]!=size[r])	return 0;
	if(!dfs2(tr[l].ls,tr[r].rs))
		return 0;
	return dfs2(tr[l].rs,tr[r].ls);
}

void dfs(int x)
{
	size[x]=1;
	if(tr[x].ls!=-1)
	{
		dfs(tr[x].ls);
		size[x]+=size[tr[x].ls];
	}
	if(tr[x].rs!=-1)
	{
		dfs(tr[x].rs);
		size[x]+=size[tr[x].rs];
	}
	if(tr[x].ls==-1 || tr[x].rs==-1)	return;
	if(dfs2(tr[x].ls,tr[x].rs))
		ans=max(ans,size[x]);
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&tr[i].val);
	for(int i = 1;i <= n; i++)
		scanf("%d%d",&tr[i].ls,&tr[i].rs);
	dfs(1);
	printf("%d",max(ans,1));
	return 0;
}
