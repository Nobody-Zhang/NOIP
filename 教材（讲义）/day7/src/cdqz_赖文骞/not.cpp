#include <cstdio>
#include <algorithm>
using namespace std;
#define input(x) freopen (x,"r",stdin)
#define output(x) freopen (x,"p",stdout)

long long a[15],LCM[1<<15];
bool err[1<<15];

long long lcm(long long x,long long y)
{
	return x*y/__gcd(x,y);
}

int lowbit(int x)
{
	return x&(-x);
}

int main()
{
	input("not.in");
	output("not.out");
	int n,m;
	long long ans;
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	
	ans=m;
	for(int i=1;i<=n;i++)
	{
		LCM[1<<(i-1)]=a[i];
		ans-=m/a[i];
	}
	for(int i=2;i<=n;i++)
		for(int j=1;j<(1<<n);j++)
		{
			int tmp=j,cnt=0;
			
			while(tmp)
			{
				cnt++;
				tmp-=lowbit(tmp);
			}
			
			if(cnt!=i) continue;
			
			for(int k=1;k<=n;k++)
				if((1<<(k-1))&j)
				{
					int p=(~(1<<(k-1)))&j;
					
					if(err[p])
					{
						err[j]=true;
						
						break;
					}
					LCM[j]=lcm(LCM[p],a[k]);
					if(LCM[j]>m||LCM[j]<0)
					{
						err[j]=true;
						
						break;
					}
					if(i%2) ans-=m/LCM[j];
					else ans+=m/LCM[j];
					
					break;
				}
		}
	
	printf("%I64d",ans);
	return 0;
}
