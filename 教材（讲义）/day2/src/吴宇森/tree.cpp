#include<bits/stdc++.h>
using namespace std;

const int N=1000005;
int n,v[N],l[N],r[N],size[N],ans=0;

void dfs(int x)
{
	size[x]=1;
	if(l[x]!=-1)
	{
		dfs(l[x]);
		size[x]+=size[l[x]];
	}
	if(r[x]!=-1)
	{
		dfs(r[x]);
		size[x]+=size[r[x]];
	}
}

bool judge(int x,int y)
{
	if(x==-1&&y==-1)
	return true;
	if(x!=-1&&y!=-1&&v[x]==v[y]&&judge(l[x],r[y])&&judge(r[x],l[y]))
	return true;
	return false;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&l[i],&r[i]);
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		if(judge(l[i],r[i]))
		ans=max(ans,size[i]);
	}
	printf("%d",ans);
	return 0;
}
