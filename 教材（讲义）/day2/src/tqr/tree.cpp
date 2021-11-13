#include<bits/stdc++.h>
#define fo(i,j,k) for(register int i=j;i<=k;i++)
using namespace std;

int n,son[1000050][2];
int val[1000050],size[1000050];
int ans;

template<class T> inline void read(T &re)
{
	re=0;T sign=1;char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');re*=sign;
}

inline void dfs(int u)
{
	size[u]=1;
	if (son[u][0]!=-1){dfs(son[u][0]);size[u]+=size[son[u][0]];}
	if (son[u][1]!=-1){dfs(son[u][1]);size[u]+=size[son[u][1]];}
}

bool check(int u,int v)
{
	if (v==-1&&u==-1) return 1;
	if (v!=-1&&u!=-1&&val[u]==val[v]&&check(son[u][0],son[v][1])&&check(son[u][1],son[v][0])) return 1;
	return 0;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	fo(i,1,n) read(val[i]);
	fo(i,1,n){read(son[i][0]);read(son[i][1]);}
	dfs(1);
	fo(i,1,n) if (check(son[i][0],son[i][1])) ans=max(ans,size[i]);
	printf("%d\n",ans);
	return 0;
}
