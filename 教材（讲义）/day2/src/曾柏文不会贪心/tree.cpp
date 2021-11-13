#include<bits/stdc++.h>

#define maxn 1100000

using namespace std;

struct tree
{
	int to,pre;
}e[maxn*2];

int du[maxn],n,val[maxn],head[maxn],cnt=0,size[maxn],father[maxn],power[maxn];

bool used[maxn];

void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].pre=head[x];
	head[x]=cnt;
}

void dfs(int x,int fa)
{
	power[x]=val[x];
	size[x]=1;
	for(int i=head[x];i;i=e[i].pre)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,x);
		size[x]+=size[v];
		power[x]+=power[v];
	}
	if(size[x]%2==0) { used[x]=false;return;}
	if(du[x]%2==1) { used[x]=false;return;}
	if(du[x]==2)
	{
		int v=e[head[x]].to;
		int past=e[head[x]].pre;
		if(val[v]!=val[e[past].to]) { used[x]=false;return;}
		if(power[v]!=power[e[past].to]) { used[x]=false;return;}
	}
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	memset(used,true,sizeof(used));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x!=-1) add(i,x),father[x]=i,du[i]++;
		if(y!=-1) add(i,y),father[y]=i,du[i]++;
	}
	dfs(1,1);
	int maxx=0;
	for(int i=1;i<=n;i++)
		if(used[i])
			if(size[i]>maxx)
				maxx=size[i];
	printf("%d",maxx);
	
	return 0;
}

/*
7
1 3 3 1 2 1 2
2 3
4 5
6 7
-1 -1
-1 -1
-1 -1
-1 -1
*/
