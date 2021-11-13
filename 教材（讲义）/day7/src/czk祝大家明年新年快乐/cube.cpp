#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+5;
int n;
double a[Maxn],f[Maxn]={0},dd[Maxn]={0},d[Maxn]={0};

int main(){
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	for(int i=0;i<=n-1;i++){
		f[i+1]=f[i]+(a[i+1]*(3.0*dd[i]+3.0*d[i]+1.0));
		d[i+1]=a[i+1]*(d[i]+1.0);
		dd[i+1]=a[i+1]*(dd[i]+2.0*d[i]+1.0);
	}
	printf("%0.1lf",f[n]);
	return 0;	
}
