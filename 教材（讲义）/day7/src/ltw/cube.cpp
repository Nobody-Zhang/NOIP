#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

double a[100001],f[100001],ff[100001],dp[100001];
int n;

//E(k*k^2+3*k*k+3*k+1)
//f[] len k ff[] len k^2 dp[]sco
//ff[i]=ff[i-1]+delta(f[])     *    a[i]

int main()
{
	freopen ("cube.in","r",stdin);
	freopen ("cube.out","w",stdout);
	scanf ("%d",&n);
	for (register int i=1;i<=n;i++)
		scanf ("%lf",&a[i]);
	for (register int i=0;i<=n-1;i++)
	{
		dp[i+1]=dp[i]+(a[i+1]*((3.0*ff[i])+(3.0*f[i])+1.0));
		f[i+1]=a[i+1]*(f[i]+1.0);
		ff[i+1]=a[i+1]*(ff[i]+2.0*f[i]+1.0);
	}
	printf ("%.1lf",dp[n]);
	return 0;
}
