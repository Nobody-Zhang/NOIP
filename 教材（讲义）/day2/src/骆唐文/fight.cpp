#include<cstdio>
#include<algorithm>
#include<iostream>
#include<memory.h>
using namespace std;

long long lef=0,rig=0,l,r,minn;
long long c[100001];
long long n,m,p1,s1,s2,ans;

int main()
{
	freopen ("fight.in","r",stdin);
	freopen ("fight.out","w",stdout);
	scanf ("%lld",&n);
	for (register int i=1;i<=n;i++)
		scanf ("%lld",&c[i]);
	scanf ("%lld%lld%lld%lld",&m,&p1,&s1,&s2);
	c[p1]+=s1;
	for (register int i=1;i<=m-1;i++)
		lef+=(m-i)*c[i];
	for (register int i=m+1;i<=n;i++)
		rig+=(i-m)*c[i];
	minn=922337203685477580;
	for (register int i=1;i<=n;i++)
	{
		if (i<m)
		{
			l=lef+((m-i)*s2);
			r=rig;
			if (abs (l-r)<minn)
			{
				minn=abs (l-r);
				ans=i;
			}
		}
		if (i==m)
		{
			l=lef;
			r=rig;
			if (abs (l-r)<minn)
			{
				minn=abs (l-r);
				ans=i;
			}
		}
		if (i>m)
		{
			l=lef;
			r=rig+((i-m)*s2);
			if (abs (l-r)<minn)
			{
				minn=abs (l-r);
				ans=i;
			}
		}
	}
	printf ("%lld",ans);
}
