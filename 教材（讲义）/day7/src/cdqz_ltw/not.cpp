#include<cstdio>
#include<algorithm>
using namespace std;

long long a[101];
long long n,m,ans,lim,flag,gd;

long long gcd (long long x,long long y)
{
	if (y==0)
		return x;
	return gcd (y,x%y);
}
long long lcm (long long x,long long y)
{
	return (x*y)/gcd (x,y);
}
void search (long long val,long long step,long long now)
{
	if (step==lim)
	{
		ans+=flag*((int)(m/val));
		return ;
	}
	for (int i=now+1;i<=n;i++)
	{
		long long op=lcm (val,a[i]);
		if (op>m)
			continue ;
		search (op,step+1,i);
	}
}

int main()
{
	freopen ("not.in","r",stdin);
	freopen ("not.out","w",stdout); 
	scanf ("%lld%lld",&n,&m);
	for (register int i=1;i<=n;i++)
		scanf ("%lld",&a[i]);
	ans=m;
	for (lim=1;lim<=n;lim++)
	{
		if (lim%2)
			flag=-1;
		else
			flag=1;
		search (1,0,0);
	}
	printf ("%lld",ans);
	return 0;
}
