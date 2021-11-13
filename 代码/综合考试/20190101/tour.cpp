#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define N 55
using namespace std;
double km,L,money,pos[N][3],single;//pos第一个表示位置，第二个表示钱 
int m;//km表示终点离起点的距离，L表示最大容量，single单位油能行驶的最大距离 
bool judge(int now,double last)
{
	if((pos[now+1][1]-pos[now][1])>(last*single))//表示到不了 
	 return true;//必需得加 
	if(last*2>=L) return false;
	return true;
}
double add(int now,double last)
{
	double ans=0;
	ans+=(L-last)*pos[now][2];
	ans+=20;
	return ans;
}
double coin(int now)
{
	double ans=0;
	ans+=(pos[now+1][1]-pos[now][1])/single;
	return ans;
}
void dfs(int now,double last,double cost)
{//last表示到当前的位置还剩的油是多少 
	if(last<0||cost>money) return;//剪枝 
	if(now==m+1)
	{
		money=min(money,cost);
		return;
	}
	//先处理加的情况 
	if(judge(now,last))
	 dfs(now+1,L-coin(now),cost+add(now,last));
	dfs(now+1,last-coin(now),cost);
	return;
}
int main()
{
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	money=0x7fffffff;
	double tmp;
	cin>>km>>L>>single>>tmp>>m;
	for(int i=1;i<=m;i++)
	 cin>>pos[i][1]>>pos[i][2];
	pos[m+1][1]=km;
	pos[m+1][2]=0;
	dfs(0,L,tmp);
	printf("%.1lf",money);
	return 0;
}
