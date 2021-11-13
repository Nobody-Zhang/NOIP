#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int d[128][128][2];
int col[128][128];
int m;
struct point{
	int x;
	int y;
	int z;
	int d;
	bool operator<(point b) const
	{
		return d>b.d;
	}
};
priority_queue<point> q;
void dijkstra()
{
	point s;
	s.x=1;
	s.y=1;
	s.z=col[1][1];
	s.d=0;
	d[1][1][col[1][1]]=0;
	q.push(s);
	while(!q.empty())
	{
		point u=q.top();
		q.pop();
		if(d[u.x][u.y][u.z]<u.d)
		{
			continue;
		}
		point v;
		v.x=u.x;
		v.y=u.y;
		if(u.x>1)
		{
			v.x--;
			if(col[v.x][v.y]<0)
			{
				v.z=u.z;
				v.d=u.d+2;
				if(col[u.x][u.y]<0)
				{
					v.d=-1;
				}
			}
			else
			{
				v.z=col[v.x][v.y];
				if(v.z==u.z)
				{
					v.d=u.d;
				}
				else
				{
					v.d=u.d+1;
				}
			}
			if(v.d>=0)
			{
				if(d[v.x][v.y][v.z]>v.d||d[v.x][v.y][v.z]<0)
				{
					d[v.x][v.y][v.z]=v.d;
					q.push(v);
				}
			}
			v.x++;
		}
		if(u.y>1)
		{
			v.y--;
			if(col[v.x][v.y]<0)
			{
				v.z=u.z;
				v.d=u.d+2;
				if(col[u.x][u.y]<0)
				{
					v.d=-1;
				}
			}
			else
			{
				v.z=col[v.x][v.y];
				if(v.z==u.z)
				{
					v.d=u.d;
				}
				else
				{
					v.d=u.d+1;
				}
			}
			if(v.d>=0)
			{
				if(d[v.x][v.y][v.z]>v.d||d[v.x][v.y][v.z]<0)
				{
					d[v.x][v.y][v.z]=v.d;
					q.push(v);
				}
			}
			v.y++;
		}
		if(u.x<m)
		{
			v.x++;
			if(col[v.x][v.y]<0)
			{
				v.z=u.z;
				v.d=u.d+2;
				if(col[u.x][u.y]<0)
				{
					v.d=-1;
				}
			}
			else
			{
				v.z=col[v.x][v.y];
				if(v.z==u.z)
				{
					v.d=u.d;
				}
				else
				{
					v.d=u.d+1;
				}
			}
			if(v.d>=0)
			{
				if(d[v.x][v.y][v.z]>v.d||d[v.x][v.y][v.z]<0)
				{
					d[v.x][v.y][v.z]=v.d;
					q.push(v);
				}
			}
			v.x--;
		}
		if(u.y<m)
		{
			v.y++;
			if(col[v.x][v.y]<0)
			{
				v.z=u.z;
				v.d=u.d+2;
				if(col[u.x][u.y]<0)
				{
					v.d=-1;
				}
			}
			else
			{
				v.z=col[v.x][v.y];
				if(v.z==u.z)
				{
					v.d=u.d;
				}
				else
				{
					v.d=u.d+1;
				}
			}
			if(v.d>=0)
			{
				if(d[v.x][v.y][v.z]>v.d||d[v.x][v.y][v.z]<0)
				{
					d[v.x][v.y][v.z]=v.d;
					q.push(v);
				}
			}
			v.y--;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n;
	scanf("%d%d",&m,&n);
	memset(d,-1,sizeof(d));
	memset(col,-1,sizeof(col));
	while(n--)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		col[x][y]=c;
	}
	dijkstra();
	int ans=d[m][m][0];
	if(d[m][m][1]>=0)
	{
		if(ans<0||ans>d[m][m][1])
		{
			ans=d[m][m][1];
		}
	}
	printf("%d\n",ans);
	return 0;
}
