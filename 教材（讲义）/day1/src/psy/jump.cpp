#include<bits/stdc++.h> 
#define ll long long
#define maxn 500005
using namespace std;
const ll INF=1e18;
ll n,d,k;
ll dis[maxn],val[maxn],dp[maxn];
deque<long long>q;
bool check(ll mid)
{
	if(!q.empty()) q.clear();
	ll l=((d-mid)<0?0:(d-mid));
	ll r=d+mid;
	ll last=0;
	for(ll i=0;i<=n;i++) dp[i]=-INF;
	dp[0]=0;
	for(ll i=1;i<=n;i++)
	{
		while(dis[last]<dis[i]-r) last++;
		while(dis[last]<=dis[i]-l&&dis[last]>=dis[i]-r&&last<i)
		{
			while(q.size()&&(dp[q.back()]<=dp[last]||dis[q.back()]<dis[i]-r))
			q.pop_back();
			q.push_back(last);
			last++;
		}
		while(q.size()&&(dis[q.front()]<dis[i]-r))
		q.pop_front();
		if(q.size()!=0) dp[i]=dp[q.front()]+val[i];
		if(dp[i]>=k) return true;
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%I64d%I64d%I64d",&n,&d,&k);
	for(ll i=1;i<=n;i++) scanf("%I64d%I64d",&dis[i],&val[i]);
	ll l=0,r=dis[n];
	while(l!=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(!check(l))
	{
		printf("-1\n");
		return 0;
	}
	else printf("%I64d",l);
	return 0;
}
