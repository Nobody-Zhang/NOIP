#include<bits/stdc++.h>
#define reg register
using namespace std;
list<int>q;
int n,d,k,x[500001],s[500001],f[500001],mid;
int R()
{
    reg int x=0;reg char ch=getchar();reg bool f=0;
    for(;ch<48||ch>57;ch=getchar())if(ch==45)f=1;
    for(;ch>=48&&ch<=57;ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return f?-x:x;
}
bool check(int g)
{
    while(!q.empty())q.pop_back();
    int minn,maxx=d+g,now=0;
    minn=g>=d?1:d-g;
    x[0]=s[0]=f[0]=0;
    for(reg int i=1;i<=n;i++)
    {
        f[i]=-1;
        for(;now<i&&x[i]-x[now]>=minn;now++)
        {
            if(f[now]!=-1)
            {
                while(f[now]>=f[q.back()]&&!q.empty())q.pop_back();
                q.push_back(now);
            }
        }
        while(x[i]-x[q.front()]>maxx&&!q.empty())q.pop_front();
        if(!q.empty())f[i]=f[q.front()]+s[i];
        if(f[i]>=k){return true;}
    }
    return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    n=R();d=R();k=R();
    //printf("%d\n",k);
    for(int i=1;i<=n;i++)x[i]=R(),s[i]=R();
    long long left=0,right=x[n];
    while(left<right)
    {
        mid=(left+right)>>1;
        if(check(mid))right=mid;
        else left=mid+1;
    }
    printf("%lld",right);
    return 0;
}
