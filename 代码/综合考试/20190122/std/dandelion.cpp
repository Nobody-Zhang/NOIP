#include<cassert>
#include<cstdio>
#include<vector>
using namespace std;
const int maxm=500005,maxt=200005,maxn=100005;
int seq[maxm];
int cnt[maxt];
vector<int> to[maxn];
int n,T;
int vis[maxn],timer=0;
int ext[maxn];
bool flag;
void dfs(int x){
    vis[x]=timer;
    for(vector<int>::iterator pt=to[x].begin();pt!=to[x].end();++pt){
        if(vis[*pt]!=timer){
            dfs(*pt);;
        }else if(ext[*pt]!=timer)flag=false;
    }
    ext[x]=timer;
}   
bool toposort(){
    ++timer;flag=true;
    for(int i=1;i<=n;++i){
        if(vis[i]!=timer)dfs(i);
    }
    return flag;
}
bool check(int x){
    if(x==0)return true;
    for(int i=1;i<=n;++i)to[i].clear();
    for(int i=1;i<=x;++i){
        for(int j=cnt[i-1]+1;j<cnt[i];++j){
            to[seq[j]].push_back(seq[j+1]);
        }
    }
    return toposort();
}
int main(){
    freopen("dandelion.in","r",stdin);
    freopen("dandelion.out","w",stdout);
    scanf("%d%d",&n,&T);
    for(int i=1;i<=T;++i){
        scanf("%d",cnt+i);
        cnt[i]+=cnt[i-1];if(cnt[i]>maxm)assert(0);
        for(int j=cnt[i-1]+1;j<=cnt[i];++j){
            scanf("%d",seq+j);
        }
    }
    int l=0,r=T;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    assert(cnt[T]<=500000);
    printf("%d\n",l-1);
    //printf("%d\n",cnt[T]);
    return 0;
}