#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

double a[100001],f[100001],b[100001],dp[100001];
int n;

int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	scanf ("%d",&n);
	for (register int i=1;i<=n;i++)
		scanf ("%lf",&a[i]);
	for (register int i=0;i<=n-1;i++)
	{
		dp[i+1]=dp[i]+(a[i+1]*((3.0*b[i])+(3.0*f[i])+1.0));
		f[i+1]=a[i+1]*(f[i]+1.0);
		b[i+1]=a[i+1]*(b[i]+2.0*f[i]+1.0);
	}
	printf ("%.1lf",dp[n]);
	return 0;
}


