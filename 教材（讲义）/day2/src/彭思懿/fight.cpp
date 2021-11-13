#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
const long long oo=1e10;
ll tota=0,totb=0,n,m,a[maxn];
ll num1,num2,p;
int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	scanf("%lld%lld%lld%lld",&m,&p,&num1,&num2);
	a[p]+=num1;
	for(ll i=1;i<=n;i++)
	{   
	    ll dis=abs(i-m);
		if(i<m) tota+=dis*a[i];
		if(i>m) totb+=dis*a[i];
	}
    if(tota==totb) {printf("%lld",m);return 0;}
    ll k=m,tmp,ans=abs(tota-totb);
	for(ll i=1;i<=n;i++)
	{
		if(i<m)
		{
			tmp=abs(tota-totb+(m-i)*num2);
			if(tmp<ans){
				ans=tmp; k=i;
			} 
		}
		else if(i>m)
		{
			tmp=abs(totb-tota+(i-m)*num2);
			if(tmp<ans){
				ans=tmp; k=i;
			} 
		}
	}
	printf("%lld",k);
	return 0;
}
/*
6
1 1 1 1 1 16
5 4 1 1

6
2 3 2 3 2 3
4 6 5 2
*/
