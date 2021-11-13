#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
char a[25][25];//定义字符组
int used1[91],used2[25][25];
//used1是用过的字母，used2是走过的方格 
//A是65，Z是90 ，used字符组从 65-90
int ud[4]={1,-1,0,0};//上下怎么走 
int lr[4]={0,0,1,-1};//左右怎么走 
int max=0,m,n,l;//定义最大步数 m行n列的地图 
void search(int roe,int col,int u)//search函数，搜索 
//roe现在的行，col列，u步
{
	l=u;
	if(l>max) max=l;
	//终止条件？？？
	for(int i=0;i<=3;i++)
	{
		int x1=roe+ud[i];
		int y1=col+lr[i];
		if(x1>0&&x1<=m&&y1>0&&y1<=n&&used1[a[x1][y1]]==0&&used2[x1][x2]==0)
		{
			used1[a[x1][y1]]=1;
			used2[x1][x2]=1;
			search(x1,y1,u+1);
			used1[a[x1][y1]]=0;
			used2[x1][x2]=0;
		}
			
	} 
} 
int main()//主函数 
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)//输入字符
	 for(int r=1;r<=n;r++)
	 cin>>a[i][r];
	used2[1][1]=1;
	used1[a[1][1]]=1;
	search(1,1,1);
	cout<<max;
	return 0;
}
