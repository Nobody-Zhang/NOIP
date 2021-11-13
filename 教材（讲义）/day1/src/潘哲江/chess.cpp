#include <cstdio>
#include <cstring>
const int N=107,D[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int a[N][N],f[N][N];
int n,m,x,y,c;
inline int hf(int x,int y) 
{ 
	return (x<=n&&x>0&&y<=n&&y>0); 
} 
void dfs(int x,int y,int tag)
{
    for(int i=0;i<4;i++)
    {
        int dx=x+D[i][0],dy=y+D[i][1];
        if (hf(dx,dy))
        {
            if (a[dx][dy]==-1)
            {
                if(f[x][y]+2<f[dx][dy])
                {
                    f[dx][dy]=f[x][y]+2;
                    a[dx][dy]=a[x][y]; 
                    dfs(dx,dy,0); 
                    a[dx][dy]=-1; 
                }
            }
            else if(a[dx][dy]==a[x][y])
            {
                if(f[x][y]<f[dx][dy])
                {
                    f[dx][dy]=f[x][y];
                    dfs(dx,dy,1);
                }
            }
            else if(a[dx][dy]!=a[x][y])
            {
                if (f[x][y]+1<f[dx][dy])
                {
                    f[dx][dy]=f[x][y]+1; 
                    dfs(dx,dy,1);
                }
            }
        }
    }
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    memset(a,-1,sizeof(a));
    memset(f,0x3f,sizeof(f));
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&c);
        a[x][y]=c;
    }
    f[1][1]=0;
    dfs(1,1,1);
    if (f[n][n]==0x3f3f3f3f)
        printf("-1\n");
    else
        printf("%d\n",f[n][n]);
    return 0;
}
