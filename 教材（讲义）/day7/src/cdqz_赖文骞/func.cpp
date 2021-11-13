#include <cmath>
#include <cstdio>
using namespace std;
#define input(x) freopen (x,"r",stdin)
#define output(x) freopen (x,"p",stdout)

long long d;

long long power(long long a,long long b,long long p)
{
	long long ret=1LL%p;
	
	for(;b;b>>=1)
	{
		if(b&1) ret=ret*a%p;
		a=a*a%p;
	}
	
	return ret;
}

long long g(int x)
{
	long long ret=0;
	
	for(int i=2;i<=sqrt(x);i++)
		if(!(x%i))
		{
			ret+=i;
			while(!(x%i)) x/=i;
		}
	if(x!=1) ret+=x; 
	
	return ret;
}

long long f(int x)
{
	long long ans=power(2048,g(x),d);
	
	return (((ans*ans)%d)*ans)%d;
}

int main()
{
	input("func.in");
	output("func.out");
	int l,r;
	long long ans;
	
	scanf("%d%d%I64d",&l,&r,&d);
	
	ans=f(l);
	for(int i=l+1;i<=r;i++) ans=ans^f(i);
	
	printf("%I64d",ans);
}
