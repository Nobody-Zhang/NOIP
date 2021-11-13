#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 1005
using namespace std;
int m,dp[maxn],in[maxn];
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&in[i]);
	for(int i=1;i<=m;i++) dp[i]=1;
	for(int i=2;i<=m;i++)
		for(int j=1;j<=i-1;j++)
			if(in[i]>in[j])
				dp[i]=max(dp[i],dp[j]+1);
	int maxx=0;
	for(int i=1;i<=m;i++)
		maxx=max(maxx,dp[i]);
	printf("%d",maxx);
	return 0;
} 
