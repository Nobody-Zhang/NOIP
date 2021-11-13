#include<bits/stdc++.h>
using namespace std;
#define MAXX 1000001
#define mod 10000
int f[MAXX],g[MAXX+3][3];//f代表全覆盖，g代表覆盖没全
int main()
{
	int m;
	cin>>m;
	f[1]=1;
	f[2]=2;
	g[2][1]=g[2][2]=1;
	for(int n=3;n<=m;n++)
	{
		f[n]=f[n-1]+f[n-2]+g[n-1][1]+g[n-1][2];
		f[n]%=mod;
		g[n][1]=f[n-2]+g[n-1][2];
		g[n][1]%=mod;
		g[n][2]=f[n-2]+g[n-1][1];
		g[n][2]%=mod;
	}
	cout<<f[m];
	return 0;
}