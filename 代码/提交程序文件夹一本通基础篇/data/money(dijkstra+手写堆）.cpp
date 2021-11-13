#include<cstdio>
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
}dui[maxnum];
double f[maxnum][maxnum],dist[maxnum],chazhao[maxnum];
int n,m,tot,x,y;
void put(double value,int biaoji)
{
	tot++;
	dui[tot].w=value;
	dui[tot].key=biaoji;
	int next=tot;
	while(next>1)
	{
		if(dui[next/2].w>dui[next].w)break;
		zdui h=dui[next];
		dui[next]=dui[next/2];
		dui[next/2]=h;
		next=next/2;
	}
}
void get()
{
	dui[1]=dui[tot];
	tot--;
	int next=1;
	while(2*next<=tot)
	{
		next*=2;
		if(next<tot&&dui[next+1].w>dui[next].w)next++;
		if(dui[next/2].w>dui[next].w)break;
		zdui h=dui[next];
		dui[next]=dui[next/2];
		dui[next/2]=h;
	}
}
void Dijkstra(int v)
{
	bool s[maxnum]; 
    for(int i=1;i<=n;++i)
        dist[i]=0;
	dist[v]=1;
	put(1,v);
    while(tot>0)
        {
        	int u=dui[1].key;
			get();
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
            			if(s[k]==false)	put(newdist,k);
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
