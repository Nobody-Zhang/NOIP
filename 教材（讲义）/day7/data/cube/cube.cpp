#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100005;
int n ;
double f[MAXN], g[MAXN], h[MAXN], p[MAXN] ;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%lf",&p[i]);
	for (int i=1;i<=n;++i)
	{
		g[i]=p[i]*(g[i-1]+1);
		h[i]=p[i]*(h[i-1]+2*g[i-1]+1);
		f[i]=p[i]*(f[i-1]+3*h[i-1]+3*g[i-1]+1)+(1-p[i])*f[i-1];
	}
	printf("%.1f\n",f[n]);
}
