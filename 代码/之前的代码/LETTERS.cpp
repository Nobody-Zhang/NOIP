#include<bits/stdc++.h>//万能库 
using namespace std;//避免重名 
int u[100];//这个是已经用过的字母，用一维数组 
//这里用int类型因为字母可以用ASCII码来存储 
char mp[21][21];//这里存储每个位置是什么字母 
int used[21][21];//存储已经走过的地方，函数值1是走过的地方 
int m,n;//m行n列 
int x[4]={1,-1,0,0}; 
int y[4]={0,0,1,-1};
int max1;//最多能走过的步数 
void dfs(int q,int w,int e)//回溯函数 
//表示 当前在（q，w），应该走第e步 
{
	if(e-1>max1)
		max1=e-1;//-1！！！！！ 
	for(int i=0;i<=3;i++)
	{
		int x1=q+x[i];
		int y1=w+y[i];//上下左右搜索 
		int j=mp[x1][y1]-'A';
		if(x1>0&&x1<=m&&y1>0&&y1<=n)//上下左右不超过边界 
		if(u[j]==0)//没有被用过的字母
		if(used[x1][y1]==0)//没有被走过的方格 
		//其实可以删掉 
		{
			used[x1][y1]=1;//标记 
			u[j]=1;//标记 
			e=e+1;
			dfs(x1,y1,e);
			e=e-1;
			u[j]=0;//还原 
			used[x1][y1]=0;//还原 
		}
	}
}
int main()//主函数
{
	cin>>m>>n;//输入多少行，多少列 
	
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=n;j++)
	  cin>>mp[i][j];//输入地图 
	int j=mp[1][1]-'A';			
	u[j]=1;//标记 
	 used[1][1]=1; //起始位置在 
	dfs(1,1,2);//开始搜索 
	cout<<max1;
	return 0;
}
