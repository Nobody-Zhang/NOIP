#include<bits/stdc++.h>
using namespace std;
#define maxn 1002
double dp[maxn];
int n;
int main()
{
	int tot;
	scanf("%d",&tot);
	while(tot--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i=n-1;i>=0;i--)
			dp[i]=dp[i+1]+(double)n/(n-i);
		printf("%.2lf\n",dp[0]);
	}
	return 0;
}
