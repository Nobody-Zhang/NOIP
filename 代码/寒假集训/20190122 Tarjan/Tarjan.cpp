#include<bits/stdc++.h>
using namespace std;
#define N 100005
struct t{int data,last;}edge[N];
int head[N],tot,m,n,used[N],num,dfn[N],low[N],belong[N];//dfn��ʾ����ı�
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
        if(!dfn[v]){//����û�д����
            tarjan(v);
            low[x]=min(low[v],low[x]);//�ܵ������С�ڵ�
        }
        else if(used[v]){//��ʾv�Ѿ���ջ��Ҳ����˵�ҵ���һ�����׽ڵ�
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x]){//��ʾ�Ѿ�������������ĸ��׽ڵ� 
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
    printf("�ܹ���%d��ǿ��ͨ����\n",tot);
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
