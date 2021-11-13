#include<bits/stdc++.h>
using namespace std;
int f[200*50];//耗电量为i的照明度 
int f2[200][200];//第i到j的最大照明度 
int as[200][200];//前i个分成第j组的照明度 
int n,m,t,a[200],z[200];//a耗电量，z照明度 
int main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	cin>>n>>m>>t;//n个m组最大限度为t*个数 
	for(int i=1;i<=n;i++)
	 cin>>a[i]>>z[i];
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++)
		{
			for(int k=(n-i+1)*t;k>=a[j];k--)
			 f[k]=max(f[k],f[k-a[j]]+z[j]);
			for(int k=0;k<=(j-i+1)*t;k++)
			 f2[i][j]=max(f2[i][j],f[k]);
		}
	}
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=min(i,m);j++)
	  for(int k=j-1;k<i;k++)
	   as[i][j]=max(as[i][j],as[k][j-1]+f2[k+1][i]);
	cout<<as[n][m];
	return 0;
}
