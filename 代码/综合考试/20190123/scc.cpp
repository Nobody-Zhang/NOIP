#pragma GCC optimize(2) 
#include<bits/stdc++.h>
using namespace std;
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
template <typename T> inline void redi(T& t)
{
	register int c=getchar();t=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=t*10+c-'0',c=getchar();
}
template <typename T,typename... Args>inline void redi(T& t,Args&... args)
{
	redi(t);
	redi(args...);
}
#define maxn 100005
#define maxm 500005
#define ll 100000
int inc,m,n,head[maxn],low[maxn],nume,dfn[maxn],tot,belong[maxn],num[maxn];
bool /*mp[maxn][maxn],*/used[maxn];//是不是有重复的边存在 
map<long long,bool>mp;
stack<int>s;
struct t{
	int data,last;
}edge[maxm];
void add(int a,int b)
{
	inc++;
	edge[inc].data=b;
	edge[inc].last=head[a];
	head[a]=inc;
	return;
}
void tarjan(int x)
{
	int v;
	s.push(x);
	used[x]=true;
	dfn[x]=low[x]=++nume;//初始化 
	for(int i=head[x];i;i=edge[i].last)
	{
		v=edge[i].data;
		if(!dfn[v]){//表示不在栈里面 
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(used[v]){//搜索到最上面的父亲了 
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(low[x]==dfn[x])
	{
		tot++;
		do{
			v=s.top();
			s.pop();
			belong[v]=tot;
			used[v]=false;
			num[tot]++;
		}while(x!=v);
	}
	return;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("scc.in","r",stdin);
	freopen("scc.out","w",stdout);
	//redi(n,m);//n点数和m边数 
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=1;i<=m;i++)
	 {
	 	scanf("%d%d",&a,&b);
	 	if(mp[a*ll+b]==true) continue;
	 	mp[a*ll+b]=true;
	 	add(a,b);
	 }
	for(int i=1;i<=n;i++)
	 if(dfn[i]==0)
	  tarjan(i);
	printf("%d\n",tot);
	sort(num+1,num+tot+1,cmp);
	for(int i=1;i<=tot;i++)
	 printf("%d ",num[i]);
	return 0;
}
