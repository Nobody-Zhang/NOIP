#include<bits/stdc++.h>
using namespace std;
double d1[100003],d2[100003],f[100003],a[100003];
int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%lf",&a[i]);
	//(x+1)^3-x^3=3x^2+3x+1
	//E(3x^2+3x+1)=3*E(x^2)+3*E(x)+1//E(1)=1
	//d1[x]=E(x) d2[x]=E(x^2)
	//d1[i]=a[i]*(d1[i-1]+1)
	//d2[i]=a[i]*()
	for(int i=1;i<=n;i++)
	{
		d1[i]=a[i]*(d1[i-1]+1);
		d2[i]=a[i]*(d2[i-1]+2*d1[i-1]+1);
		f[i]=a[i]*(f[i-1]+3*d2[i-1]+3*d1[i-1]+1)+(1-a[i])*f[i-1];
	}
	printf("%.1lf",f[n]);
}
