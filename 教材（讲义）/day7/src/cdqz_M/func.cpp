#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> T cpow(T,T);
template<class T> T moded_cpow(T,T,T);

ll g(ll x)
{
	ll re=0;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			re+=i;
			while(x%i==0) x/=i;
		}
	}
	return re+x;
}

ll F(ll x,ll MO) {return moded_cpow(2048LL,cpow(3LL,g(x)),MO);}

int L,R,D;

int main()
{
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	scanf("%d%d%d",&L,&R,&D);
	ll ans=F(L,D);
	for(int i=L+1;i<=R;i++)
		ans^=F(i,D);
	printf("%I64d\n",ans);
	return 0;
}

template<class T> T cpow(T x,T y)
{
	T ans=1;
	while(y){
		if(y&1) ans*=x;
		x*=x;
		y>>=1;
	}
	return ans;
}

template<class T> T moded_cpow(T x,T y,T MOD)
{
	T ans=1;
	while(y){
		if(y&1) ans=(ans*x)%MOD;
		x=(x*x)%MOD;
		y>>=1;
	}
	return ans;
}