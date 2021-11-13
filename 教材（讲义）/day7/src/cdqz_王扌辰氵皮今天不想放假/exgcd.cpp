#include<cstdio>
using namespace std;
int t,tot,ans[15];
long long x,y;
long long gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}
long long exgcd(long long a,long long b,long long &xx,long long &yy)
{
	if(b==0)
	{
		xx=1;
		yy=0;
		return a;
	}
	exgcd(b,a%b,xx,yy);
	x=yy;
	y=xx-(a/b)*yy;
	xx=x;
	yy=y;
}
int main()
{
	freopen("exgcd.in","r",stdin);
	freopen("exgcd.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		long long a,b,c,gcdd,xx,yy;
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		gcdd=gcd(a,b);
		if(c%gcdd!=0)
		{
			ans[++tot]=-1;
			continue;
		}
		long long g=exgcd(a,b,xx,yy);
		x*=(c/gcdd);
		if(x>0)
		{
	    	while(x>0)
	    	x-=(b/gcdd);
	    	x+=(b/gcdd);
		}
		if(x<=0)
		{
			while(x<=0)
			x+=(b/gcdd);
		}
		ans[++tot]=x;
		x=0;y=0;
	}
	for(int i=1;i<=tot;i++)
	{
		if(ans[i]==-1)printf("no\n");
		else printf("%d\n",ans[i]);
	}
	return 0;
}
