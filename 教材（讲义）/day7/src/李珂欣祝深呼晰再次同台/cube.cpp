#include<bits/stdc++.h>
using namespace std;
double p[1000002],f[1000002],g1[1000002],g2[1000002];
int main()
{
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&p[i]);//(k+1)^3-k^3==E(3k^2+3k+1)==E(K^2)+E(k)+1
	}
	for(int i=1;i<=n;i++)
	{
		g1[i]=(g1[i-1]+1)*p[i];//算E(k)
		//相当于是加权平均值, 
		g2[i]=(g2[i-1]+2*g1[i-1]+1)*p[i];//算E(k^2）//同样考虑期望贡献如果加进来的是1
		//对k^2的的影响是多加了(k+1)^2-k^2==2k+1  
		f[i]=f[i-1]*(1-p[i])+(f[i-1]+3*g2[i-1]+3*g1[i-1]+1)*p[i];//算期望贡献,f[k]存总的加进来是1的影响//(k+1)^3-k^3==E(3k^2+3k+1)==E(K^2)+E(k)+1 
	}
	printf("%0.1lf",f[n]);
}
