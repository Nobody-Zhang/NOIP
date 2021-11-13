#include<bits/stdc++.h>
#define N 4200
 struct hehe{
     int next;
     int to;
 }edge[N];
 int num_edge,head[N],dis[N],n,a,b,y;
 int add_edge(int from,int to){
     edge[++num_edge].next=head[from];
     edge[num_edge].to=to;
     head[from]=num_edge;
 }
 int dfs(int x){
     for(int i=head[x];i;i=edge[i].next)
         if(!dis[edge[i].to]){
             dis[edge[i].to]=dis[x]+1;
             dfs(edge[i].to);
         }
 }
 int main(){
     scanf("%d",&n);
     for(int i=1;i<n;++i){
         scanf("%d%d",&a,&b);
         add_edge(a,b);
         add_edge(b,a);
     }
     dfs(1);
     for(int i=y=1;i<=n;i++)
         if(dis[i]>dis[y])
             y=i;
     memset(dis,0,sizeof(dis));
     dfs(y);
     for(int i=y=1;i<=n;i++)
         if(dis[i]>dis[y])
             y=i;
     printf("%d",dis[y]);
     return 0;
 } 
