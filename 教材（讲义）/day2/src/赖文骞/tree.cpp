#include <cstdio>
#include <iostream>
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

struct data
{
	int lson,rson,val;
}tree[1000005];
bool tag;

int dfs(int nowl,int nowr,int add)
{
	if(nowl==-1&&nowr==-1) return 0;
	if(tree[nowl].val!=tree[nowr].val)
	{
		tag=false;
		
		return 0;
	}
	if(nowl==-1||nowr==-1)
	{
		tag=false;
		
		return 0;
	}
	
	return dfs(tree[nowl].lson,tree[nowr].rson,2)+dfs(tree[nowl].rson,tree[nowr].lson,2)+add;
}

int main()
{
	input("tree.in");
	output("tree.out");
	int n,ans=1;
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&tree[i].val);
	for(int i=1;i<=n;i++) scanf("%d%d",&tree[i].lson,&tree[i].rson);
	
	for(int i=1;i<=n;i++)
	{
		int tot;
		
		tag=true;
		tot=dfs(tree[i].lson,tree[i].rson,3);
		if(tag) ans=std::max(ans,tot);
	}
	
	printf("%d",ans);
	return 0;
}
