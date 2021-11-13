#include<bits/stdc++.h>
using namespace std;
//0 red 1 yellow 2 white
const int N=105;
int used[N][N],m,n,mp[N][N],dp[N][N],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
bool flag=false;

inline int read() 
{
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

void dfs(int x,int y,int tot,bool zt)
{
	if(tot>=dp[x][y]) return;
	dp[x][y]=tot;
	if(x==m&&y==m) return;
	for(int i=0;i<=3;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx==0||xx==m+1||yy==0||yy==m+1) continue;
		if(mp[xx][yy]==mp[x][y])
		dfs(xx,yy,tot,false);
		else if(mp[xx][yy])
		dfs(xx,yy,tot+1,false);
		else if(!zt)
		{
			mp[xx][yy]=mp[x][y];
			dfs(xx,yy,tot+2,true);
			mp[xx][yy]=0;
		}
	}
}

void solve()
{
	used[1][1]=1;
	dfs(1,1,0,false);
	if(dp[m][m]!=0x3f3f3f)
	printf("%d",dp[m][m]);
	else
	printf("-1");
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	m=read(),n=read();
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		mp[i][j]=0,dp[i][j]=0x3f3f3f;
	}
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		x=read(),y=read(),z=read();
		mp[x][y]=z+1;
	}
	solve();
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
*/
/*
5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0
*/
