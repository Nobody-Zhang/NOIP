#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
double g1[maxn],g2[maxn],f[maxn],p[maxn];
int n;
int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%lf",&p[i]);
	
	for(int i=1;i<=n;i++)
	{
		g1[i]=(g1[i-1]+1)*p[i];//以i结尾仅有1的最长连续段的期望长度 
		g2[i]=(g2[i-1]+2*g1[i-1]+1)*p[i];//平方 
		f[i]=f[i-1]*(1-p[i])+(f[i-1]+3*g2[i-1]+3*g1[i-1]+1)*p[i];
	}//以i结尾段的期望值 
	printf("%.1lf",f[n]);
	return 0;
}
/*
3
0.5 0.50.5
*/ 
