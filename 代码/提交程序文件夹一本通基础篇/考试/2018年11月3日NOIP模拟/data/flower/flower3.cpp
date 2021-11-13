#include<cstdio>
#include<cstring>
#include<algorithm>
#define SF scanf
#define PF printf
#define MAXN 100010
#define MAXS 30
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll dp[MAXN][2];
ll l,s;
int t;
int main(){
	SF("%d",&t);
	while(t--){
		SF("%lld%lld",&l,&s);
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		for(int i=1;i<=l;i++){
			for(int len=1;len<=min(2,i);len++){
				(dp[i][0]+=dp[i-len][0]*(i==len?1ll:(s-1ll))%MOD)%=MOD;
				(dp[i][1]+=dp[i-len][1]*(i==len?1ll:(s-1ll))%MOD)%=MOD;
			}
			if(i>=3)
				(dp[i][1]+=dp[i-3][0]*(i==3?1ll:(s-1ll))%MOD)%=MOD;	
		}
		int ans=dp[l][1]*s%MOD;
		PF("%d\n",ans);
	}
}
