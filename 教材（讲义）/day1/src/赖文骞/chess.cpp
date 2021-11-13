#include <cstdio>
#include <cstring>
#include <algorithm>
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

int m,ans=0x7f7f7f7f,best[105][105],place[105][105],add[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
bool tag=false;

void dfs(int x,int y,int sum,bool magic)
{
	if(!place[x][y]) return;
	if(sum>=best[x][y]) return;
	
	best[x][y]=sum;
	if(x==m&&y==m)
	{
		ans=std::min(ans,sum);
		tag=true;
		
		return;
	}
	
	for(int i=0;i<=3;i++)
	{
		int nx=x+add[i][0],ny=y+add[i][1];
		
		if(nx<1||nx>m||ny<1||ny>m) continue;
		if(place[nx][ny])
		{
			if(place[x][y]==place[nx][ny]) dfs(nx,ny,sum,false);
			else dfs(nx,ny,sum+1,false);
		}
		else if(!magic)
		{
			place[nx][ny]=place[x][y];
			dfs(nx,ny,sum+2,true);
			place[nx][ny]=0;
		}
	}
	
	return;
}

int main()
{
	input("chess.in");
	output("chess.out");
	int n;
	
	scanf("%d%d",&m,&n);
	while(n--)
	{
		int x,y,c;
		
		scanf("%d%d%d",&x,&y,&c);
		
		place[x][y]=c+1;
	}
	
	memset(best,0x7f,sizeof(best));
	dfs(1,1,0,false);
	
	if(tag) printf("%d",ans);
	else printf("-1");
	return 0;
}
