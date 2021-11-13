#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,k) for(register int i=j;i<=k;i++)
#define oo 233333333333333333
#define N 100005
using namespace std;

ll n,k,sum[N],dp[N],pos,maxn=-999999999,now;
int x;

template<class T> inline void read(T &re)
{
	re=0;T sign=1;char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');re*=sign;
}

int main()
{
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	read(n);read(k);
	fo(i,1,n) read(x),sum[i]=sum[i-1]+x;
	fo(i,1,k)
	{
		dp[i]=sum[i];
		if(now==dp[i-1]-sum[i]>=maxn) maxn=now,pos=i;
	}
	fo(i,k+1,n)
	{
		if(pos<i-k)
		{
			maxn=-oo;
			fo(j,pos+1,i)
				if(now=dp[j-1]-sum[j]>=maxn) {maxn=now;pos=j;}
		}
		else
		{
			if(now=dp[i-1]-sum[i]>=maxn) {maxn=now;pos=i;}
		}
		dp[i]=dp[pos-1]+sum[i]-sum[pos];
	}
	printf("%I64d\n",dp[n]);
	return 0;
}