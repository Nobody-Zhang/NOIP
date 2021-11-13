#include<bits/stdc++.h>
using namespace std;
int mp[21][21],data[21],last[21],dp[21],n;
void outline(int x)
{
	if(x) outline(last[x]);
	if(x) cout<<x<<" ";
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>data[i],dp[i]=data[i];
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
		{
			cin>>mp[i][j];
		}
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			if(mp[i][j]==1&&dp[j]<data[j]+dp[i])
			{
				dp[j]=data[j]+dp[i];
				last[j]=i;
			}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[ans]<dp[i]){
			ans=i;
		}
	}
	outline(ans);
	cout<<endl<<dp[ans];
	return 0;
}