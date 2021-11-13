#include <stdio.h>
#define maxn 100005
#define maxm 200005
struct edge
{
  int y,next;
};
int head[maxn],n,m,tot;
edge ed[2*maxm];
bool vis[maxn];
void add(int x,int y)
{
  tot++;
  ed[tot].y=y;
  ed[tot].next=head[x];
  head[x]=tot;
}
void dfs(int i)
{    
     int t;
     printf("%d ",i);
     vis[i]=1;
     t=head[i];
     if(t!=0&&vis[ed[t].y]==0)
        dfs(ed[t].y);
     while (ed[t].next!=0)
	 {
        if (!vis[ed[ed[t].next].y])//此处一定要判断,否则出现顶点多次进队 
            dfs(ed[ed[t].next].y);
        t=ed[t].next;
     }      
}
int main()
{
    freopen("graph.in","r",stdin);
    //freopen("graph.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {  int x,y;
       scanf("%d%d",&x,&y);
       add(x,y);
       add(y,x);
    } 
    for (int i=1;i<=n;i++)
	   if (!vis[i])
		{
            dfs(i);
            printf("\n");
		}	  
    return 0;
}
