#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
double dp[maxn];
double f[maxn];
double d[maxn];
//f仅考虑前i个的期望得分 
double a[maxn];
int n;
int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf",&a[i]);//cin>>a[i];
	for(int i=0;i<=n-1;i++)
	{
		dp[i+1]=dp[i]+(a[i+1]*((3.0*d[i])+(3.0*f[i])+1.0));
		f[i+1]=a[i+1]*(f[i]+1.0);
		d[i+1]=a[i+1]*(d[i]+2.0*f[i]+1.0);
	}
	printf("%.1lf\n",dp[n]);
	return 0;
}
