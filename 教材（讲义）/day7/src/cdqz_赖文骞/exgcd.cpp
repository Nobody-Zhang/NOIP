#include <cstdio>
using namespace std;
#define input(x) freopen (x,"r",stdin)
#define output(x) freopen (x,"w",stdout)

long long exgcd(long long a,long long b,long long& x,long long& y)
{
	if(!b)
	{
		x=1;
		y=0;
		
		return a;
	}
	
	long long ret=exgcd(b,a%b,y,x);
	
	y-=x*(a/b);
	
	return ret;
}

int main()
{
	input("exgcd.in");
	output("exgcd.out");
	int t;
	
	scanf("%d",&t);
	
	while(t--)
	{
		long long a,b,c,x,y,gcd;
		
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		
		gcd=exgcd(a,b,x,y);
		if(c%gcd)
		{
			puts("no");
			continue;
		}
		
		x=((x+b)%b*c)/gcd;
		printf("%I64d\n",x%(b/gcd));
	}
	
	return 0;
}
