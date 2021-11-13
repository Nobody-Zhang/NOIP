#include<bits/stdc++.h>
using namespace std;
//bool a[6][6];//前面是人，后面是书 
int used[6];//书
int u[6];//人
int a[6][6]={{0,0,0,0,0,0},{0,0,0,1,1,0},{0,1,1,0,0,1},
{0,0,1,1,0,0},{0,0,0,0,1,0},{0,0,1,0,0,1}};
/* a[6][6]={{0,0,0,0,0,0},{0,0,1,0,0,0},{0,0,1,1,0,1},
{0,1,0,1,0,0},{0,1,0,0,1,0},{0,0,1,0,0,1}};*/
int re;
int out[6];//怎么输出每个人选什么 
void pr()
{
	cout<<"answer "<<re<<":"<<endl;
	for(int i=1;i<=5;i++)
	 printf("%d:%c\n",i,out[i]+'A'-1);
}
void dfs(int j)//j是第本书 
{
	if(j>5)//结束函数 
	{
		re++;
		pr();
		return;	
	}
	for(int i=1;i<=5;i++)//这里是人选书 
	if(a[i][j]==1)
	if(used[j]==0&&u[i]==0)// i是人，j是书本 
	//这个人喜不喜欢  这个人没有选过书
	{
		used[j]=1;//这个人选过书本了
		u[i]=1;
		out[i]=j;//第i个人选了第j本书
		//for(int i=1;i<=5;i++)
		dfs(j+1);//搜索下一层 
		u[i]=0;
		used[j]=0; 
	}
}
int main()
{

	/*for(int i=1;i<=5;i++)
	 for(int j=1;j<=5;j++)
	 {
	 	a[i][j]=false;
	 }
	for(int i=1;i<=5;i++)
	 for(int j=1;j<=5;j++)
	  {	  	
	  if(b[i][j]==1) a[i][j]=true;
		else a[i][j]=false;
		  }*/
	dfs(1);
	return 0;
}
