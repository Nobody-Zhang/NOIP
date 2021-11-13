#pragma GCC optimize (2)
#include <cstdio>
#include <algorithm>
using namespace std;
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

int dp[2][6670];
char s1[6670],s2[6670];
int main()
{
	input("lcs.in");
	output("lcs.out");
	int n,m;
	
	scanf("%d%d\n%s\n%s",&n,&m,s1,s2);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1]) dp[i%2][j]=dp[(i-1)%2][j-1]+1;
			else dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
		}
	
	printf("%d",dp[n%2][m]);
	return 0;
}

