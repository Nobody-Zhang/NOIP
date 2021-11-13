#include<cstdio>
#define INF 0x3f3f3f3f
#define N 103

int map[N][N],m,n,ans=INF,f[N][N];
int dx[6]={0,0,1,0,-1,0},dy[6]={0,1,0,-1,0};

inline void dfs(int x,int y,int cost,bool flag)
{
	if(cost>=f[x][y]) 
		return;
	f[x][y]=cost;
	if(x==m&&y==m) 
		return;
	for(int i=1;i<=4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx==0||xx==m+1||yy==0||yy==m+1) 
			continue;
		if(map[xx][yy]==map[x][y]) 
			dfs(xx,yy,cost,0);
		else if(map[xx][yy]) 
			dfs(xx,yy,cost+1,0);
		else if(!flag)
		{
			map[xx][yy]=map[x][y];
			dfs(xx,yy,cost+2,1);
			map[xx][yy]=0;
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		map[x][y]=c+1;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=INF;
	dfs(1,1,0,0);
	if(f[m][m]!=INF) 
		printf("%d",f[m][m]);
	else printf("-1");
}
