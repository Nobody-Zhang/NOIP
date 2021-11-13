#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxn 10001
long long n,p;
long long front[maxn];
int inc(long long m)
{
	int ans=0;
	long long tmp=m;
	while(tmp>=p)
	{
		ans++;
		tmp/=p;
	}
	return front[ans];
}
long long solve()
{
	int up=inc(n);
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		int down=inc(i);
		int down2=inc(n-i+1);
		if(down+down2<up) {
			ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	scanf("%I64d%I64d",&n,&p);
	for(int i=1;i<maxn;i++)
		front[i]=front[i-1]+i;
	printf("%I64d",solve());
	return 0;
}
