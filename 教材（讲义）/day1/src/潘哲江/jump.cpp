#include<bits/stdc++.h>
using namespace std;
inline int rd(){
  int ret=0,f=1;char c;
  while(c=getchar(),!isdigit(c))f=c=='-'?-1:1;
  while(isdigit(c))ret=ret*10+c-'0',c=getchar();
  return ret*f;
}
#define space() putchar(' ')
#define nextline() putchar('\n')
void pot(int x){if(!x)return;pot(x/10);putchar('0'+x%10);}
void out(int x){if(!x)putchar('0');if(x<0)putchar('-'),x=-x;pot(x);}
const int MAXN = 500005;
int n,d,aim;
int dis[MAXN],val[MAXN];
int f[MAXN];
int q[MAXN];
bool check(int x){
    int l=1,r=0;
    memset(f,0,sizeof(f));
    memset(q,0,sizeof(q));
    f[0]=0;
    int kl=max(1,d-x),kr=d+x;
    int j=0;
    for(int i=1;i<=n;i++){
        while(j<i&&dis[j]+kl<=dis[i]){
            while(l<=r&&f[q[r]]<=f[j]) r--;
            if(f[j]==-(1<<30)){j++;continue;}
            q[++r]=j++;
        }
        while(l<=r&&dis[q[l]]+kr<dis[i])l++;
        if(l<=r) f[i]=f[q[l]]+val[i];
        else f[i]=-(1<<30);
        if(f[i]>=aim) return 1;
    }
    return 0;
}
int main(){
	freopen("jump.in","r",stdin);
   	freopen("jump.out","w",stdout);
    n=rd();d=rd();aim=rd();
    for(int i=1;i<=n;i++)dis[i]=rd(),val[i]=rd();
    int l=0,r=1e9,mid,ans=-1;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;   
    }
    out(ans);
    return 0;
}
