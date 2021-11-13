#include<bits/stdc++.h>
using namespace std;
long long m,n,ans;//m个房间n种信仰 
#define mod 100003
long long supermi(long long a,long long b){
	//a^b
	long long tmp=a,tpas=1;
	while(b)
	{
		if(b%2==1) tpas=tpas*tmp%mod;
		tmp=tmp*tmp%mod;
		b=b/2;
	}
	return tpas;
}
int main()
{
	cin>>n>>m;
	cout<<(supermi(n,m)-n*supermi(n-1,m-1)%mod+mod)%mod<<endl;
	return 0;
} 
