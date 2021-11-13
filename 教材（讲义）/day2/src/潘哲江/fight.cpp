#include<bits/stdc++.h>
using namespace std;
const int Maxn=100000+80;
long long n,c[Maxn],m,p1,s1,s2,vleft=0,vright=0,Mindif=0x3f3f3f3f,ans;
inline void input(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
	cin>>c[i];
    cin>>m>>p1>>s1>>s2;
    c[p1]+=s1;
}
inline void init(void)
{
    for(int i=1;i<m;i++)vleft+=(c[i]*(m-i));
    for(int i=m+1;i<=n;i++)vright+=(c[i]*(i-m));
}
inline void work(void)
{
    if(vleft<vright)
    {
        for(int i=1;i<=m;i++)
        {
            long long l=vleft+s2*(m-i);
            long long dif=abs(vright-l);
            if(dif<Mindif)
            {
                Mindif=dif;
                ans=i;
            }
        }
    }
    else if(vright<vleft)
    {
        for(int i=m;i<=n;i++)
        {
            long long r=vright+(i-m)*s2;
            long long dif=abs(r-vleft);
            if(dif<Mindif){
                
                Mindif=dif;
                ans=i;
            }
        }
    }
    else
    {
        ans=m;
    }
}
int main(void)
{
    freopen("fight.in","r",stdin);
    freopen("fight.out","w",stdout);
    input();
    init();
    work();
    printf("%lld\n",ans);
    return 0;
}
