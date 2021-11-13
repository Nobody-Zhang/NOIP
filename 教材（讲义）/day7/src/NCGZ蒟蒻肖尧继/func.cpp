#include<cmath>
#include<cstdio>
#include<bitset>
#include<bits/stdc++.h>
#define ri register int
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
using namespace std;
template<typename TP>inline void read(TP&x)
{
    x=0;int f=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
template<typename TP>inline void print(TP x)
{
    if(x<0)x=-x,putchar('-');
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
inline long long Pow(int x,int y,int mod)
{
	long long ret=1;
	for(ri i=y;i;i>>=1)
	{
		if(i&1)ret=(ret*x)%mod;
		x=(x*x)%mod;
	}
	return ret%mod;
}
bitset<100005>flag;
int prime[50005],size,eular[100005],g[100005];
inline int get_prime(int x)
{
	for(ri i=2;i<=x;++i)
	{
		if(!flag[i])prime[++size]=i,eular[i]=i-1;
		for(ri j=1;i*prime[j]<=x&&j<=size;++j)
		{
			flag[prime[j]*i]=1;
			if(i%prime[j]==0){eular[prime[j]*i]=prime[j]*eular[i];break;}
			eular[prime[j]*i]=(prime[j]-1)*eular[i];
		}
	}
}
inline int get_gx(int x)
{
	int cnt=1,ret=0;
	for(ri i=2;i*i<=x;++i)
		if(prime[cnt]==i)
		{
			if(x%i==0)
			{
				ret+=i;
				while(x%i==0)x/=i;
			}
			++cnt;
		}
	//cout<<"ret:"<<ret+1;
	if(ret!=1)++ret;
	return ret+1;
}
int L,R,D;
long long ans;
int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	read(L),read(R),read(D);
	const int mod=D;
	eular[1]=1;
	get_prime(100005);
	for(ri i=L;i<=R;++i)
		ans^=Pow(2048,(int)pow(3,get_gx(i)),mod);
	print(ans);
	return 0;
}
/*
1 3 9       暗示39天下第一
8
*/
