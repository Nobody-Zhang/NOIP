#include<bits/stdc++.h>
using namespace std;
int n,f[6005][2],fa[6005],v[6005],h[6005],cnt;      //f�����ʾ���ڽڵ�i��[i][0]��ʾ��ѡ��[i][1]��ʾѡ;fa����洢i�ĸ��ڵ�;v�洢�ڵ�ļ�ֵ;h����洢ͷָ��;cnt����
struct edge{
int to,pre;
}e[6005];       //�ڽӱ���
int gi()   //�����Ż�
{
     int a=0;char x=getchar();bool f=0;
     while((x>'9'||x<'0')&&x!='-')x=getchar();
     if(x=='-')x=getchar(),f=1;
     while(x>='0'&&x<='9')a=a*10+x-48,x=getchar();
     return f?-a:a;
}
void add(int from,int to)    //����
{
    e[++cnt].pre=h[from];
    e[cnt].to=to;
    h[from]=cnt;
}
void dp(int now)   //dp����
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
     while(fa[root]!=-1)root=fa[root];    //�ҳ����ڵ�
     dp(root);
     cout<<max(f[root][0],f[root][1]);   //���Ǹ��ڵ�ѡ��ѡ�����ֵ
     return 0;
}
