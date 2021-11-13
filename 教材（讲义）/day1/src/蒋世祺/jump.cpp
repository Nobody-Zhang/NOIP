#include<bits/stdc++.h>
using namespace std;

int ans=-1;
const int maxn=5e5+5;
int n,d,goal;
int pos[maxn],val[maxn];
long long dp[maxn];
int q[maxn];
int head,tail;

bool check(int mid){
    long long an=0x8080808080808080;
    int mi=max(1,d-mid);
    int mx=d+mid;
    head=1;tail=0;
    q[++tail]=0;
    int fir=-1;
    memset(dp,0x80,sizeof(dp));
    dp[0]=0;
    
    
    for(int i=1;i<=n;i++){
        if(pos[i]<mi)  continue;
        if(pos[i]>=mi&&fir==-1)  fir=i;
        if(pos[i]-pos[i-1]>mx) break;
        while(mi<=pos[i]-pos[fir]&&fir<i){
            while(head<=tail&&dp[fir]>=dp[q[tail]]) tail--;
            q[++tail]=fir++;
        }
        while(head<=tail&&pos[q[head]]+mx<pos[i]) head++;
        if(head<=tail) dp[i]=dp[q[head]]+val[i];
        if(an<dp[i]) an=dp[i];
    }
    return an>=goal;
}

int main(){
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    scanf("%d%d%d",&n,&d,&goal);
    for(int i=1;i<=n;i++)  scanf("%d%d",&pos[i],&val[i]);
    int l=0,r=pos[n];
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
          else l=mid+1;
    }
    printf("%d",ans);
}
/*
7 4 10 
2 6
5 -3
10 3 
11 -3
13 1 
17 6 
20 2 
*/
