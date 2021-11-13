#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define mod 1000000007
long long tp[maxn];
int n;
long long solve()
{
	if(n==0) return 0;
	tp[n]=n%mod;
	for(int i=n-1;i>=1;i--)
		tp[i]=(tp[i+1]*i)%mod;
	tp[n+1]=1;
	long long ans=0;
	bool flag=true;
	for(int i=2;i<=n;i++)
	{
		if(flag)
		{
			ans=((ans+tp[i])%mod+mod)%mod;
			flag=false;
		}
		else
		{
			ans=((ans-tp[i])%mod+mod)%mod;
			flag=true;
		}
	}
	ans=((tp[1]-ans)%mod+mod)%mod;
	ans=((ans+((n&1)?(-1):(1)))%mod+mod)%mod;
	/*if(flag)
	{
		return ((ans+1)%mod+mod)%mod;
	}
	return ((ans-1)%mod+mod)%mod;*/
	return ans;
}
int main()
{
	freopen("derange.in","r",stdin);
	freopen("derange.out","w",stdout);
	scanf("%d",&n);
	cout<<solve();
}
