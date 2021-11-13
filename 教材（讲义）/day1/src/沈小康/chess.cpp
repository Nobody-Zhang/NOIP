#include<bits/stdc++.h>
#define N 101
using namespace std;
int n,m;
int ans[N][N],color[N][N];
int dox[4]={1,0,-1,0},doy[4]={0,1,0,-1};
struct Node
{
	int cost,x,y,color;
	bool used;
}node[N*N*N];

template <class T>
void read(T &x)
{
	char c;int sign=1;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1; x=c-48;
	while((c=getchar())>='0'&&c<='9') x=(x<<1)+(x<<3)+c-48; x*=sign;
}

void bfs()
{
	int head=0,tail=1;
	node[1].cost=0;
	node[1].x=1;
	node[1].y=1;
	node[1].used=0;//初始化原点入队 
	while(head<tail)
	{
		Node now=node[++head];
		int cost=now.cost,x=now.x,y=now.y;
		if(cost>=ans[x][y]) continue;//剪枝 
		ans[x][y]=cost;//否则更新 
		for(int i=0;i<4;++i)
		{
			int dx=dox[i]+x,dy=doy[i]+y;//确定下一点 
			if(x<1||y<1||x>n||y>n) continue;//越界 
			if(!color[dx][dy])//无色 
			{
				if(now.used) continue;//用过了
				else//使用魔法 
				{
					node[++tail].used=1;
					node[tail].x=dx;
					node[tail].y=dy;
					node[tail].cost=cost+2;
					node[tail].color=color[x][y];//在这一步中，魔法指定的颜色 
				} 
			}
			else
			{
				node[++tail].used=0;
				node[tail].x=dx;
				node[tail].y=dy;
				node[tail].cost=cost;
				if(color[dx][dy]!=color[x][y]&&color[x][y]) node[tail].cost++;//两个都有颜色且不同 
				else if(now.used&&now.color!=color[dx][dy]) node[tail].cost++;//起点没有颜色 
			}
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(ans,100,sizeof(ans));
	read(n);read(m);
	for(int i=1;i<=m;++i)
	{
		int x,y,c;
		read(x);read(y);read(c);
		color[x][y]=c+1;
	}
	bfs();
	if(ans[n][n]==1684300900) cout<<-1<<endl;
	else cout<<ans[n][n]<<endl;
	return 0;
}
