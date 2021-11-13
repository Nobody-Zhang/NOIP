#include<bits/stdc++.h>
using namespace std;

const int N=100005;
long long n,c[N],m,p1,s1,s2,l,r,ans,minn=0x7fffffff;
long long leftsum=0,rightsum=0;
void solve()
{
	l=1,r=n+1;
	while(l<r)
	{
		long long mid=(l+r)/2;
		long long tmp=leftsum+s2*(m-mid);
		if(abs(tmp-rightsum)<=minn)
		{
			ans=mid;
			minn=abs((long long)tmp-rightsum);
		}
		if(tmp<=rightsum) r=mid;
		else l=mid+1;
	}
	printf("%I64d",ans);
}

int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
	scanf("%I64d",&c[i]);
	scanf("%I64d%I64d%I64d%I64d",&m,&p1,&s1,&s2);
	c[p1]+=s1;
	for(int i=1;i<=m;i++)
	leftsum+=(m-i)*c[i];
	for(int i=m;i<=n;i++)
	rightsum+=(i-m)*c[i];
	solve();
	return 0;
}
