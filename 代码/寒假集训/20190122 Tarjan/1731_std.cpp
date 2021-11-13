#include<cstdio>
#include<vector>
using namespace std;
const int maxn=10005;
vector<int> to[maxn];
int vis[maxn],low[maxn];
int T;
int stk[maxn],top;
bool in_stack[maxn];
int belong[maxn];
vector<int> scc[maxn];//strongly connected component
int W[maxn];
int tot=0;
int w[maxn];
void dfs(int x){
	low[x]=vis[x]=++T;
	stk[++top]=x;in_stack[x]=true;
	for(vector<int>::iterator pt=to[x].begin();pt!=to[x].end();++pt){
		if(vis[*pt]==0){
			dfs(*pt);
			if(low[*pt]<low[x])low[x]=low[*pt];
		}else{
			if(in_stack[*pt]&&vis[*pt]<low[x])low[x]=vis[*pt];
		}
	}
	if(low[x]==vis[x]){
		++tot;
		do{
			scc[tot].push_back(stk[top]);
			in_stack[stk[top]]=false;
			belong[stk[top]]=tot;
			W[tot]+=w[stk[top]];
		}while(stk[top--]!=x);
	}
}
vector<int> TO[maxn];
bool done[maxn];
int f[maxn];
int max(int a,int b){
	return a>b?a:b;
}
int dp(int x){
	if(done[x])return f[x];
	for(vector<int>::iterator pt=TO[x].begin();pt!=TO[x].end();++pt){
		f[x]=max(f[x],f[*pt]);
	}
	f[x]+=W[x];
	done[x]=true;
	return f[x];
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	int a,b;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&a,&b);
		to[a].push_back(b);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i])dfs(i);
	}
	for(int i=1;i<=n;++i){
		for(vector<int>::iterator pt=to[i].begin();pt!=to[i].end();++pt){
			if(belong[i]==belong[*pt])continue;
			TO[belong[i]].push_back(belong[*pt]);
		}
	}
	int ans=0;
	for(int i=1;i<=tot;++i){
		if(!done[i])ans=max(ans,dp(i));
	}
	printf("%d\n",ans);
	return 0;
}
