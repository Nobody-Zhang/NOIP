#include<bits/stdc++.h>
#define N 42000
int n,a,b,next[N*2],to[N*2],head[N],num,size[N],father[N],ans;
void add(int false_from,int false_to){
     next[++num]=head[false_from];
     to[num]=false_to;
     head[false_from]=num;
 }
 void dfs(int x){
     size[x]=1;
     for(int i=head[x];i;i=next[i])
         if(father[x]!=to[i]){
             father[to[i]]=x;
             dfs(to[i]);
             size[x]+=size[to[i]];
         }
     if(size[x]*2>=n&&!ans)
         ans=x;
 }
int main(){
     scanf("%d",&n);
     for(int i=1;i<n;++i){
         scanf("%d%d",&a,&b);
         add(a,b);
         add(b,a);
     }
     dfs(1);
     printf("%d",ans);
     return 0;
 }
