#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int n;
double a[maxn],ans[maxn],d[maxn],dd[maxn];

int main(){
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	 scanf("%lf",&a[i]);
	for(int i=0;i<n;i++){
		d[i+1]=a[i+1]*(d[i]+1);//以i+1结尾的序列末尾1的期望长度 
		dd[i+1]=a[i+1]*(dd[i]+2*d[i]+1);//以i+1结尾的序列末尾的期望长度的平方 
		ans[i+1]=ans[i]+a[i+1]*(3*dd[i]+3*d[i]+1);
	}
	printf("%.1lf",ans[n]);
}
