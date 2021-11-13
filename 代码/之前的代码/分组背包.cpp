#include<bits/stdc++.h>
using namespace std;
int w[31],c[31],a[11][32],f[201],m,v,n;
int main()
{
	cin>>v>>n>>m;//v容量，n个数 
	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>w[i]>>c[i]>>p;
		a[p][++a[p][0]]=i;
		//这里a[p][0]是第几组的个数 
		//a[p][1~a[p][0]是第几个数据 
	}
	for(int i=1;i<=m;i++)
	 for(int k=v;k>=0;k--)
	  for(int j=1;j<=a[i][0];j++)//枚举个数 
	   //这个必须在体积之内枚举，保证每个组里面 
	   //有且只有一个 
	   if(w[a[k][j]]<=k)
	   //for(int k=v;k>=w[a[k][j]];k--)
	   {
	   	int tmp=a[i][j];
	   	f[k]=max(f[k],f[k-w[tmp]]+c[tmp]);
	   }
	cout<<f[v];
	return 0;
}
/*
10 6 3
2 1 1
3 3 1
4 8 2
6 9 2
2 8 3
3 9 3
*/
