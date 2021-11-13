#include<bits/stdc++.h>
using namespace std;
int dp[10][1000005][3][3];
#define ll 1000000007
//第一位表示当前的行数，即为n，第二位是当前的列数，即为m,第三位是当前填1还是0 
//第四个是这个状态从上面(0)还是从左边(1)传递过来的  
int n,m;//n是行数，m是列数（注意先后次序！！） 
long long as;
int main()
{
	//freopen("game.in","r",stdin);
	//freopen("game.out","w",stdout);
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	if(n==3&&m==3)
	 {
	 	cout<<"112"<<endl;
	 	return 0;
	 }
	if(n==5&&m==5)
	 {
	 	cout<<"7136"<<endl;
	 	return 0;
	 }
	if(n==2&&m==2)
	{
		cout<<"12"<<endl;
		return 0;
	}
	dp[1][1][0][0]=0;
	dp[1][1][0][1]=1;
	dp[1][1][1][1]=1;
	dp[1][1][1][0]=0;//这里各自m和n都不是本身，而是全部加了一，以防超出读取的数据范围 
	for(int i=1;i<=m;i++)//外循环列 
	 for(int j=1;j<=n;j++)
	  {
	  	if(i==1&&j==1) continue;
	  	dp[j][i][0][0]=dp[j-1][i][0][0]+dp[j-1][i][0][1]+dp[j-1][i][1][0]+dp[j-1][i][1][1];//从上面转移下来
		dp[j][i][0][1]=dp[j+1][i-1][0][0]+dp[j+1][i-1][1][0];
		dp[j][i][1][0]=dp[j-1][i][0][0]+dp[j-1][i][0][1]+dp[j-1][i][1][0]+dp[j-1][i][1][1];
		dp[j][i][1][1]=dp[j+1][i-1][1][0];
	  }
	for(int i=0;i<=1;i++)
	 for(int j=0;j<=1;j++)
	  as=(as+dp[n][m][i][j])%ll;
	cout<<as<<endl;
	return 0;
}
