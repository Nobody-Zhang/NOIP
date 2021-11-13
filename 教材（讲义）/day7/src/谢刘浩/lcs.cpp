#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

short dp[2][6666];
int n,m;
char a[6666],b[6666];

int main(){
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&m,&n);
	getchar();gets(b);gets(a);
	for(int i=1;i<=n;i++){
		int now=i&1,pre=now^1;
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1])dp[now][j]=dp[pre][j-1]+1;
			else{dp[now][j]=max(dp[now][j-1],dp[pre][j]);}
		}
	}
	printf("%d",dp[n&1][m]);
}
