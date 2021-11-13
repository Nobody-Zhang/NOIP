#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define M 5000
int next[M],pre[M],last[M],apple[M],dp[M][M],n,m,tot=0;
/*
dp[i][j]��ʾ�ڵ�i����j��֦������ʣƻ�����ֵ
apple[i]��ʾ��i�����ϵ�ƻ����
next,pre,last���������ߵ�����
tot��ͳ�Ʊߵ����
*/
void add (int u,int v,int w)
{
    tot++;
    next[tot]=v;
    apple[tot]=w;
    pre[tot]=last[u];
    last[u]=tot;
    
}
void dfs (int u,int father)
{
    int ans=0;//ans��ʾu�ڵ���ӽڵ���Ŀ 
    for (int i=last[u];i!=0;i=pre[i])
    {
        int v=next[i],value=apple[i];
        if(v == father)continue;//�����һ�����ڽڵ���Ǹ��ڵ㣬��֤�����ײ��ˣ���ʼ�ݹ鸸�ڵ���ֵܽڵ�
       //�ݹ鵽���ϲ�ĸ��ڵ�1
       dfs(v,u);
        for(int j=m;j>=1;--j)//��Ϊ������֦������Ŀ��ȡ��min
        {
            for(int k=j;k>=1;--k)
           { dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k-1]+value);
           // printf("u=%d j=%d u=%d j-k=%d v=%d k-1=%d value=%d dp[u][j]=%d\n",u,j,u,j-k,v,k-1,value,dp[u][j]);
            } 
/*
����u�ڵ��µ��ӽڵ�j����j��������֦�����Ž���dp
������ú�˵���£���Ϊ�����������ǰ��յݹ齨������
���бȽ�ʱ��dp[u][j]����ǰ��ѡ���i����ӽڵ�õ������Ž���
����dp��ʱ�򲻿����ظ�����©��ĳ�ڵ�
*/
        }
    }  
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;++i)
    {
        int x,y,value;
        scanf("%d%d%d",&x,&y,&value);
        add(x,y,value);
        add(y,x,value);
    }
    dfs(1,0);
    printf("%d\n",dp[1][m]);
    return 0;
}
