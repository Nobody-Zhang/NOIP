#include<bits/stdc++.h>
using namespace std;
const int maxn=6667;
int n,m;
char a[maxn],b[maxn];
int dp[2][maxn];
int ans;

int main(){
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++)scanf("%c",&a[i]);
	getchar();
	for(int i=1;i<=m;i++)
		scanf("%c",&b[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
	 	int nowi=i&1;
	 	if(a[i]==b[j])  dp[nowi][j]=dp[nowi^1][j-1]+1;
		   else dp[nowi][j]=max(dp[nowi^1][j],dp[nowi][j-1]);
		//printf("%d ",dp[nowi][j]);
	 }
	 //putchar(10);
	}
	printf("%d",dp[n&1][m]);
}
