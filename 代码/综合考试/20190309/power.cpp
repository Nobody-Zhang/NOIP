#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000008
#define ll long long
using namespace std;
char s[100005],c[100005];
ll n,ans1,ans2,basee,ans;
int len,top,tot,ret;
ll quick(ll x,ll y)
{
	ll ret=1;
	while(y)
	{
		if(y&1)
		ret=(ret*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%s",s+1);
	ret=len=strlen(s+1);
	for(int i=1;i<=len;i++)
	c[i]=s[len-i+1];
	if(len<=18)
	{
		for(int i=1;i<=len;i++)
    	{
    		n*=10;
    		n+=s[i]-'0';
    	}
    	printf("%I64d",quick(3,n));
    	return 0;
	}
	basee=115678;//10^10mod488538
	top=1;
	while(ret>10)
	{
		n=0;
		ans1=0;
		for(int i=top+9;i>=top;i--)
		{
			n*=10;
			n+=c[i]-'0';
		}
		top+=10;
		ans1=n%488538;
		for(int i=1;i<=tot;i++)
		ans1=(ans1*basee)%488538;
		ans=(ans+ans1)%488538;
		tot++;
		ret-=10;
	}
	n=0;
	ans1=0;
	for(int i=len;i>=top;i--)
	{
		n*=10;
		n+=c[i]-'0';
	}
	ans1=n%488538;
	for(int i=1;i<=tot;i++)
	ans1=(ans1*basee)%488538;
	ans=(ans+ans1)%488538;
	printf("%I64d",quick(3,ans));
	return 0;
}
