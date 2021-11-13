#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 300005 ;
int n, m , first[MAXN] , nexts[MAXN<<1] , to[MAXN<<1] , egnum , vis[MAXN], inStack[MAXN] , inDeg[MAXN] ;
char str[MAXN] ;

void addEdge(int a, int b){
	nexts[++egnum]=first[a], first[a]=egnum , to[egnum]=b , inDeg[b]++ ;
}

int dfs(int a){
	inStack[a] = vis[a] = true ;
	for(int i=first[a];i;i=nexts[i]){
		int b=to[i] ;
		if(inStack[b]) return -1 ;
		if(!vis[b]) {
			if(dfs(b)==-1) return -1 ;
		}
	}
	inStack[a] = false ;
	return 0 ;
}

int que[MAXN] , head , tail , dp[MAXN][26] ;

void topoSort(){
	head=tail=0 ;
	for(int i=1;i<=n;++i) if(inDeg[i]==0){
		que[tail++]=i;
		dp[i][str[i]-'a'] = 1 ;
	}
	while(head<tail){
		int a=que[head++] ;
		for(int i=first[a];i;i=nexts[i]){
			int b=to[i] ;
			for(int j=0;j<26;++j) dp[b][j]=max(dp[b][j], dp[a][j]) ;
			int c=str[b]-'a';
			dp[b][c]=max(dp[b][c], dp[a][c]+1) ;
			if(--inDeg[b] == 0){
				que[tail++]=b;
			}
		}
	}
}

int main(){
	scanf("%d%d%s",&n,&m,str+1) ;
	for(int i=1;i<=m;++i){
		int a,b;
		scanf("%d%d",&a,&b) ;
		addEdge(a,b) ;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i] && dfs(i)==-1){
			printf("-1\n") ;
			return 0 ;
		}
	}
	topoSort() ;
	int ans=0 ;
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j){
			ans = max(ans, dp[i][j]) ;
		}
	}
	printf("%d\n",ans) ;
	return 0 ;
}
