#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 30
#define MOD 1000000007
using namespace std;
int dp[MAXN][MAXN][MAXN][2],ans;
int l,s;
int main(){
	SF("%d%d",&l,&s);
	dp[0][0][0][0]=1;
	for(int i=0;i<l;i++)
		for(int j=0;j<=s;j++)
			for(int k=0;k<=s;k++)
				for(int x=1;x<=s;x++){
					if(x==k&&k==j)
						(dp[i+1][k][x][1]+=dp[i][j][k][0])%=MOD;
					else{
						(dp[i+1][k][x][1]+=dp[i][j][k][1])%=MOD;
						(dp[i+1][k][x][0]+=dp[i][j][k][0])%=MOD;
					}
				}
	int ans=0;
	for(int j=0;j<=s;j++)
		for(int k=0;k<=s;k++)
			ans=(ans+dp[l][j][k][1])%MOD;
	PF("%d",ans);
}
