#include<bits/stdc++.h>
#define maxn 100002
using namespace std;
long long lq=0,hq=0,n,m,a[maxn];
long long num1,num2,p;
int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
    scanf("%lld%lld%lld%lld",&m,&p,&num1,&num2);
    a[p]+=num1;
    for(long long i=1;i<=n;i++)
    {   
        long long dis=abs(i-m);
        if(i<m)lq+=dis*a[i];
        if(i>m)hq+=dis*a[i];
    }
    if(lq==hq) {printf("%lld",m);return 0;}
    long long putin=m,tmp,ans=abs(lq-hq);
    for(long long i=1;i<=n;i++)
    {
        if(i<m)
        {
            tmp=abs(lq-hq+(m-i)*num2);
            if(tmp<ans){ans=tmp;putin=i;} 
        }
        if(i>m)
        {
            tmp=abs(hq-lq+(i-m)*num2);
            if(tmp<ans){ans=tmp;putin=i;} 
        }
    }
    printf("%lld",putin);
    return 0;
}
