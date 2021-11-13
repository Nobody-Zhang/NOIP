#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void redi(T& t)
{
	register int c=getchar();t=0;
	bool flag=false;
	if(c=='-') flag=true;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=t*10+c-'0',c=getchar();
	if(flag) t=-t;
}
template <typename T,typename... Args>inline void redi(T& t,Args&... args)
{
	redi(t);
	redi(args...);
}
/*void redi(long long &t)
{
	scanf("%lld",&t);
	return;
 }*/ 
#define maxx 25 
//#define long long long long
long long a[maxx],b[maxx],k;
long long qmul(long long x,long long y,long long mod)
{//x*y%mod
	long long ans=0;
	while(y>0)
	{
		if(y&1) ans=(ans+x)%mod;
		x=(x+x)%mod;
		y>>=1;
	}
	return ans;
}
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0){
		x=1,y=0;
		return a;
	}
	long long gcd=exgcd(b,a%b,x,y);
	long long xx=y;
	long long yy=(x-(long long)ceil(a/b)*y);
	x=xx;
	y=yy;
	return gcd;
}
long long inverse(long long x,long long mod)
{//求x相对于mod下的逆元 
	long long xx,k;
	long long gcd=exgcd(x,mod,xx,k);
	//if(gcd!=1) exit(0);
	return ((xx%mod+mod)%mod);
}
long long china()
{
	long long ans=0;
	long long N=1;
	for(int i=1;i<=k;++i)
		N*=b[i];
	for(int i=1;i<=k;i++)
	{
		long long tmp=N/b[i];
		long long inv=inverse(tmp,b[i]);
		ans=(ans+qmul(qmul(tmp,inv,N),a[i],N))%N;
	}
	return ((ans+N)%N);
}
int main()
{
	redi(k);
	for(int i=1;i<=k;++i)
		redi(a[i]);
	for(int i=1;i<=k;++i)
		redi(b[i]);
	for(int i=1;i<=k;++i)
		a[i]=(a[i]+b[i])%b[i];
	printf("%lld\n",china());
}
