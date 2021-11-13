#include<bits/stdc++.h>
using namespace std;

int n,m,a[105][105],q[2][1000010],ans[105][105],slx[4]={0,0,1,-1},sly[4]={1,-1,0,0};
int in[105][105];
bool vis[105][105],mag[105][105];

void bfa()
{
	memset(ans,100,sizeof(ans));
	ans[1][1]=0;
	vis[1][1]=1;
	q[0][1] = 1;
	q[1][1] = 1;
	in[1][1]=1;
	int h=0,t=1;
	do
	{
		h++;
		int x = q[0][h], y = q[1][h];
		in[x][y]--;
		if(in[x][y])	continue;
		for(int i=0;i<4;i++)
		{
			int xl = x+slx[i], yl = y+sly[i];
			if(xl>0 && xl<=m && yl>0 && yl<=m && !vis[xl][yl])
			{
				if(!a[xl][yl] && mag[x][y])	continue;
				q[0][++t] = xl;
				q[1][t] = yl;
				in[xl][yl]++;
				vis[xl][yl]=1;
				if(!a[xl][yl] && !mag[x][y])
				{
					ans[xl][yl] = ans[x][y]+2;
					a[xl][yl] = a[x][y];
					mag[xl][yl] = 1;
				}
				else if(a[xl][yl]!=a[x][y] )
					ans[xl][yl]=ans[x][y]+1;
				else
					ans[xl][yl]=ans[x][y];
			}
			else	if(xl>0 && xl<=m && yl>0 && yl<=m)
			{
				if((mag[xl][yl] && mag[x][y]) || ans[xl][yl]<ans[x][y])	continue;
				bool flag=0;
				if(mag[xl][yl] )
				{
					if(ans[xl][yl]>ans[x][y]+2)
					{
						flag=1;
						a[xl][yl]=a[x][y];
						ans[xl][yl]=ans[x][y]+2;
					}
				}
				else if(a[xl][yl]!=a[x][y])
				{
					if(ans[xl][yl]>ans[x][y]+1)
					{
						flag=1;
						ans[xl][yl]=ans[x][y]+1;
					}
					
				}
				else if(a[xl][yl]==a[x][y])
				{
					if(ans[xl][yl]>ans[x][y])
					{
						flag=1;
						ans[xl][yl]=ans[x][y];
					}
				}
				if(flag)
				{
					q[0][++t] = xl;
					q[1][t] = yl;
					in[xl][yl]++;
				}
			}
		}
	}
	while(h<t);
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n; i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y] = z+1;
	}
	if(m==1)
	{
		printf("0");
		return 0;
	}
	bfa();
	if(vis[m][m])
		printf("%d",ans[m][m]);
	else
		printf("-1");
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

5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0

8 19
1 1 0
1 2 1
2 2 0
3 2 1
3 1 0
4 1 0
5 1 0
5 2 1
6 2 0
7 2 1
7 1 0
8 1 0
8 2 0
8 3 0
8 4 0
8 5 0
8 6 0
8 7 0
8 8 0

*/
