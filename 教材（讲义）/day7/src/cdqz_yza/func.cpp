#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int l,r,d,g[100005],k;
ll ans;

int prime[100]={
2,3,5,7,11,13,17,19,23,29,31,37,
41,43,47,53,59,61,67,71,73,79,83,89,
97,101,103,107,109,113,127,131,137,139,149,151,
157,163,167,173,179,181,191,193,197,199,211,223,
227,229,233,239,241,251,257,263,269,271,277,281,
283,293,307,311,313,317,331,337,347,349,353,359,
367,373,379,383,389,397,401,409,419,421,431,433,
439,443,449,457,461,463,467,479,487,491,499,503};

int max(int x,int y)
{
	return x>y?x:y;
}

ll qpow(int x,ll y,int mod)
{
	if(y==1)	return x;
	int ret=qpow(x,y/2,mod);
	if(y%2)	return x*ret*ret%mod;
	return ret*ret%mod;
}

ll qpow2(int x,int y)
{
	if(y==1)	return x;
	int ret=qpow2(x,y/2);
	if(y%2)	return x*ret*ret;
	return ret*ret;
}

void work()
{
	for(int i=l;i<=r;i++)
	{
		ll p=qpow(3,g[i],d-1);
		ans^=qpow(2,11*p,d);
	}
}

void work1()
{
	for(int i=l;i<=r;i++)
	{
		ll p=qpow(3,g[i],k);
		ans^=qpow(2,11*p,d);
	}
}

void work2()
{
	for(int i=l;i<=r;i++)
	{
		ll p=qpow2(3,g[i]);
		ans^=qpow(2,11*p,d);
	}
}

int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	scanf("%d%d%d",&l,&r,&d);
	for(int i=0;i<96;i++)
		for(int j=max((l-1)/prime[i]+1,1);j<=r/prime[i];j++)
			g[prime[i]*j]+=prime[i];
	g[1]=1;
	bool fl=0;
	for(int i=2;i*i<=d;i++)
		if(d%i==0)
		{
			fl=1;
			break;
		}
	if(fl==0)
	{
		work();
		printf("%I64d",ans);
		return 0;
	}
	ll pl=1;
	for(int i=1;i<=60;i++)
	{
		pl*=2;
		if((pl-1)%d==0)
		{
			k=i;
			break;
		}
	}
	if(k!=0)
		work1();
	else
		work2();
	printf("%I64d",ans);
	return 0;
}
