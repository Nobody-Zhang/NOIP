#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxx 1000000
#define maxn 1000005
#define myll "%I64d "
long long ans[maxn],e[maxn];
void sol1()
{//这个是求1到n的正因子个数的 
	for(int i=1;i<=maxx;++i)
		for(int j=i;j<=maxx;j+=i)
			ans[j]++;
	for(int i=1;i<=maxx;++i)
	printf(myll,ans[i]);
	exit(0);
}
void sol2()
{//求正因子和 
	for(int i=1;i<=maxx;++i)
		for(int j=i;j<=maxx;j+=i)
			ans[j]+=i;
	for(int i=1;i<=maxx;++i)
	printf(myll,ans[i]);
	exit(0);
}
int prime[maxn],vis[maxn],inc;
void sol3()
{//求莫比乌斯函数 
	ans[1]=1;
	for(int i=2;i<=maxx;++i)
	{
		if(!vis[i]) ans[i]=-1,prime[++inc]=i;
		for(int j=1;j<=inc&&i<=maxx/prime[j];++j)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				ans[i*prime[j]]=0;
				break;
			}
			ans[i*prime[j]]=-ans[i];
		}
	}
	for(int i=1;i<=maxx;i++)
	printf(myll,ans[i]);
	exit(0);
}
void sol4()
{//求欧拉函数 
	ans[1]=1;
	for(int i=2;i<=maxx;i++)
		if(!ans[i])//表示当前是没有被更新过（质数）
		//可以更新别的phi 
			for(int j=i;j<=maxx;j+=i){
				if(!ans[j]) ans[j]=j;
				ans[j]=ans[j]/i*(i-1);
			}
	for(int i=1;i<=maxx;i++)
	printf(myll,ans[i]);
	exit(0);
}
void sol6()
{
	for(int i=1;i<=maxx;++i)
		printf("%d ",i);
	exit(0);
} 
void sol5()
{
	printf("1 ");
	for(int i=2;i<=maxx;++i)
	 printf("0 ");
	exit(0);
}
int main()
{
	freopen("mulfunc.in","r",stdin);
	freopen("mulfunc.out","w",stdout);
	int opt;
	scanf("%d",&opt);
	if(opt==1) sol1();
	if(opt==2) sol2();
	if(opt==3) sol3();
	if(opt==4) sol4();
	if(opt==5) sol5();
	sol6();
}
