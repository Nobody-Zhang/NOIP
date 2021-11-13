#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
int n,pos[500005],num[500005];
ll dp[500005];
int frt,rr;
pair<ll,int> cur[500005];

inline void ins(pair<ll,int> ele)
{
	while(frt<rr&&cur[rr-1]<ele)rr--;
	cur[rr++]=ele;
}

inline void era(pair<ll,int> ele)
{
	if(frt<rr&&cur[frt]==ele)frt++;
}

inline ll maxi()
{
	return frt>=rr?(-1LL<<60):cur[frt].first;
}

bool check(int mind,int maxd,int lim)
{
	int l=0,r=0;
	frt=rr=0;
	dp[0]=0LL;
	rep1(k,n)
	{
		while(pos[k]-pos[r]>=mind)
		{
			ins(MP(dp[r],r));r++;
		}
		while(pos[k]-pos[l]>maxd)
		{
			era(MP(dp[l],l));l++;
		}
		dp[k]=maxi()+num[k];
		if(dp[k]>=lim)return true;
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int d,lim;
	scanf("%d%d%d",&n,&d,&lim);
	rep1(k,n)scanf("%d%d",&pos[k],&num[k]);
	int l=0,r=INF;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(max(d-mid,1),d+mid,lim))r=mid;
		else l=mid+1;
	}
	printf("%d\n",r==INF?-1:r);
	return 0;
}