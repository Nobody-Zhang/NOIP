#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxx 500
int m,n,pos[maxx],minn,cost[maxx];//n是住在哪个地方，m是有多少盏灯 
bool num[maxx];
int add_money(int now)
{
	int ans=0;
	for(int i=1;i<=m;i++)
	 if(num[i]==false)
	  ans+=cost[i];
	ans+=cost[now];
	return ans;
}
int add_time(int left,int right)
{
	int ans=pos[right]-pos[left];
	return ans;
}
void dfs(int left,int right,int now,int W)
{
	if(W>minn) return;
	if(left==1&&right==m)
	{
		minn=min(minn,W);
		return;
	}
	if(left!=1)
	 {
	 	num[left-1]=true;
		dfs(left-1,right,left-1,add_money(left-1)*add_time(left-1,now)+W);
		num[left-1]=false;
	 }
	if(right!=m)
	 {
	 	num[right+1]=true;
	 	dfs(left,right+1,right+1,add_money(right+1)*add_time(now,right+1)+W);
	 	num[right+1]=false;
	 }
	return;
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	minn=0x7fffffff;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	 scanf("%d%d",&pos[i],&cost[i]);
	num[n]=true;
	dfs(n,n,n,0);
	printf("%d",minn);
	return 0;
}
