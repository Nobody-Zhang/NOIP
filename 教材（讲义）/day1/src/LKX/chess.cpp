#include<bits/stdc++.h>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int m,ans=0x3f3f3f;
int mp[102][102];
int f[102][102];

void dfs(int x,int y,int sum,bool frog)
{
	if(x<1||y<1||y>m||x>m) return; 
	if(sum>=f[x][y]) return;
	f[x][y]=sum;
	if(x==m&&y==m)
	{
		if(sum<ans)
		ans=sum;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&yy<=m&&xx<=m&&yy>=1)
		{
			if(mp[xx][yy])
			{
				if(mp[x][y]==mp[xx][yy])
				dfs(xx,yy,sum,false);
				else dfs(xx,yy,sum+1,false);
			}
			else
			{
				if(!frog)
				{
					mp[xx][yy]=mp[x][y];
					dfs(xx,yy,sum+2,true);
					mp[xx][yy]=0;
				}
			}
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n;
	memset(f,0x3f3f3f,sizeof(f));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		mp[x][y]=c+1;// 1红色 2黄色 0无色（未赋值，其初值为0）
	}//推走的话，现在推的与上一个的颜色有关 
	
	dfs(1,1,0,false);
	
	if(ans==0x3f3f3f) printf("-1");
	else printf("%d\n",ans);
	
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
*/
