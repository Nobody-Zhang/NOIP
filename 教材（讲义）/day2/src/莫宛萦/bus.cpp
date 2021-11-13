#include<bits/stdc++.h>
using namespace std;
//t-a[i]<=m 所以二维数组不会爆
#define N 505
int good[N][N],n,timer,a[N]; 
int dfs(int i,int t)
{
	if(i==n+1) return 0;
	//如果现在的时间没有人 就跳到下一个有人的时间 
	if(t<a[i]) return dfs(i,a[i]);
	//t因为小于a[i] 会导致数组越界 
	if(good[i][t-a[i]])//第i个人 所花费的等待时间为t-a[i] 
	 return good[i][t-a[i]];
	
	//车等人 就是从上一层推过来车的时间要大一点 
	int sum=0,j=i;
	//刚好<=发车时间的人一起坐 
	while(j<=n&&a[j]<=t)
	 sum+=a[j++];
	//因为j多加了1所以后面就不用加1 
	int best=(j-i)*t-sum+dfs(j,t+timer);
	for(;j<=n;j++)
	{
		sum+=a[j];
		best=min(a[j]*(j-i+1)-sum+dfs(j+1,a[j]+timer),best);
	}
	//记忆化搜索 
	return good[i][t-a[i]]=best;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&timer);
	for(int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	printf("%d\n",dfs(1,0));
}
