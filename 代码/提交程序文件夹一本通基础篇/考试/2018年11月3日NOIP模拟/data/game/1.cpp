#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 100010
#define MOD 1000000007
using namespace std;
int bit[MAXN];
int u,cnt[MAXN],n;
int main(){
    SF("%d",&n);
    bit[0]=1;
    for(int i=1;i<=n;i++)
        bit[i]=(bit[i-1]<<1)%MOD;
    for(int i=1;i<=n;i++){
        SF("%d",&u);
        if(u!=-1)
            cnt[u]++;
    }
    int ans=bit[n-1]-1;
    for(int i=1;i<=n;i++){
        ans=(ans-(bit[cnt[i]]-1))%MOD;
    }
    PF("%d",(ans+MOD)%MOD);

}
