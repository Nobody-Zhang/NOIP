#include<bits/stdc++.h>
using namespace std;
int n,f[6005][2],fa[6005],v[6005],h[6005],cnt;      //f数组表示对于节点i，[i][0]表示不选，[i][1]表示选;fa数组存储i的父节点;v存储节点的价值;h数组存储头指针;cnt计数
struct edge{
int to,pre;
}e[6005];       //邻接表建树
int gi()   //读入优化
{
     int a=0;char x=getchar();bool f=0;
     while((x>'9'||x<'0')&&x!='-')x=getchar();
     if(x=='-')x=getchar(),f=1;
     while(x>='0'&&x<='9')a=a*10+x-48,x=getchar();
     return f?-a:a;
}
void add(int from,int to)    //建树
{
    e[++cnt].pre=h[from];
    e[cnt].to=to;
    h[from]=cnt;
}
void dp(int now)   //dp过程
{
     f[now][1]=v[now];
     for(int i=h[now];i;i=e[i].pre)
     {
         int g=e[i].to;
         dp(g);
         f[now][1]+=f[g][0];
         f[now][0]+=max(f[g][0],f[g][1]);
     }
 }
int main()
{
     n=gi();
     for(int i=1;i<=n;i++)v[i]=gi(),fa[i]=-1;
     for(int i=1;i<n;i++)
     {
         int son=gi(),father=gi();
         fa[son]=father;
         add(father,son);
     }
     int root=1;
     while(fa[root]!=-1)root=fa[root];    //找出根节点
     dp(root);
     cout<<max(f[root][0],f[root][1]);   //答案是根节点选或不选的最大值
     return 0;
}
