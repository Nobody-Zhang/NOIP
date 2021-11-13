#include<bits/stdc++.h>
#define N 1000002
using namespace std;
int maxdep=0,tot=0;
int v[N],son[N][3],size[N];
void dfs(int x)
{
	size[x]=1;
	if(son[x][0]!=-1) 
	{
		dfs(son[x][0]);
		size[x]+=size[son[x][0]];
	}
	if(son[x][1]!=-1)
	{
		dfs(son[x][1]);
		size[x]+=size[son[x][1]];
	}

}
int check(int a,int b)
{
	if(a==-1&&b==-1) return 1;
	if(a!=-1&&b!=-1&&v[a]==v[b]&&check(son[a][0],son[b][1])&&check(son[b][0],son[a][1]))
	  return 1;
	return 0;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,maxx=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&son[i][0],&son[i][1]);
	dfs(1);
	for(int i=1;i<=n;i++)
	  if(check(son[i][0],son[i][1])) 
	    maxx=max(maxx,size[i]);
	printf("%d",maxx);
}
/*
10
2 2 5 5 5 5 4 4 2 3
9 10
-1 -1
-1 -1
-1 -1
-1 -1
-1 2
3 4
5 6
-1 -1
7 8
*/
