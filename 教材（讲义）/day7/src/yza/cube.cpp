#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;

int n;
double a[maxn],d[maxn],f[maxn],dd[maxn];

int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf",&a[i]);
	for(int i=0;i<n;i++)
	{
		f[i+1] = f[i]+a[i+1]*(3*dd[i]+3*d[i]+1.0);
		d[i+1] = a[i+1]*(d[i]+1.0);
		dd[i+1] = a[i+1]*(dd[i]+2*d[i]+1.0);
	}
	printf("%0.1lf",f[n]);
	return 0;
}
