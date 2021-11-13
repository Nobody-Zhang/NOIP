#include<bits/stdc++.h>
using namespace std;
int a[101][101],b[101][101],c[101][101];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
	scanf("%d",&b[i][j]);
	c[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
	for(int j=1;j<=m;j++)
	{
	c[i][j]=a[i][j]+b[i][j];
	printf("%d ",c[i][j]);
    }
    printf("\n");
	}
}
