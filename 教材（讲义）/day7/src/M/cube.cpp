#include<bits/stdc++.h>
using namespace std;
const int MaxN=1e5+5;

int n;
double a[MaxN],f[MaxN],d[MaxN],dp[MaxN];

int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
	for(int i=0;i<=n;i++){
		dp[i+1]=dp[i]+a[i+1]*(3*f[i]+3*d[i]+1);
		f[i+1]=a[i+1]*(f[i]+2*d[i]+1);
		//WA : f[i+1]=f[i]+a[i+1]*(2*d[i]+1);
		d[i+1]=a[i+1]*(d[i]+1);
	}
	printf("%0.1lf\n",dp[n]);
	return 0;
}