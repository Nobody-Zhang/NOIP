#include<bits/stdc++.h>
using namespace std;
int mp[101][101],f[101][101],m,n,as;
int u[]={0,0,1,0,-1},d[]={0,1,0,-1,0};
int s(int x,int y)
{
	if(f[x][y]>0) return f[x][y];
	int t=1;
	for(int i=1;i<=4;i++)
	 {
	 	int nx=x+u[i],ny=y+d[i];
	 	if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&mp[x][y]<mp[nx][ny])
	 	{
	 		int tmp=s(nx,ny)+1;
	 		t=max(tmp,t);
	 	}
	 }
	f[x][y]=t;
	return t;
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=n;j++)
	  cin>>mp[i][j];
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=n;j++)
	  {
	  	int t=s(i,j);
	  	f[i][j]=t;
	  	as=max(as,t);
	  }
	cout<<as<<endl;
	return 0;
}
