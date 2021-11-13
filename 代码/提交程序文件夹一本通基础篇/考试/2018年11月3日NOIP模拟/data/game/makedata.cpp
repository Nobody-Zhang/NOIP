#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<ctime>
#define SF scanf
#define PF printf
#define DELTA 10
#define MAXN 1000
#define MAXM 80
using namespace std;
int get_rand(int x){
	return rand()*rand()%x+1;	
}
int fa[MAXN];
int get_fa(int x){
	if(fa[x]==0)
		return x;
	fa[x]=get_fa(fa[x]);
	return fa[x];	
}
void merge(int u,int v){
	u=get_fa(u);
	v=get_fa(v);
	if(u==v)
		return ;
	if(get_rand(2)==1)
		swap(u,v);
	fa[u]=v;	
}
int main(){
	srand(time(0));	
	int n=MAXN-get_rand(DELTA);
	int m=get_rand(MAXM);
	PF("%d\n",n);
	for(int i=1;i<=m;i++){
		int u=get_rand(n);
		int v=get_rand(n);
		merge(u,v);
	}
	for(int i=1;i<=n;i++){
		get_fa(i);
		if(fa[i]==0)
			PF("-1 ");
		else
			PF("%d ",fa[i]);
	}
}
