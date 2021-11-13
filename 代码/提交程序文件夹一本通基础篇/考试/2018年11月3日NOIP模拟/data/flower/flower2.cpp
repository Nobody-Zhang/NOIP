#include<cstdio>
#include<cstring>
#include<algorithm>
#define SF scanf
#define PF printf
#define MAXN 10010
#define MAXS 30
#define MOD 1000000007
using namespace std;
int dp[MAXN][MAXS][2];
int l,s;
int main(){
	while(SF("%d%d",&l,&s)!=EOF){
		memset(dp,0,sizeof dp);
		dp[0][0][0]=1;
		for(int i=1;i<=l;i++)
			for(int j=0;j<=s;j++)
				for(int k=1;k<=s;k++){
					if(k==j)
						continue;
					for(int len=1;len<=min(2,i);len++){
						(dp[i][k][0]+=dp[i-len][j][0])%=MOD;
						(dp[i][k][1]+=dp[i-len][j][1])%=MOD;
					}
					if(i>=3)
						(dp[i][k][1]+=dp[i-3][j][0])%=MOD;	
				}
		int ans=0;
		for(int i=1;i<=s;i++)
			ans=(ans+dp[l][i][1])%MOD;
		PF("%d\n",ans);
	}
}
