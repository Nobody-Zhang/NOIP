#include<cstdio>
#include<cctype>
const int maxn=55;
char maze[maxn][maxn];
int belong1[maxn][maxn],belong2[maxn][maxn];
int cnt=0;
struct edge{
    int to,next;
}lst[maxn*maxn*2];int len=1;
int first[maxn*maxn*2];
void addedge(int a,int b){
    lst[len].to=b;
    lst[len].next=first[a];
    first[a]=len++;
}
int T;int vis[maxn*maxn*2],match[maxn*maxn*2];
bool dfs(int x){
    for(int pt=first[x];pt;pt=lst[pt].next){
        if(vis[lst[pt].to]!=T){
            vis[lst[pt].to]=T;
            if(!match[lst[pt].to]||dfs(match[lst[pt].to])){
                match[lst[pt].to]=x;match[x]=lst[pt].to;
                return true;
            }
        }
    }return false;
}
bool block[maxn][maxn];
int main(){
    freopen("ju.in","r",stdin);
    freopen("ju.out","w",stdout);
    int n,m,q;scanf("%d%d%d",&n,&m,&q);
    int a,b;
    for(int i=1;i<=q;++i){
        scanf("%d%d",&a,&b);block[a][b]=true;
    }
    for(int i=1;i<=n;++i)block[i][0]=block[i][m+1]=true;

    for(int i=1;i<=m;++i)block[0][i]=block[n+1][i]=true;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(!block[i][j]){
                if(block[i][j-1])++cnt;
                belong1[i][j]=cnt;
            }
        }
    }
    int cnt2=cnt;
    for(int j=1;j<=m;++j){
        for(int i=1;i<=n;++i){
            if(!block[i][j]){
                if(block[i-1][j])++cnt2;
                belong2[i][j]=cnt2;
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(!block[i][j]){
                addedge(belong1[i][j],belong2[i][j]);
                addedge(belong2[i][j],belong1[i][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;++i){
        vis[i]=++T;
        if(!match[i]&&dfs(i))ans++;
    }
    printf("%d\n",ans);
    return 0;
}
