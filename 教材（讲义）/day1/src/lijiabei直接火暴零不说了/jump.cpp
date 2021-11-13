#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,k,ans;
ll a[2][1000010];
ll f[10000010];
bool check(int x)
{
    ll left=d-x;
    if(d-x<0)
    {
        left=1;
    }
    ll right=d+x;
    memset(f,-127,sizeof(f));
    f[0]=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i-1;j>=0;j--)
        {
            if(a[0][i]-a[0][j]<left)
            {
                continue;
            }
            if(a[0][i]-a[0][j]>right)
            {
                break;
            }
            f[i]=max(f[i],f[j]+a[1][i]);//转移方程从前一个格子转移过来 
            if(f[i]>=k)
            {
                return true;
            }	
        }
    } 
    return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    scanf("%lld%lld%lld",&n,&d,&k);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a[0][i],&a[1][i]);
    }
    ll l=0;
    ll r=1000010;
    ll mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {	
            l=mid+1;
        }
    }
    printf("%I64d",ans);
    return 0;
} 
