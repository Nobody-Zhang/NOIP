#include<bits/stdc++.h>
using namespace std;
int m,n;//总共m个人，n对仇敌关系 
int w[3001][3001];//表示是否是仇敌 
int out[3001];//是否选 
int s[3001];//当前选择情况 
int as;//表示最大值 
void pr()
{
	cout<<as<<endl;
	 for(int j=1;j<=m;j++)
	cout<<out[j]<<" ";
}
void dfs(int x,int y)//x是选到多少个人，y是当前选的人的个数 
{
	if(x>m) 
	{
		if(as<y) 
		{
			as=y;
			memset(out,0,sizeof(out));//数组清0 
			for(int i=1;i<=m;i++)
		 	out[i]=s[m];
		}
		return;
	}
	if(as<y){
		as=y;
		memset(out,0,sizeof(out));//数组清0 
		for(int i=1;i<=m;i++)
		 out[i]=s[m];
	}
	for(int i=x+1;i<=m;i++)
	{
		s[i]=1,y=y+1;
		dfs(i,y);
		s[i]=0,y=y-1;
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int l,k;
		cin>>l>>k;
		w[l][k]=1,w[k][l]=1;//所有都标记 
	}
	dfs(1,0);
	pr();
	return 0;
}
