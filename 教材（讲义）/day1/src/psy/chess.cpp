#include<bits/stdc++.h>
#define maxx 100005
using namespace std;
int ans=maxx,n,m;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int mapp[105][105],f[105][105];//f[i][j]:保存从起点到(i,j)的最少金币 
void dfs(int x,int y,int mon,bool judge)
{
	//剪枝 
	if(!mapp[x][y]) return ;
	if(mon>=f[x][y]) return ;//不符合最优解 
	
	if(x==m&&y==m)
	{
		ans=min(ans,mon);
		return ;
	}
	f[x][y]=mon;
	for(int i=0;i<=3;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<=0||xx>=m+1||yy<=0||yy>=m+1) continue;
		if(mapp[xx][yy])//如果这个格子有颜色 
		{
			if(mapp[xx][yy]==mapp[x][y]) //颜色相同 
			     dfs(xx,yy,mon,true);
			else dfs(xx,yy,mon+1,true);//颜色不同 
		}
		else if(judge)//可以使用魔法，直接将下一个格子变成现在这个格子的颜色（可以保持当前的最优解） 
		{
			mapp[xx][yy]=mapp[x][y];
			dfs(xx,yy,mon+2,false);
			mapp[xx][yy]=0;
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
		scanf("%d%d%d",&x,&y,&c);//红1黄2 
		mapp[x][y]=c+1;
	}
	memset(f,0x3f3f3f,sizeof(f));
	dfs(1,1,0,1);
	if(ans==maxx) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
