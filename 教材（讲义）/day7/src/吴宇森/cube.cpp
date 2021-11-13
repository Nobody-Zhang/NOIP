#include<bits/stdc++.h>
using namespace std;
//(a+1)^3-a^3=3*a^2+3*a+1
//(a^2+2*a+1)*(a+1)=a^3+a^2+2*a^2+2*a+a+1=a^3+3*a^2+3*a+1
//f[i+1]=f[i]+a[i+1]*(3*d[i]^2+3*d[i]+1)
//d[i+1]=a[i+1]*(d[i]+1)
//d[i+1]=a[i+1]*d[i]+a[i+1]
//d[i]=d[i+1]-a[i+1]
const int N=100005;
int n;
double a[N],dp[N],f[N],ff[N];//ff ex^2 f ex 

int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%lf",&a[i]);
	for(int i=0;i<=n-1;i++)
	{
		dp[i+1]=dp[i]+(a[i+1]*(3.0*ff[i]+3.0*f[i]+1.0));
		f[i+1]=a[i+1]*(f[i]+1.0);
		ff[i+1]=a[i+1]*(ff[i]+2.0*f[i]+1.0);
	}
	printf("%.1lf",dp[n]);
	return 0;
}
