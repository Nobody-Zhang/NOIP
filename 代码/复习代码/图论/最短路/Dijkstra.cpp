#include<bits/stdc++.h>
using namespace std;
#define N 101
double dis[N][N],ans[N];
int pre[N],add[N][3],m,n;
bool used[N];
int main()
{
	freopen("short.in","r",stdin);
	freopen("short_Dijkstra.out","w",stdout);
	memset(dis,0x7f,sizeof(dis));
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	 scanf("%d%d",&add[i][1],&add[i][2]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		dis[b][a]=dis[a][b]=sqrt(pow(double(add[a][1]-add[b][1]),2)
		+pow(double(add[a][2]-add[b][2]),2));
	}
	int a,b;
	scanf("%d%d",&a,&b);
	used[a]=true;
	ans[a]=0;
	for(int i=1;i<=m;i++)
	 ans[i]=dis[a][i];//先初始化全部的路程 
	for(int i=1;i<=m;i++)
	{
		double minn=0x7f;
		int tmp=0;
		for(int j=1;j<=m;j++)
		 if(used[j]==false&&dis[i][j]<minn)
		 {
		 	minn=dis[i][j];
		 	tmp=j;//求最短路 
		 }
		if(tmp==0) break;//表示当前节点没有任何和它相连的最短路径 
		used[tmp]=true;
		for(int j=1;j<=m;j++)
		//这个用来更新绕一圈回到那个点但是是最小值的那个点 
		 if(used[j]==false)
		  ans[j]=min(ans[j],ans[tmp]+dis[tmp][j]);
	}
	printf("%.2lf",ans[b]);
}
