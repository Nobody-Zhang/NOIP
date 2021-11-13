#include <cstdio>
#include <algorithm>
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

int n,m,t[505],best[505][505];

int dfs(int now,int times)
{
	if(now==n+1) return 0;
	if(times<t[now]) return dfs(now,t[now]);
	if(best[now][times-t[now]]) return best[now][times-t[now]];
	
	int ret,tot=0,p=now;
    while(p<=n&&t[p]<=times)
	{
		tot+=t[p];
		p++;
	}
	ret=times*(p-now)-tot+dfs(p,times+m); 
	while(p<=n)
	{
		tot+=t[p];
		ret=std::min(ret,t[p]*(p-now+1)-tot+dfs(p+1,t[p]+m));
		p++;
	}
	
	return best[now][times-t[now]]=ret;
}

int main()
{
	input("bus.in");
	output("bus.out");
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	
	std::stable_sort(t+1,t+n+1);
	
	printf("%d",dfs(1,0));
	return 0;
}
