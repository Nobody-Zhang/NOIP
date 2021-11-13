#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int l,r,mod;

inline long long qpow(int a,int x,int mod){
	long long ans=1;
	for(;x;x>>=1,a=a*1ll*a%mod)
		if(x&1)ans=ans*1ll*a%mod;
	return ans%mod;
}
inline long long qpow2(int a,int x){
	long long ans=1;
	for(;x;x>>=1,a=a*1ll*a)
		if(x&1)ans=ans*1ll*a;
	return ans;
}

inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9')s=getchar();
	while(s>='0'&&s<='9')
	{x=(x<<1)+(x<<3)+s-'0';s=getchar();}
}
inline void print(int x){
	if(x>9)print(x/10);
	putchar(x%10+48);
}

inline int g(int x){
	int ans=0;
	if(x==1)return 1;
	for(int i=2;i*i<=x;i++){
		if(x%i)continue;
		while(x%i==0)x/=i;
		ans+=i;
	}
	return ans;
}

inline long long f(int x,int mod){
	return qpow(2048,qpow2(3,g(x)),mod)%mod;
}

int main(){
	long long ans;
	freopen("func.in","r",stdin);
	freopen("func.out","w",stdout);
	read(l);read(r);read(mod);
	ans=f(l,mod);
	for(int i=l+1;i<=r;i++){
		ans^=f(i,mod);
	}
	print(ans);
}
