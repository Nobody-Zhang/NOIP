#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n,ans=-1000;
int val[maxn],tr[maxn][2],w[maxn];
void dfs(int i)
{
	w[i]=1;
	if(tr[i][0]!=-1)
	{
		dfs(tr[i][0]);
		w[i]+=w[tr[i][0]];
	}
	if(tr[i][1]!=-1)
	{
		dfs(tr[i][1]);
		w[i]+=w[tr[i][1]];
	}
}
bool check(int u,int v)
{
	if(u==-1&&v==-1) return true;
	if(u!=-1&&v!=-1&&val[u]==val[v]&&check(tr[u][0],tr[v][1])&&check(tr[u][1],tr[v][0]))
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
	scanf("%d%d",&tr[i][0],&tr[i][1]);
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		if(check(tr[i][0],tr[i][1]))
		ans=max(ans,w[i]);
	}
	printf("%d",ans);
} 
