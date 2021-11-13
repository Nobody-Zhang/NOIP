#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int t,n,m;
int nt[maxn];
double dp[maxn];

int get(int x){
	while(nt[x]) x=nt[x];
	return x;
}

int main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+10;i++) nt[i]=dp[i]=0;
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			nt[x]=y;
		}
		
		dp[n]=0;
		for(int i=n-1;i>=0;i--){
			int x=get(i);
			for(int j=1;j<=6;j++)
			 dp[i]+=1.0/6*(dp[get(x+j)]+1);
		}
		printf("%.2lf\n",dp[0]);
	}
}
