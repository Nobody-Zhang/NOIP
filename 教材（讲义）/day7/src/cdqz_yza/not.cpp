#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m,a[12],num;

ll gcd(ll x,ll y)
{
	return y==0?x:gcd(y,x%y);
}

int main()
{
	freopen("not.in","r",stdin);
	freopen("not.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<(1<<n);i++)
	{
		int tot=0;
		ll lcm=0;
		for(int j=1;j<=n;j++)
			if(i&(1<<(j-1)))
			{
				if(tot==0)
					lcm=a[j];
				else
				{
					int gc=gcd(lcm,a[j]);
					lcm=lcm*a[j]/gc;
				}
				if(lcm>m)
						break;
				tot++;
			}
		if(lcm>m)	continue;
		if(tot%2!=0)
			num+=m/lcm;
		else
			num-=m/lcm;	
	}
	printf("%I64d",m-num);
	return 0;
}
