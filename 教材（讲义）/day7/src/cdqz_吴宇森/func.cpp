#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int L,R,D,g[N];
long long ans=0	;

void work(int t)
{
	int x=t;
	for(int i=2;i*i<x;i++)
	{
		if(x%i==0)
		{
			g[t]+=i;
			while(!x%i) x/=i;
		}
	}
	if(x!=1) g[t]+=x; 
}

long long qpow(int m,int n,int mod)
{
	long long ans=1;
	while(n!=0)
	{
		if(n&1) ans=ans*m%mod;
		m=m*m%mod;
		n>>=1;
	}
	return ans;
} 

int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	scanf("%d%d%d",&L,&R,&D);
	g[1]=1;
	for(int i=L;i<=R;i++)
	{
		work(i);
		ans^=qpow(2048,g[i],D);
	}
	printf("%I64d",ans);
	return 0;
}
