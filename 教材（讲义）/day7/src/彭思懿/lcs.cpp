#include<bits/stdc++.h>
#define maxn 6670
using namespace std;
int dp[2][maxn],n,m;
char a[maxn],b[maxn];
int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
    for(int i=1;i<=n;i++)
    {
    	int now=i&1,pre=now^1;
    	 for(int j=1;j<=m;j++)
         {
        	if(a[i]==b[j]) dp[now][j]=dp[pre][j-1]+1;
        	else dp[now][j]=max(dp[pre][j],dp[now][j-1]);
         }
    }
    printf("%d",dp[n&1][m]);
    return 0;
}
/*
5 6
abdac
adabac
*/
