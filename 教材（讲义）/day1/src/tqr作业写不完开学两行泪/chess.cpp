#include<bits/stdc++.h>
#define fo(i,j,k) for (int i=j;i<=k;i++)
#define fr(i,j,k) for (int i=j;i>=k;i--)
#define mem(x,y) memset(x,y,sizeof(x))
#define MAXN 105
#define red 1
#define yellow 2
using namespace std;

int m,n,x,y,c;
int a[MAXN][MAXN];
int f[MAXN][MAXN];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int ans=0x7fffffff;

void dfs(int x,int y,int cnt,bool flag)
{
	if (x<1||y<1||x>m||y>m) return;
	if (a[x][y]==0) return;
	if (cnt>=f[x][y]) return;
	f[x][y]=cnt;
	if (x==m&&y==m)
	{
		ans=min(ans,cnt);
		return;
	}
	fo(i,0,3)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if (a[xx][yy])
		{
			if (a[xx][yy]==a[x][y])
				dfs(xx,yy,cnt,0);
			else dfs(xx,yy,cnt+1,0);
		}
		else
		if (!flag)
		{
			a[xx][yy]=a[x][y];
			dfs(xx,yy,cnt+2,1);
			a[xx][yy]=0;
		}
	}
}

template<class T> inline void read(T &re)
{
	re=0;T sign=1;char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');re*=sign;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	mem(f,0x7f);
	read(m);read(n);
	for (int i=1;i<=n;i++)
	{
		read(x);read(y);read(c);
		a[x][y]=c+1;
	}
	dfs(1,1,0,0);
	if (ans==0x7fffffff) printf("-1");
	else printf("%d",ans);
	return 0;
}
