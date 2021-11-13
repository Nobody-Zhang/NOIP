#include <bits/stdc++.h>
using namespace std;

const int Max=500005;
int n,m,k,d,head,tail,l,r,mid,maxlen,minlen,now,tag;
int x[Max],num[Max],f[Max],p[Max];

inline int get_int()
{
    int x=0,f=1;
    char c;
    for(c=getchar();(!isdigit(c))&&(c!='-');c=getchar());
    if(c=='-') f=-1,c=getchar();
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}

inline bool check(int len)
{
    now=0,head=1,tail=0,maxlen=len+d,minlen=max(d-len,1);
    for(int i=1;i<=n;i++)
    {
      while(x[now]<=x[i]-minlen)
      {
        if(f[now]<=-1e9) {now++;continue;}
        while(head<=tail&&f[now]>=f[p[tail]]) tail--;
        p[++tail]=now,now++;   
      }
      while(head<=tail&&x[p[head]]<x[i]-maxlen) head++;
      if(head<=tail) f[i]=f[p[head]]+num[i];
      else f[i]=-1e9;
      if(f[i]>=k) return 1;
    }
    return 0;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    n=get_int(),d=get_int(),k=get_int();
    for(int i=1;i<=n;i++) x[i]=get_int(),num[i]=get_int();
    l=0,r=500000;
    while(l<r)
    {
      mid=(l+r)>>1;
      if(check(mid)) tag=1,r=mid;
      else l=mid+1;
    }
    if(tag) cout<<r;
    else cout<<"-1\n";
    return 0;
}
