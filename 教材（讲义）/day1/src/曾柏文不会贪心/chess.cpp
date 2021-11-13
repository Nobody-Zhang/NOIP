#include<bits/stdc++.h>

#define maxn 101*101

#define maxm 101*102*5

using namespace std;

struct way
{
	int to,pre,val;
}e[maxm];

bool v[maxn];

int n,m,col[maxn],head[maxn],cnt=0,dist[maxn],ans=0x3f3f3f;

priority_queue <pair <int,int>  > q;

inline void add(int a,int b,int val)
{
	e[++cnt].to=b;
	e[cnt].val=val;
	e[cnt].pre=head[a];
	head[a]=cnt;
}

inline void addedge(int i)
{
	if(i%m!=1&&col[i-1]!=-1)
	{
		if(col[i-1]==col[i]) add(i,i-1,0);
		else add(i,i-1,1);	
	}
	if(i>m&&col[i-m]!=-1)
	{
		if(col[i-m]==col[i]) add(i,i-m,0);
		else add(i,i-m,1);
	}
	if(i%m!=0&&col[i+1]!=-1)
	{
		if(col[i+1]==col[i]) add(i,i+1,0);
		else add(i,i+1,1);
	}
	if(m*m-i>=m&&col[i+m]!=-1)
	{
		if(col[i+m]==col[i]) add(i,i+m,0);
		else add(i,i+m,1);
	}
}

void dijkstra()
{
	memset(dist,0x3f,sizeof(dist));
	memset(v,0,sizeof(v));
	dist[1]=0;
	q.push(make_pair(0,1));
	while(q.size())
	{
		int x=q.top().second; q.pop();
		if(v[x]) continue; v[x]=1;
		for(int i=head[x];i;i=e[i].pre)
		{
			int y=e[i].to;
			int z=e[i].val;
			if(dist[y]>dist[x]+z) { dist[y]=dist[x]+z; q.push(make_pair(-dist[y],y));}
		}
	}

}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m*m;i++)
	{
		head[i]=0;
		col[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		col[(x-1)*m+y]=z;
	}
	for(int i=1;i<=m*m;i++)
	{
		if(col[i]==-1)
		{
			int top=0,stack1[5];
			if(i%m!=1&&col[i-1]!=-1) stack1[++top]=i-1;
			if(i>m&&col[i-m]!=-1) stack1[++top]=i-m;
			if(i%m!=0&&col[i+1]!=-1) stack1[++top]=i+1;
			if(m*m-i>=m&&col[i+m]!=-1) stack1[++top]=i+m;
			for(int ii=1;ii<=top;ii++)
				for(int j=ii+1;j<=top;j++)
				{
					if(col[stack1[ii]]==col[stack1[j]])
					{
						add(stack1[ii],stack1[j],2);
						add(stack1[j],stack1[ii],2);
					}
					else
					{
						add(stack1[ii],stack1[j],3);
						add(stack1[j],stack1[ii],3);
					}
					
				}
		}
		addedge(i);
	}
	dijkstra();
	if(col[m*m]==-1)
	{
		if(col[m*m-1]==-1&&col[m*m-m]==-1) { printf("-1"); return 0;}
		int ans=min(dist[m*m-m],dist[m*m-1])+2;
		if(ans<=10611095) printf("%d",ans);
		else printf("-1");
		return 0;
	}
	if(dist[m*m]<=10611095) printf("%d",dist[m*m]);
	else printf("-1");
	return 0;
}
/*

*/
