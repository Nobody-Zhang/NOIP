#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
using namespace std;
const int maxn=100005;
vector<int> to[maxn];
int deg[maxn];
int vis[maxn];int timer=0;
int cntodd=0;
void dfs(int x){
    vis[x]=timer;
    if(deg[x]&1)cntodd++;
    for(vector<int>::iterator pt=to[x].begin();pt!=to[x].end();++pt){
        if(vis[*pt]!=timer)dfs(*pt);
    }
}
int sumN=0,sumM=0;
void work(){
    int n,m;scanf("%d%d",&n,&m);sumN+=n;sumM+=m;
    //assert(n<=m);//printf("%d %d\n",n,m);
    for(int i=0;i<=n;++i)deg[i]=0;
    int a,b;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&a,&b);deg[a]++;deg[b]++;
        to[a].push_back(b);to[b].push_back(a);
    }
 //   assert(deg[0]==0);
    ++timer;
    int cntblock=0;
    int ans=0;
    int cntodd0=0;
    for(int i=0;i<=n;++i){
        if(deg[i]!=0&&vis[i]!=timer){
            cntblock++;
            cntodd=0;dfs(i);
            if(cntodd>2)ans+=(cntodd-2)/2;
            if(i==0)cntodd0=cntodd;
        }
    }// assert(cntblock==1);
    if(cntblock==0)printf("0\n");
    else if(cntblock==1){
        if(deg[0]==0){
            printf("%d\n",2+ans);
        }else{
            printf("%d\n",cntodd0/2);
        }
    }else{
        if(deg[0]==0)printf("%d\n",cntblock+ans+1);
        else printf("%d\n",cntblock+ans);
    }
    for(int i=0;i<=n;++i)to[i].clear();
}
int main(){
    freopen("vine.in","r",stdin);
    freopen("vine.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--){
        work();
    }
    assert(sumN<=100000);assert(sumM<=500000);
    return 0;
}