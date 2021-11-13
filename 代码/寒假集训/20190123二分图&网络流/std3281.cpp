#include<cstdio>
#include<cstring>
const int maxn=402,maxm=20300;
int s,t;
struct edge{
	int to,next,w;
}lst[maxm<<1];int len=0;//x^1 lst[x] lst[x^1]
int first[maxn];
int N,F,D;
void Addedge(int a,int b,int w){
	lst[len].to=b;lst[len].next=first[a];lst[len].w=w;first[a]=len++;
}
void addedge(int a,int b,int w){
	Addedge(a,b,w);
	Addedge(b,a,0);
}
int q[maxn],dis[maxn],vis[maxn];int timer=0;
bool bfs(){
	int head=0,tail=0;
	q[tail++]=s;
	dis[s]=0;vis[s]=++timer;
	while(head!=tail){
		int x=q[head++];
		for(int pt=first[x];pt!=-1;pt=lst[pt].next){
			if(lst[pt].w==0)continue;
			if(vis[lst[pt].to]!=timer){
				vis[lst[pt].to]=timer;
				dis[lst[pt].to]=dis[x]+1;
				q[tail++]=lst[pt].to;
			}
		}	
	}
	return vis[t]==timer;
}
int min(int a,int b){
	return a<b?a:b;
}
int dfs(int x,int lim){
	if(x==t)return lim;
	int ans=0;
	for(int pt=first[x];pt!=-1;pt=lst[pt].next){
		if(lst[pt].w!=0&&dis[lst[pt].to]==dis[x]+1){
			int y=dfs(lst[pt].to,min(lst[pt].w,lim));
			if(y!=0){
				lst[pt].w-=y;lst[pt^1].w+=y;
				ans+=y;lim-=y;
				if(lim==0)return ans;
			}
		}
	}
	return ans;
}
int dinic(){
	int ans=0;	
	while(bfs())ans+=dfs(s,0x3f3f3f3f);
	return ans;
}
int main(){
	memset(first,-1,sizeof(first));
	scanf("%d%d%d",&N,&F,&D);
	//1-F,F+1...F+N,F+N+1...F+N+D
	s=0;t=N+N+F+D+1;
	for(int i=1;i<=N;++i){
		int fi,di;
		scanf("%d%d",&fi,&di);
		for(int j=1;j<=fi;++j){
			int x;scanf("%d",&x);
			addedge(x,F+i,1);	
		}
		for(int j=1;j<=di;++j){
			int x;scanf("%d",&x);
			addedge(F+N+i,F+N+N+x,1);
		}
		addedge(F+i,F+N+i,1);
	}
	for(int i=1;i<=F;++i)addedge(s,i,1);
	for(int i=1;i<=D;++i)addedge(F+N+N+i,t,1);
	printf("%d\n",dinic());
	return 0;
}

