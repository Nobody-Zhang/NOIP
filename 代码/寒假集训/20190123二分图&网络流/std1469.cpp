#include<cstdio>
const int maxn=405,maxm=60005;
struct edge{
	int to,next;
}lst[maxm];int len=1;
int first[maxn];
void addedge(int a,int b){
	lst[len].to=b;lst[len].next=first[a];first[a]=len++;
}
int P,N;
int match[maxn];//match[i]==j
int vis[maxn],timer=0;
bool dfs(int x){//从x出发寻找增广路，x是非匹配点 
	if(vis[x]==timer)return false;
	vis[x]=timer;
	for(int pt=first[x];pt;pt=lst[pt].next){
		if(!match[lst[pt].to]||dfs(match[lst[pt].to])){
			match[lst[pt].to]=x;return true;
		}/*else{
			//match[lst[pt].to]!=0
			if(dfs(match[lst[pt].to]){
				match[lst[pt].to]=x;return true;
			}
		}*/
	}
	return false;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&P,&N);
		for(int i=1;i<=P;++i){
			int cnt;scanf("%d",&cnt);
			while(cnt--){
				int x;scanf("%d",&x);
				addedge(i,P+x);addedge(P+x,i);
			}
		}
		int ans=0;
		for(int i=1;i<=P;++i){
			++timer;
			if(dfs(i))ans++;
		}
		printf("%s\n",(ans==P)?"YES":"NO");
		len=1;
		for(int i=1;i<=N+P;++i)first[i]=0;
		for(int i=1;i<=N+P;++i)match[i]=0;
	
	}
	return 0;
}
