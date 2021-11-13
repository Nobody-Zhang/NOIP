//#pragma GCC optimize(2) 
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int t;
#define maxm 4005
#define maxn 60005
struct tr{
	int data,last;
}edge[maxn];
int inc,head[maxm],match[maxn];
bool used[maxn];
void add(int a,int b){
	inc++;
	edge[inc].data=b;
	edge[inc].last=head[a];
	head[a]=inc;
	return;
}
bool dfs(int x)
{
	for(int i=head[x];i;i=edge[i].last){
		int now=edge[i].data;
		if(used[now]==false)
		{
			used[now]=true;
			if(match[now]==0||dfs(match[now]))
			{
				match[now]=x;
				return true;
			}
		}
	}
	return false;
}
int vis[maxn],timer;
/*bool dfs(int x)
{
	if(vis[x]==timer) return false;
	vis[x]=timer;
	for(int i=head[x];i;i=edge[i].last){
		int now=edge[i].data;
		if(match[now]==0||dfs(match[now])==true){
			match[now]=x;
			return true;
		}
	}
	return false;
}*/
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int p,n;
		scanf("%d%d",&p,&n);
		inc=0;
		for(int i=1;i<=p;i++){
			int tot;
			scanf("%d",&tot);
			while(tot--){
				int a;
				scanf("%d",&a);
				add(i,p+a);
				add(a+p,i);
			}
		}
		int ans=0;
		for(int i=1;i<=p;i++){//从左边开始遍历 
			{
				for(int j=1;j<=p+n;j++)
				 used[j]=false;
				//timer++;
				if(dfs(i)) ans++;
			}
		}
		if(ans==p) printf("YES\n");
		else printf("NO\n");
		for(int i=1;i<=n+p;i++)match[i]=head[i]=0;
	}
}
