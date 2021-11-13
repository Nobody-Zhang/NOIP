#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
//#include<vector>
//#include<stack>
#include<map>
#define R(a,b,c) for(register int (a)=(b);(a)<=(c);++(a))
#define nR(a,b,c) for(register int (a)=(b);(a)>=(c);--(a))
#define Ii inline int
#define Iv inline void
#define Il inline long long
#define Ib inline bool
#define INF 0x7ffffff
#define re register
#define ll long long
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define Cmin(a,b) ((a)=(a)<(b)?(a):(b))
#define Cmax(a,b) ((a)=(a)>(b)?(a):(b))
#define Fill(a,b) memset((a),(b),sizeof((a)))
#define D_e_Line printf("\n-------------\n");
#define D_e(x) printf("\n______%d_______\n",x)
#define Pause system("pause")
using namespace std;
const int N=100005;
Il read(){
    ll s=0,f=1;char c;
    for(c=getchar();c>'9'||c<'0';c=getchar())if(c=='-')f=-1;
    while(c>='0'&&c<='9')s=s*10+(c^'0'),c=getchar();
    return s*f;
}
template<class Tp>Iv print(Tp x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10^'0');
}
Il Pow(ll a,ll b,ll mod){
	a%=mod,b%=mod;
	ll s=1;
	while(b){
		if(b&1)s=s*a%mod;
		a=a*a%mod,b>>=1;
	}
	return s;
}
Il G(ll x,ll mod){
	ll sum=0;
	R(i,1,INF)
		if(x%i==0){
			sum+=i,
			x/=i;
			if(x==1)
				return sum;
		}
}
Il F(ll x,ll mod){
	return Pow(2048,Pow(3,G(x,mod),mod),mod)%mod;
}
#define ON_JUD
int main(){
#ifdef ON_JUD
	freopen("func.in","r",stdin),freopen("func.out","w",stdout);
#endif
	ll l=read(),r=read(),mod=read();
	if(l==r){
		printf("0\n");return 0;
	}
	ll ans=F(l,mod);
	R(i,l+1,r)
		ans^=F(i,mod);
	print(ans);
	return 0;
}
