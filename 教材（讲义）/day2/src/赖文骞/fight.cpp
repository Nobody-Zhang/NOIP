#include <cmath>
#include <cstdio>
#include <climits>
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

long long c[1000005];

int main()
{
	input("fight.in");
	output("fight.out");
	int n,p=0;
    long long m,p1,s1,s2,mini=LLONG_MAX,dratot=0LL,tigtot=0LL;
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&c[i]);
	scanf("%I64d%I64d%I64d%I64d",&m,&p1,&s1,&s2);
	
	c[p1]+=s1;
	for(int i=1;i<=n;i++)
	{
		if(i<m) dratot+=(m-i)*c[i];
		else if(i>m) tigtot+=(i-m)*c[i];
	}
	
	if(dratot==tigtot) p=m;
	else if(dratot<tigtot)
	{
		for(int i=1;i<=m;i++)
		{
			long long tmp=std::abs(dratot+(m-i)*s2-tigtot);
			if(tmp<mini)
			{
				mini=tmp;
				p=i;
			}
		}
	}
	else
	{
		for(int i=m;i<=n;i++)
		{
			long long tmp=std::abs(tigtot+(i-m)*s2-dratot);
			if(tmp<mini)
			{
				mini=tmp;
				p=i;
			}
		}
	}
	
	printf("%d",p);
	return 0;
}
