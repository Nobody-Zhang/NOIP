#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
int dp[750][750];//i个人等待了i时的最小时间 f[i][j]表示把前i个人送完后，最后一趟车的出发时间为a[i]+j 的最小花费
int Time[1000010];
int n,m;
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&Time[i]);
	}
	sort(Time+1,Time+1+n);
	for(int i=1;i<2*m;i++)//任意等待的时间不超过2m 
	{
		dp[1][i]=i;//初始化:一个人等待的时间为i 
	}
	for(int i=2;i<=n;i++)//从第二个人开始枚举
	{
		for(int j=0;j<2*m;j++)//枚举等待的时间
		{
			dp[i][j]=inf;//初始化为最大值
			for(int k=0;k<2*m;k++)//之前人等待的时间 
			{
				int check=Time[i]+j-(Time[i-1]+k);
				if(check==0||check>=m)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][k]+j); 
				} 
			} 
		} 
	} 
	int ans=inf;
	for(int i=0;i<2*m;i++)
	{
		if(ans>dp[n][i])
		{
			ans=dp[n][i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

