#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define maxn 100005
struct zgb{
	int data,last;
}edge[maxn*2+2];
int head[maxn],inc,n,m,in[maxn],cnt;
void add(int a,int b)
{
	inc++;
	edge[inc].data=b;
	edge[inc].last=head[a];
	head[a]=inc;
	return;
}
int dfs(int x,int y)
{
	for(ri i=head[x];i;i=edge[i].last)
	{
		if(edge[i].data<=y)
		{
			dfs(edge[i].data,y);
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	freopen("rise.in","r",stdin);
	freopen("rise.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;i++)
		scanf("%d",&in[i]);
	for(ri i=1;i<=n;i++)
		for(ri j=i;j<=n;j++)//当前向后至少多少个相同的 
			if(in[i]<in[j]) {
				add(i,j);break;
			}
	while(m--)
	{
		int x,y;
		cnt=1;
		scanf("%d%d",&x,&y);
		printf("%d\n",dfs(x,y));
	}
	return 0;
}
