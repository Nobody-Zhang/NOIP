#include<bits/stdc++.h>
using namespace std;
#define mod 10007
int a,b,k,n,m;
long long f[1001];
long long inv[10000001];
long long finv[10000001];
long long C(int a,int b)
{
	long long ans;
	ans=(f[a]*finv[b]*finv[a-b])%mod;
	return ans;
} 
long long poww(int a,int b){
long long ans=1,base=a;
while(b!=0){if(b&1!=0)ans=base*ans%mod;base=base*base%mod;b>>=1;}
    return ans;
}
int main()
{
	f[0]=1;
	for(int i=1;i<=10000000;i++)
	 f[i]=f[i-1]*i%mod;
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	inv[1]=finv[1]=1;
	for(int i=2;i<=10000000;i++)
	 {
	 	long long tmp=floor(1.0*mod/i);
	 	inv[i]=mod-tmp*inv[mod%i];
	 	finv[i]=finv[i-1]*inv[i];
	 }
	//cout<<power(2,4);
	long long ans;
	//cout<<poww(a,n)<<" "<<poww(b,m);
	ans=((C(k,n)*poww(a,n)+mod)%mod*poww(b,m)+mod)%mod;
	cout<<ans<<endl;
	return 0;
}
