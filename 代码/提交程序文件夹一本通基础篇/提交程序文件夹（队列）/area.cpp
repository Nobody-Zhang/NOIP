#include<bits/stdc++.h>
using namespace std;
#define MAXX 15
int area[MAXX][MAXX];
int a,b;
void BFS_1()
{
	for(int i=1;i<=MAXX;i++)
	 for(int j=1;j<=MAXX;j++)
	  if(area[i][j]==1)
	  {
	  	a=i,b=j;
	  	return;
	  }
}
void BFS_2(int k)
{
	for(int i=1;i<=MAXX;i++)
	 
}
int main()
{
	for(int i=1;i<=10;i++)
	 for(int j=1;j<=10;j++)
	  cin>>mp[i][j];
	BFS_1();
	BFS_2(a);
}
