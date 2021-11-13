#include<bits/stdc++.h>
using namespace std;
int color[103][103],d[103][103][5],m;
struct Z{
	int x,y,z,d;
	bool operator<(Z b) const
	{
		return d>b.d;
	}
};
priority_queue<Z> q;//类似于一个贪心的思想,按照d从小到大排,毕竟d越小越好 
void dijkstra()
{
	Z s;
	s.x=1;
	s.y=1;
	s.z=color[1][1];
	s.d=0;
	d[1][1][color[1][1]]=0;
	q.push(s);
	
	while(!q.empty())
	{
		Z u=q.top();
		q.pop();
		if(d[u.x][u.y][u.z]<u.d) continue;
		Z v;
		v.x=u.x;
		v.y=u.y;
		if(u.x>1)
		{
			v.x--;
			if(color[v.x][v.y]<0)
			{
				v.z=u.z;
				v.d=u.d+2;
				if(color[u.x][u.y]<0)
			      v.d=-1;
			}
			else 
			{
				v.z=color[v.x][v.y];
				if(v.z==u.z) v.d=u.d;
				else v.d=u.d+1;
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
			if(color[v.x][v.y]<0)
			{
				v.z=u.z;
				v.d=u.d+2;
				if(color[u.x][u.y]<0)
			      v.d=-1;
			} 
			else 
			{
				v.z=color[v.x][v.y];
				if(v.z==u.z) v.d=u.d;
				else v.d=u.d+1;
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
			if(color[v.x][v.y]<0)
			{
				v.z=u.z;
				v.d=u.d+2;
				if(color[u.x][u.y]<0)
			      v.d=-1;
			} 
			else 
			{
				v.z=color[v.x][v.y];
				if(v.z==u.z) v.d=u.d;
				else v.d=u.d+1;
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
			if(color[v.x][v.y]<0)
			{
				v.z=u.z;
				v.d=u.d+2;
				if(color[u.x][u.y]<0)
			      v.d=-1;
			} 
			else 
			{
				v.z=color[v.x][v.y];
				if(v.z==u.z) v.d=u.d;
				else v.d=u.d+1;
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
	memset(color,-1,sizeof(color));
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		color[x][y]=c;
	}
	dijkstra();
/*	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
	  	printf("%d ",d[i][j][0]);
	  	printf("\n");
	}*/
	  
	int ans=d[m][m][0];
	if(d[m][m][1]>=0)
	{
		if(ans<0||ans>d[m][m][1])
		  ans=d[m][m][1];
	}
	printf("%d",ans);
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
