#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,mp[105][105],val[105][105];
int dis[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y,int sum,bool magic)
{
	if(sum>=val[x][y])return;
	val[x][y]=sum;
	if(x==n&&y==n)return;
	for(int i=0;i<=3;i++)
	{
		int xx=x+dis[i][0],yy=y+dis[i][1];
		if(xx<=0||xx>n||yy<=0||yy>n)continue;
		if(mp[xx][yy]==mp[x][y])
		dfs(xx,yy,sum,false);
		else if(mp[xx][yy]!=mp[x][y]&&mp[xx][yy]!=0)
		dfs(xx,yy,sum+1,false);
		else if(mp[xx][yy]==0&&!magic)
		{
			mp[xx][yy]=mp[x][y];
			dfs(xx,yy,sum+2,true);
			mp[xx][yy]=0;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	val[i][j]=0x3f3f3f3f;
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		mp[x][y]=c+1;
	}
	dfs(1,1,0,false);
	if(val[n][n]!=0x3f3f3f3f)
	printf("%d",val[n][n]);
	else
	printf("-1");
	return 0;
}
