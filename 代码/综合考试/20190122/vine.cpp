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
#define N 500005
int t,m,n,inc,tot,head[N],point[N],ans;
struct tr{
	int data,last;
}edge[N];
bool used[N],used_point[N];
void add(int a,int b)
{
	inc++;
	edge[inc].data=b;
	edge[inc].last=head[a];
	head[a]=inc;
}
queue<int> q;
int len[N];
void dfs(int u)
{
	for(int i=head[u];i;i=edge[i].last)
	{
		int now=edge[i].data;
		if(used_point[now]==false){
			used_point[now]=true;
			dfs(now);
		}
	}
}
int main()
{
	freopen("vine.in","r",stdin);
	freopen("vine.out","w",stdout);
	redi(t);
	for(int i=1;i<=t;i++){
		redi(m,n);
		for(int j=1;j<=m;j++)
		 head[j]=point[j]=0;
		for(int j=1;j<=n;j++)
		 used[j]=false;
		inc=0;
		for(int j=1;j<=n;j++){
			int a,b;
			redi(a,b);
			add(a,b);
			add(b,a);
			point[a]++;
			point[b]++;
		}
		inc=0;
		for(int j=1;j<=m;j++){
		 	if(used_point[j]==false&&point[j]!=0){
		 		tot++;
				dfs(j);
		 	}
		 	if(point[j]%2==1) inc++; 
		}
		if(point[0]==0) ans=2;
		ans+=2*inc;
		ans+=tot;
		printf("%d\n",inc);
	}
	return 0;
}
