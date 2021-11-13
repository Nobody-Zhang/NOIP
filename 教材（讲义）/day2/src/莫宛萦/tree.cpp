#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int siz[N],val[N],a[N][2],ans=-1,n;
void dfs(int u)
{
	siz[u]=1;
	if(a[u][0]!=-1)
	{
		dfs(a[u][0]);
		siz[u]+=siz[a[u][0]];
	}
	if(a[u][1]!=-1)
	{
		dfs(a[u][1]);
		siz[u]+=siz[a[u][1]];
	}
}
bool check(int u,int v)
{
	if(u==-1&&v==-1)
	 return true;
	if(u==-1||v==-1)
	 return false;
	if(val[u]==val[v]&&check(a[u][0],a[v][1])&&check(a[u][1],a[v][0]))
	 return true;
	return false;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	 scanf("%d",&val[i]);
	for(int i=1;i<=n;i++)
	 scanf("%d%d",&a[i][0],&a[i][1]);
	dfs(1);
	for(int i=1;i<=n;i++)
	 if(check(a[i][0],a[i][1]))
	  ans=max(ans,siz[i]);
	printf("%d\n",ans);
} 
