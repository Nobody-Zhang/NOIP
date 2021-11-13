#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000+5
int dp[maxn][maxn];
string s1,s2;
char c1[maxn],c2[maxn];
int main()
{
	while(scanf("%s%s",c1,c2)==2)
	{
		//;
		//if(cin>>s1>>s2==false) break;
		//int m=s1.length(),n=s2.length();
		int m=strlen(c1),n=strlen(c2);
		//for(int i=1;i<=m;i++) c1[i]=s1[i-1];
		//for(int i=1;i<=n;i++) c2[i]=s2[i-1];
		for(int i=m;i>=1;i--) c1[i]=c1[i-1];
		for(int i=n;i>=1;i--) c2[i]=c2[i-1];
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(c1[i]==c2[j]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		printf("%d\n",dp[m][n]);
		memset(dp,0,sizeof(dp));
		s1.clear(),s2.clear();
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		//if(scanf("%s%s",s1,s2)!=2) break;
	}
	return 0;
}
