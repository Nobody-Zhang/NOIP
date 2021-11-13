#include<bits/stdc++.h>
using namespace std;
#define N 105
#define oo 8378534
int dx[5]={0,0,-1,1},dy[5]={-1,1,0,0};
int n,m,pl[N][N],f[N][N],flag,ans=oo,ok,vis[N][N];
bool check(int x,int y)
{
	if(x>m||y>m||x<1||y<1) return true;
	return false;
}
void dfs(int x,int y,int cost,bool magic)
{
	//cout<<x<<" "<<y<<endl;
	if(cost>=f[x][y]) return;
	f[x][y]=cost;
	if(x==m&&y==m) return;
	for(int i=0;i<=3;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(check(xx,yy)) continue;
		if(pl[xx][yy]==pl[x][y])
		 dfs(xx,yy,cost,false);
		else if(pl[xx][yy])
		 dfs(xx,yy,cost+1,false);
		else if(!magic)
		 pl[xx][yy]=pl[x][y],dfs(xx,yy,cost+2,true),pl[xx][yy]=0;
	}
	
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	  f[i][j]=oo;
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		pl[x][y]=c+1;
	}
	dfs(1,1,0,false);
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
	  cout<<f[i][j]<<" ";
	  cout<<endl;
	}
	 */
	if(f[m][m]==oo) printf("-1\n");
	else printf("%d\n",f[m][m]);
	return 0;
}
/*
5 7 
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
ans 8
5 5 
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0
*/
