#include<bits/stdc++.h>
using namespace std;]
long long zh(long long n,long long m,long long mod)
{//C(n,m)
	long long ans=1;
	for(long long i=n;i>=n-m+1;i--)
	{
		ans*=ans;
		ans%=mod;
	}
	for(long long i=m;i>=1;i--)
	{
		//ans/==>ÇóÄæÔª!!! 
	}
}
void solve(int n,int m,int k)
{//ÇóC(m+n,n)%k 
	long long ans=1;
	long long m1=m,n1=n;
	while(1)
	{
		if(m1/p==0&&n1/p==0) break;
		ans=(ans*zh(m1%mod,m2%mod,mod))%mod;
		m1=m1/mod;
		n1=n1/mod;
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	int tot;
	cin>>tot;
	for(int i=1;i<=a;i++)
	 {
	 	int a,b,k;
		cin>>a>>b>>k;
		solve(a,b,k);
	 }
	 return 0;
}
