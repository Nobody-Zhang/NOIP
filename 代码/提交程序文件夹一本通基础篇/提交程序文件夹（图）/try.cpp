#include<bits/stdc++.h>
using namespace std;
#define maxn 100
struct s
{
	int to_where,weight,last_point;
};
struct s f[maxn*2+5];
int head[maxn+5],f_size,maxx_size,size[maxn+5],tot;
bool vis[maxn+5];
void add(int from,int to,int wei)
{
	f[++f_size].to_where=to;
	f[f_size].weight=wei;
	f[f_size].last_point=head[from];
	head[from]=f_size;
}
void jl(int now)
{
	if(f[now].last_point!=0)
	 jl(f[now].last_point);
	cout<<f[now].to_where<<"������"<<f[now].weight<<endl;
}
/*void bfs(int i)
{
	int front=0,tail=1;
	
}*/
void dfs(int i)
{
	cout<<i<<" ";
	int t=head[i];
	vis[i]=1;
	if(t!=0&&vis[f[t].to_where]==0)
   // û�е�ͷ   ��δ�������� 
	 dfs(f[t].to_where);//�������� 
	while(f[t].last_point!=0)//û�������ͷ 
	{
		if(!vis[f[f[t].last_point].to_where])
		 dfs(f[f[t].last_point].to_where);
		t=f[t].last_point;
	}
}
/*void dfs(int i)
{    
     int t;
     printf("%d ",i);
     vis[i]=1;
     t=head[i];
     if(t!=0&&vis[f[t].last_point]==0)
        dfs(f[t].to_where);
     while (f[t].last_point!=0)
	 {
        if (!vis[f[f[t].last_point].to_where])//�˴�һ��Ҫ�ж�,������ֶ����ν��� 
            dfs(f[f[t].last_point].to_where);
        t=f[t].last_point;	
     }
}*/
int main()
{
	int m,n;
	//ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y;//>>z;
		z=1;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=n;i++)
	{
		if(head[i]!=0)
		cout<<"��ǰ�ĵ���"<<i<<"����Щ������"<<endl;
		else
		{
			cout<<"��ǰ�ĵ���"<<i<<"û�����κε�����"<<endl;
			continue;
		}
		jl(head[i]);
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	 if(!vis[i])
	 {
	 	dfs(i);
	 	cout<<endl;
	 }
	return 0;
}
/*
7 5
1 5 5
1 3 6
4 1 7
2 1 8
3 6 4
*/
