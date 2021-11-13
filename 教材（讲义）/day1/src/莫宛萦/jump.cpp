#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
ll n,d,k,dis[N],val[N],llo,rr,f[N];
bool ok;
/*void dfs(int i,int pos,int tot)
//i是打算跳到的格子 pos是目前据起点的距离 
{
	if(ok||i>n) return ;
	if(dis[i]-pos>rr) return ;//跳不到那么远 
	if(dis[i]-pos<ll) dfs(i+1,pos,tot);//跳下一个更远的 
	//要跳这个 就进行更新记忆化f数组 
	if(tot+val[i]>=k) { ok=true; return; }
	else if(tot+val[i]>f[i]) f[i]=tot+val[i];
	else return ;//没有原来的方案大 
	dfs(i+1,pos,tot);//不选i 
	dfs(i+1,dis[i],tot+val[i]);//选i 
}*/

bool check(ll x)
{
	//ok=false;
	memset(f,-127,sizeof(f));
	llo=d-x,rr=d+x;
	if(llo<=0) llo=1;//不能取max 因为0是属于long long 
	f[0]=0;
//dp思路：每一个点的最高得分都是由上一段中最高得分推过来的 
	for(int i=1;i<=n;i++)
	 for(int j=i-1;j>=0;j--)
	 {
		if(dis[i]-dis[j]>rr) break;//到离它最近的那一个都到不了 就break掉 
		if(dis[i]-dis[j]<llo) continue;
		f[i]=max(f[i],f[j]+val[i]);
		if(f[i]>=k) return true;
	 }
	return false;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	ll tot=0;
	scanf("%I64d%I64d%I64d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&dis[i],&val[i]);
		if(val[i]>0) tot+=val[i];
	}
	if(tot<k) { printf("-1\n"); return 0; }
	ll l=1,r=1005;
	ll ans;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(!check(mid)) l=mid+1;
		else r=mid-1,ans=mid;
	}/**/
	printf("%I64d\n",ans);
	return 0;
}
/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
*/
