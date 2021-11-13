#include <stdio.h>
#define maxn 100005
#define maxm 200005
struct edge
{
  int y,next;
};
int head[maxn],n,m,que[maxn],tot;
edge ed[2*maxm];
bool vis[maxn];
void add(int x,int y)
{
  tot++;
  ed[tot].y=y;
  ed[tot].next=head[x];
  head[x]=tot;
}
void bfs(int i)
{
     int  front=0,rear=0;
     vis[i]=true;
     que[++rear]=i;
     while (front<rear)
     {
         int t=que[++front];
         t=head[t];
         while (t!=0)
         {
           if (!vis[ed[t].y])//此处一定要判断,否则出现顶点多次进队 
           {
           que[++rear]=ed[t].y;
           vis[ed[t].y]=true;
           }
           t=ed[t].next;
         }
     } 
     printf("%d",que[1]);
     for (int j=2;j<=rear;j++)
         printf(" %d",que[j]);
     printf("\n");
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
      if (!vis[i])bfs(i);
    return 0;
}
