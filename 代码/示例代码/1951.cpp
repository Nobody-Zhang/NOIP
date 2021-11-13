#include<cstdio>
const int mod1=999911659,mod2=999911658;
int qpow(int a,int x,int mod){
	int ans=1;
	for(;x;x>>=1,a=a*1ll*a%mod)if(x&1)ans=ans*1ll*a%mod;
	return ans;
}

int m[4]={};int cnt=0;
int mod3;
const int maxn=100005;
int fac[maxn],ifac[maxn];
void init(){
	fac[0]=1;
	for(int i=1;i<mod3;++i)fac[i]=fac[i-1]*1ll*i%mod3;
	ifac[mod3-1]=qpow(fac[mod3-1],mod3-2,mod3);
	for(int i=mod3-1;i>=1;--i)ifac[i-1]=ifac[i]*1ll*i%mod3;
}
int C(int n,int m){
	if(m>n)return 0;
	else return fac[n]*1ll*ifac[m]%mod3*ifac[n-m]%mod3;
}
int lucas(int n,int m){
	if(n<mod3)return C(n,m);
	else return lucas(n/mod3,m/mod3)*1ll*(C(n%mod3,m%mod3))%mod3;
}
int N,G;
int work(){
	int ans=0;
	for(int i=1;i*i<=N;++i){
		if(N%i==0){
			ans=(ans+lucas(N,i))%mod3;
			if(i*i!=N){
				ans=(ans+lucas(N,N/i))%mod3;
			}
		}
	}
	return ans;
}
int ans[4];
int main(){
	int x=mod2;
	for(int i=2;i*i<x;++i){
		if(x%i==0){
			x/=i;m[cnt++]=i;
		}
	}
	m[cnt++]=x;
	scanf("%d%d",&N,&G);
	if(G==mod1){
		printf("0\n");return 0;
	}
	for(int i=0;i<cnt;++i){
		mod3=m[i];init();
		ans[i]=work();
	}
	int ANS=0;
	for(int i=0;i<cnt;++i){
		ANS=(ANS+(qpow(mod2/m[i],m[i]-2,m[i]))*1ll*ans[i]%mod2*1ll*(mod2/m[i])%mod2)%mod2;
	}
	printf("%d\n",qpow(G,ANS,mod1));
	return 0;
}
