#include<cstdio>
#define maxn 100005
using namespace std;
int n;
double v[maxn],d1[maxn],d2[maxn],dp[maxn];
int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	scanf("%lf",&v[i]);
	for(int i=1;i<=n;i++)
	{
		d1[i]=v[i-1]*(d1[i-1]+1.0);
    	d2[i]=v[i-1]*(d2[i-1]+2.0*d1[i-1]+1.0);
    	dp[i]=v[i]*(3.0*d1[i]+3.0*d2[i]+1.0)+dp[i-1];
	}
	printf("%0.1lf",dp[n]);
	return 0;
}
/*
3
0.5 0.5 0.5
*/
