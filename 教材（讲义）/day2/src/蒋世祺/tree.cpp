#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int n;
int size[maxn];
int v[maxn];
int ans;
struct tree{
	int ls,rs;
}tr[maxn];

int dfs(int rt){
	size[rt]=1;
	if(tr[rt].ls!=-1) size[rt]+=dfs(tr[rt].ls);
	if(tr[rt].rs!=-1) size[rt]+=dfs(tr[rt].rs);
	return  size[rt];
}

bool work(int x,int y){
	if(x==-1&&y==-1) return true;
	if(x!=-1&&y!=-1&&v[x]==v[y]&&work(tr[x].ls,tr[y].rs)&&work(tr[x].rs,tr[y].ls)) return true;
	return false;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&tr[i].ls,&tr[i].rs);
	dfs(1);
	for(int i=1;i<=n;i++){//±©Á¦²é 
		if(work(tr[i].ls,tr[i].rs)) ans=max(ans,size[i]);
	}
	printf("%d",ans);
}
