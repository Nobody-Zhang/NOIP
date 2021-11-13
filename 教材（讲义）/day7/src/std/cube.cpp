#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100005;
int n ;
double f[MAXN], d[MAXN], d2[MAXN], p[MAXN] ;

int main(){
	freopen("cube.in","r",stdin) ;
	freopen("cube.out","w",stdout) ;
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%lf",&p[i]);
	for (int i=1;i<=n;++i)
	{
		d[i]=p[i]*(d[i-1]+1);
		d2[i]=p[i]*(d2[i-1]+2*d[i-1]+1);
		f[i]=p[i]*(f[i-1]+3*d2[i-1]+3*d[i-1]+1)+(1-p[i])*f[i-1];
	}
	printf("%.1f\n",f[n]);
}
