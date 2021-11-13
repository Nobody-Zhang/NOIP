#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int e;//有e个测试数据 
char in[101][101][101];//第一个是第几组数据
//第二个是行
//第三个是列 
int used[101][101][101];
int mb[101][4];//目标点
//[1,2]是起始位置
//[3,4]是终止位置 
int a[101];//有多少个 即a[?]*a[?] 
int lf[4]={1,-1,0,0};
int ud[4]={0,0,1,-1};//上下左右搜索 
int bj;//打标记，代表这里是yes 不然输出no 
void dfs(int i,int j,int k)
//从（i，j）开始搜索 是第k组 
{
	 if(i==mb[k][3]&&j==mb[k][4])//当到达了终点
	  {
	  	bj=1;
	  	return;
	  }
	 for(int l=0;l<=3;l++)
	 //搜索地图上面是不是走过了
	 {
	 	if(bj==1) break;
	 	int x=i+lf[l];
	 	int y=j+ud[l];//上下左右搜索 
	 	if(x>0&&y>0&&x<=a[k]&&y<=a[k])//在边界之内
		{
			if(used[k][x][y]==0&&in[k][x][y]=='.')//没有走过 
			{
				used[k][x][y]=1;//标记 
				dfs(x,y,k);//搜索 
				used[k][x][y]=0;//清除标记 
			}
		}
	 } 
}
int main()
{
	cin>>e;
//	for(int i=1;i<=e;i++)
	 //cin>>a[i];//输入是几*几的方格
	for(int i=1;i<=e;i++)//第几个数据
	{
		cin>>a[i];//输入第几个数据中的大小
		//就是n*n中的n 
	 	for(int j=1;j<=a[i];j++)
	 	 for(int r=1;r<=a[i];r++)
	 	  cin>>in[i][j][r];//输入地图 
	 	for(int j=1;j<=4;j++)
	 	{
	 		cin>> mb[i][j];//输入起始点and目标点 
	 		mb[i][j]+=1;//题目要求 
	 	}
	}
	for(int i=1;i<=e;i++)
	 {
	 	bj=0;//标记清0 
	 	used[i][mb[i][1]][mb[i][2]]=1;
		 // 起点标注为1 表示走过 
	 	dfs(mb[i][1],mb[i][2],i);//搜索 
	 	if(bj==0) cout<<"NO\n";//当没有做标记时 
	 	else cout<<"YES\n";//做了标记就输出YES 
	 }
}
