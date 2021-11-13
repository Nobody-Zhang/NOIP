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
int mp1[510][510],mp2[510][510],head[1000001],m,n,q,inc;
bool used[1000001];
struct s{
	int data,last;
}edge[1000001];
int tmp1,tmp2,ans,match[1000001],timer,vis[10000001];
void add(int a,int b)
{
	inc++;
	edge[inc].data=b;
	edge[inc].last=head[a];
	head[a]=inc;
}
int bfs1(int x,int from)
{
	inc++;
	for(int i=from;i<=m;i++)
	 if(mp1[x][i]!=-1) mp1[x][i]=inc;
	 else return i;
	return m;
}
int bfs2(int y,int from)
{
	inc++;
	for(int i=from;i<=n;i++)
	 if(mp2[i][y]!=-1) mp2[i][y]=inc;
	 else return i;
	return n;
}
bool dfs(int x)
{
	if(vis[x]==timer) return false;
	vis[x]=timer;
	for(int i=head[x];i;i=edge[i].last){
		int now=edge[i].data;
		if(match[now]==0||dfs(match[now])==true){
			match[now]=x;
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("ju.in","r",stdin);
	//freopen("ju.out","w",stdout);
	redi(n,m,q);
	for(int i=1;i<=q;i++)
	 {
	 	int x,y;
	 	redi(x,y);
	 	mp1[x][y]=mp2[x][y]=-1;
	 }
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  if(mp1[i][j]!=-1)
	   j=bfs1(i,j);
	tmp1=inc;
	inc++;
	/*for(int j=1;j<=m;j++)
	 for(int i=1;i<=n;i++)
	   if(mp2[i][j]!=-1)
	   {
	   		add(mp1[i][j],inc);
	   		add(inc,mp1[i][j]);
	   }
	   else inc++;*/
	for(int j=1;j<=m;j++)
	 for(int i=1;i<=n;i++)
	  if(mp2[i][j]!=-1)
	   i=bfs2(j,i);
	/*for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	  	 cout<<mp1[i][j]<<" ";
	  	cout<<endl;
	 }
	cout<<endl;
	for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	 cout<<mp2[i][j]<<" ";
	 	cout<<endl;
	 }*/
	 for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	   {
	   	add(mp1[i][j],mp2[i][j]);
	   	add(mp1[i][j],mp2[i][j]);
	   }
	tmp2=inc;
	 inc=0;
	for(int i=1;i<=tmp1;i++)
	{
		timer++;
		if(dfs(i)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
