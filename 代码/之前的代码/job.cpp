#include<bits/stdc++.h>
using namespace std;
int a[21][21];//表明每个人花的钱是多少
int b;//b*b
int as;//最终答案 
int used[21];//已经安排过的人 
void dfs(int q,int w)//现在安排第q个工作当前总价格 
{
	if(q>b)
	{
		if(w<as) as=w;
		return;
	}
	if(w>=as) return;
	for(int i=1;i<=b;i++)
	 if(used[i]==0)
	 {
	 	used[i]=1;
	 	dfs(q+1,w+a[q][i]);
	 	used[i]=0;
	 }
} 
int main()
{
	freopen("job.in","r",stdin);
	freopen("job.out","w",stdout);
	cin>>b;
	for(int i=1;i<=b;i++)
	 for(int j=1;j<=b;j++)
	  cin>>a[i][j];//输入数据 
	as=100000; 
	dfs(1,0);
	cout<<as;
	return 0;
}
