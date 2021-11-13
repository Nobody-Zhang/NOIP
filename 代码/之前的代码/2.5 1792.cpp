#include<bits/stdc++.h>
using namespace std;
char a[101][101];//地图用a 
int used[101][101],m,n;//先输入m行n列，used表示走过的位置 
int ud[4]={0,0,1,-1};//上下搜索 
int lr[4]={1,-1,0,0};//左右搜索
int q,w,e,r;//起点与终点坐标 
void dfs(int c,int d,int i)//当前在c行d列i步 
{
	if(c==e&&d==r) 
	{
		cout<<"YES"<<i;
		return;
	}
	for(int h=0;h<=3;h++)
	 {
	 	int x1=c+ud[h];//行上下搜索
		int y1=d+lr[h];//列左右搜索 
	 	if(x1>=0&&y1>=0&&x1<m&&y1<n&&a[x1][y1]=='.'&&used[x1][y1]==0)
	 	{
	 		i++;
	 		used[x1][y1]=1;
	 		dfs(x1,y1,i);
	 		used[x1][y1]=0;
	 	}
	 }
}
int main()
{
	cin>>m>>n;//先输入m行n列
	int u,o,f;
	for(u=0;u<m;u++)
	 for(o=0;o<n;o++)
	  cin>>a[u][o];//输入地图
	cin>>q>>w>>e>>r;//输入起点终点坐标
	dfs(q,w,0);//搜索
	return 0; 
}
