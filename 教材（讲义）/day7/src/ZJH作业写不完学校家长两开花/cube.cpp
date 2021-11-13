#include<bits/stdc++.h>
using namespace std;
const int maxn = 120100;
int n;
double a[21],f[maxn],d[maxn],ans;
int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	for(int i=0;i<n;i++){
		f[i+1]=f[i]+a[i+1]*(3*d[i]*d[i]+3*d[i]+1);
		d[i+1]=a[i+1]*(d[i]+1);
	}
	printf("%.1lf",f[n]);
}
