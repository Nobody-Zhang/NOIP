#include<cstdio>
#include<cstring>
int c[105],w[105],f[105][1005];//f��ֵ ,cʱ�� 
int main()
{
	freopen("medic.in","r",stdin);
	freopen("medic.out","w",stdout);
	int t,m;
	memset(f,0,sizeof(f));
	scanf("%d%d",&t,&m);
	for(int i=1;i<=m;i++)
	  scanf("%d%d",&c[i],&w[i]);
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=t;j++)
	{	
		f[i][j]=f[i-1][j];   //���ɵ�i��ҩ 
		if(j-c[i]>=0&&f[i][j]<f[i-1][j-c[i]]+w[i])
		  f[i][j]=f[i-1][j-c[i]]+w[i];
	}
	printf("%d",f[m][t]);
	return 0;
}
