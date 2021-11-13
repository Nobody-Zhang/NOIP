#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[20];
int f[12];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int LCM(int a,int b){
	return a*b*1ll/gcd(a,b);
}
int dfs(int x)
{
	int y=1;
	int cnt=0;
	int num=0;
	while(x)
	{
		cnt++;
		if(x&1){
			num++;
			y=LCM(y,a[cnt]);
		}
		x>>=1;
	}
	int tot=m/y;
	return tot*f[num];
}
int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[1]=1;
	for(int i=2;i<=n;++i) f[i]=-1*f[i-1];
	int ans=0;
	int max=(1<<n);
	for(int i=1;i<max;++i)
	{
		ans+=dfs(i);
	}
	printf("%d",m-ans);
}
/*
ÊäÈë 
10 1000000000
12 13 14 15 16 17 18 19 20 21
Êä³ö 
587895073
*/
