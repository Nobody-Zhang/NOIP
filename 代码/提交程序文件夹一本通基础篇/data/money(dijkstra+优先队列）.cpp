#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
const int maxint=999999,maxnum=2500;
struct lianjie
{
	int w[maxnum],t;
}biao[maxnum];
struct zdui
{
	int key;
	double w;
};
struct cmp
{
	bool operator()(zdui a,zdui b) { return  a.w < b.w; }
};
priority_queue<zdui,vector<zdui>,cmp>dui;
double f[maxnum][maxnum],dist[maxnum],chazhao[maxnum];
int n,m,tot,x,y;
void Dijkstra(int v)
{
	bool s[maxnum]; 
    for(int i=1;i<=n;++i)
        dist[i]=0;
	dist[v]=1;
	zdui linshi;
	linshi.w=1.0;
	linshi.key=v;
	dui.push(linshi);
    while(!dui.empty())
        {
        	linshi=dui.top();
			int u=linshi.key;
			dui.pop();
        	if(s[u]==false)
			{
			s[u]=true;
            for(int j=1;j<=biao[u].t;j++)
				{
            		int k=biao[u].w[j];
            		double newdist=dist[u]*f[u][k];
            		if (newdist>dist[k])
            			{
            			dist[k]=newdist;
            			zdui ii;
						ii.w=newdist;
            			ii.key=k;
            			if(s[k]==false)	dui.push(ii);
            			}
            	}
			}
        }
}
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		scanf("%lf",&f[x][y]);
		f[x][y]=(100-f[x][y])/100;
		f[y][x]=f[x][y];
		biao[x].w[++biao[x].t]=y;
		biao[y].w[++biao[y].t]=x;
	}
	int start,last;
	cin>>start>>last;
	Dijkstra(start);
	printf("%0.8lf",100/dist[last]);
}
