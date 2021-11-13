#include<bits/stdc++.h>
using namespace std;
#define N 100005
struct t{int data,last;}edge[N];
int head[N],tot,m,n,used[N],num,dfn[N],low[N],belong[N];//dfn表示最早的边
stack<int>s;
vector<int>vec[N];
void add(int a,int b)
{
    tot++;
    edge[tot].data=b;
    edge[tot].last=head[a];
    head[a]=tot;
    return;
}
void tarjan(int x)
{
    int v;
    dfn[x]=low[x]=++num;
    s.push(x);
    used[x]=true;
    for(int i=head[x];i;i=edge[i].last)
    {
        v=edge[i].data;
        if(!dfn[v]){//假设没有处理过
            tarjan(v);
            low[x]=min(low[v],low[x]);//能到达的最小节点
        }
        else if(used[v]){//表示v已经在栈内也就是说找到了一个父亲节点
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x]){//表示已经到达了最上面的父亲节点 
        tot++;
        do{
            v=s.top();
            s.pop();
            belong[v]=tot;
        }while(v!=x);
    }
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        //add(b,a);
    }
    tot=0;
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    printf("总共有%d个强连通分量\n",tot);
    for(int i=1;i<=n;i++)
        vec[belong[i]].push_back(i);
    for(int i=1;i<=tot;i++)
    {
        for(vector<int>::iterator it=vec[i].begin();it!=vec[i].end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    return 0;
}
