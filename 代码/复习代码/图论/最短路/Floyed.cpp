#include<bits/stdc++.h>
using namespace std;
#define N 101
int m,n;
double dis[N][N],add[N][3];
int main()
{
	freopen("short.in","r",stdin);
	freopen("short_Floyed.out","w",stdout);
	memset(dis,0x7f,sizeof(dis));
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	 scanf("%lf%lf",&add[i][1],&add[i][2]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		dis[b][a]=dis[a][b]=sqrt(pow(double(add[a][1]-add[b][1]),2)
		+pow(double(add[a][2]-add[b][2]),2));
	}
	for(int k=1;k<=m;k++)
	 for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)
	   if((j!=k)&&(j!=i)&&(k!=i))
	   {
	   	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	   }
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%.2lf",dis[a][b]);
	return 0;
}
