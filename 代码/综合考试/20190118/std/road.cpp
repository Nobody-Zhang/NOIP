#include<bits/stdc++.h>
#define oo 99999999
using namespace std;

int n,pos;
bool vis[5005];
double ans,MIN=oo,dis[5005];
struct tqr{int x,y;}point[5005];

double Distance(int a,int b){return sqrt((double)(point[a].x-point[b].x)*(point[a].x-point[b].x)+(double)(point[a].y-point[b].y)*(point[a].y-point[b].y));}

template<class T> inline void read(T &re){re=0;T sign=1;char tmp;while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;re=tmp-'0';while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');re*=sign;}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	for (int i=1;i<=n;i++){read(point[i].x);read(point[i].y);dis[i]=oo;}//读入和初始化
	dis[1]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) if(!vis[j]&&dis[j]<MIN) MIN=dis[j],pos=j;
		ans+=MIN; vis[pos]=1;MIN=oo;
		for (int j=1;j<=n;j++) dis[j]=min(dis[j],Distance(pos,j));
	}
	printf("%.2lf\n",ans);
	return 0;
}