#include<bits/stdc++.h>
using namespace std;
#define N 100005
double f[N],d1[N],d2[N],p[N];
int n;
int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	 scanf("%lf",&p[i]);
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		d1[i]=p[i]*(d1[i-1]+1);
		d2[i]=p[i]*(d2[i-1]+2*d1[i-1]+1);
		f[i]=(1.0-p[i])*f[i-1]+p[i]*(f[i-1]+3*d2[i-1]+3*d1[i-1]+1);
		/*
		g1[i]=(g1[i-1]+1)*p[i];//以i结尾仅有1的最长连续段的期望长度 
		g2[i]=(g2[i-1]+2*g1[i-1]+1)*p[i];//平方 
		f[i]=f[i-1]*(1-p[i])+(f[i-1]+3*g2[i-1]+3*g1[i-1]+1)*p[i];
		*/
	}
	printf("%.1lf\n",f[n]);
}
/*
3
0.5 0.5 0.5
*/
