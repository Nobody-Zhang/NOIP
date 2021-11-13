#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
long long n,p,c,as,place[501],mp[801][801];
void add(int x,int y,int z)
{
	mp[x][y]=z;
	mp[y][x]=z;
}
int main()
{
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	IOS;
	as=9999999;
	cin>>n>>p>>c;//输入奶牛数，牧场数，牧场间道路数 
	#pragma omp parallel for
	for(int i=1;i<=800;i++)
	 for(int j=1;j<=800;j++)
	  mp[i][j]=99999999;
	for(int i=1;i<=p;i++)
	 mp[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		place[x]++;
	}
	for(int i=1;i<=c;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	for(int k=1;k<=p;k++)
	 for(int i=1;i<=p;i++)
	  for(int j=1;j<=i;j++)
	   if(mp[i][j]>mp[i][k]+mp[k][j])
	   {
	   	mp[i][j]=mp[i][k]+mp[k][j];
	   	mp[j][i]=mp[i][j];
	   }
	for(int i=1;i<=p;i++)
	{
		long long mo=0;
		for(int j=1;j<=p;j++)
		 mo+=mp[i][j]*place[j];
		if(as>mo) as=mo;
	}
	cout<<as<<endl;
	return 0;
}
/*
3 4 5
2
3
4
1 2 1
1 3 5
2 3 7
2 4 3
3 4 5
*/
