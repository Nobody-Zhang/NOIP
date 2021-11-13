#include<cstdio>
#include<cassert>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=305;
int n,m,q;
int v[maxn];
bool cmp(const int &a,const int &b){
    return v[a]<v[b];
}
int seq[maxn];
ll dis[maxn][maxn];
ll ans[maxn][maxn];
ll min(ll a,ll b){
    return a<b?a:b;
}
ll max(ll a,ll b){
    return a>b?a:b;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    assert(n<=300&&m<=40000);
    for(int i=1;i<=n;++i)scanf("%d",v+i);
    for(int i=1;i<=n;++i)seq[i]=i;
    sort(seq+1,seq+n+1,cmp);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            ans[i][j]=dis[i][j]=(1LL<<60);
        }
    }
    for(int i=1;i<=n;++i)dis[i][i]=0;
    for(int i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        assert(x!=y);assert(1<=z&&z<=1000000000);
        dis[x][y]=dis[y][x]=min(dis[x][y],z);
    }
    for(int p=1;p<=n;++p){
        int k=seq[p];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(i!=j)ans[i][j]=min(ans[i][j],dis[i][j]+max(max(v[i],v[j]),v[k]));
            }
        }
    }
    int a,b;
    while(q--){
        scanf("%d%d",&a,&b);assert(a!=b);
        assert(ans[a][b]!=(1LL<<60));
        printf("%lld\n",ans[a][b]);
    }
    return 0;
}