#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long f[100005];
long long inv[100005];
long long finv[100005];
long long catlan[100005];
int m,typ,ans;
/*long long A(int a,int b)
{
	
}*/
long long C(int a,int b)
{//a>b
	if(b==0) return 1;
	if(a==b) return 1;
	long long k=1;
	k=((f[a]*finv[a-b])%mod*finv[b]+mod)%mod;
	return k;
}
long long A(int a,int b)
{
	long long k=1;
	k=f[a]%mod;
	return k;
}
void f1()
{//相当于两个栈加括号 
	long long ans=0;
	int n=m/2;
	/*for(int i=0;i<=n;i++)
	 ans=(ans+A(m,m)*C(n,i)*C(n,i)+mod)%mod;*/
	ans=(C(m,n)*C(m,n)+mod)%mod;
	cout<<ans<<endl;
	exit(0);
}
void f2()
{
	long long ans;
	catlan[0]=1;
	int n=m/2;
	ans=(C(2*n,n)-C(2*n,n-1)+mod)%mod;
	cout<<ans<<endl;
	exit(0);
}
void f3()
{
	long long ans=0;
	int n=m/2;
	for(int i=0;i<=n;i++)
	 ans=(ans+A(m,m)*C(n,i)*C(n,i)+mod)%mod;
	cout<<ans<<endl;
	exit(0);
}
void f4()
{
	long long ans=0;
	int n=m/2;
	for(int i=0;i<=n;i++)
	 ans=(ans+A(m,m)*C(n,i)*C(n,i)+mod)%mod;
	cout<<ans<<endl;
	exit(0);
}
int main()
{
	//freopen("problem.in","r",stdin);
	//freopen("problem.out","w",stdout);
	scanf("%d%d",&m,&typ);
	f[0]=1;
	for(int i=1;i<=100000;i++) f[i]=f[i-1]*i%mod;
	inv[1]=1;//floor
	for(int i=2;i<=100000;i++){
		int tmp=floor(1.0*mod/i);
	 	inv[i]=(mod-tmp*inv[mod%i]%mod+mod)%mod;
	}
	finv[1]=1;
	for(int i=2;i<=100000;i++) finv[i]=finv[i-1]*inv[i]%mod;
	if(typ==0) f1();
	if(typ==1) f2();
	if(typ==2) f3();
	if(typ==3) f4();
}
