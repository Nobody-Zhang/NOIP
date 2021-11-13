#include<bits/stdc++.h>
using namespace std;
int f[11][20],v[11][20],n,m,maxx;
void show(int i,int j)//i里面选j个 
{
	if(i==0) return;
	for(int k=0;k<=j;k++)
	if(maxx==f[i-1][k]+v[i][j-k])
	{
		maxx=f[i-1][k];
		show(i-1,k);
		cout<<i<<" "<<j-k<<endl;
		return;
	}
}
int main()
{
	cin>>n>>m;//n个公司分m台机器 
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>v[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<=j;k++)
			if(f[i-1][k]+v[i][j-k]>f[i][j])
			 f[i][j]=f[i-1][k]+v[i][j-k];
		}
	}
	cout<<f[n][m]<<endl;
	maxx=f[n][m];
	show(n,m);
	return 0;
}
/*
3 3
30 40 50
20 30 50
20 25 30
*/
