#include<bits/stdc++.h>
using namespace std;
long long ksm(long long a,long long b,int mod)
{//a^b%mod
	long long ans=1;
	while(b)
	{
		if(b%2==1) 
		ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
int main()
{
	long long m,n,k;
	cin>>m>>n>>k;
	long long ans=ksm(m,n,k);
	cout<<m<<"^"<<n<<" mod "<<k<<"="<<ans<<endl;
	return 0;
}
