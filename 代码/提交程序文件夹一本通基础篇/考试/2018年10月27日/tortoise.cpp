#include<bits/stdc++.h>
using namespace std;
//这道题竟然要用dp.....
//看不出来......
//四层循环 
int m,n,each[355],mp[41][41][41][41],how[125];
int main()
{
	freopen("tortoise.in","r",stdin);
	freopen("tortoise.out","w",stdout);
	cin>>n>>m;//n是多少的格子，m是牌数 
	for(int i=1;i<=n;i++)
	 cin>>each[i];
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		how[x]++;
	}
	mp[0][0][0][0]=each[1];
	for(int i=0;i<=how[1];i++)
	 for(int j=0;j<=how[2];j++)
	  for(int x=0;x<=how[3];x++)
	   for(int y=0;y<=how[4];y++)
	   {
	   	int zy=1+i*1+j*2+x*3+y*4;
	   	if(i!=0) mp[i][j][x][y]=max(mp[i][j][x][y],mp[i-1][j][x][y]+each[zy]);
	   	if(j!=0) mp[i][j][x][y]=max(mp[i][j][x][y],mp[i][j-1][x][y]+each[zy]);
	   	if(x!=0) mp[i][j][x][y]=max(mp[i][j][x][y],mp[i][j][x-1][y]+each[zy]);
	   	if(y!=0) mp[i][j][x][y]=max(mp[i][j][x][y],mp[i][j][x][y-1]+each[zy]);
	   }
	cout<<mp[how[1]][how[2]][how[3]][how[4]]<<endl;
	return 0;
}
