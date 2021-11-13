#include<bits/stdc++.h>
using namespace std;
#define Max 100001 
int inc,head[Max],n,m,in[Max],out[Max],dp[Max];
bool used[Max*2+5];
struct s{
	int data,last;
}edge[Max*2+5];
queue<int>q;
void add(int a,int b)
{
	inc++;
	edge[inc].data=b;
	edge[inc].last=head[a];
	head[a]=inc;
	return;
}
void topsort()
{
	for(int i=1;i<=n;i++)
		if(in[i]==0) {
			q.push(i);
			dp[i]=1;
		}
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=head[now];i;i=edge[i].last)
		if(used[i]==false)
		{
			 used[i]=true;
			 int tmp=edge[i].data;
			 dp[tmp]+=dp[now];
			 q.push(tmp);
		}
	}
	return;
}
int main()
{
//	freopen("test.in","r",stdin); 
	scanf("%d%d",&n,&m);//n个点,m条边 
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(b,a);//全部反着来，拓扑排序 
		out[b]++;
		in[a]++;
	}
	topsort();
	int ans=0;
	for(int i=1;i<=n;i++)
		if(out[i]==0) ans+=dp[i];
//	for(int i=1;i<=n;i++)
//	cout<<dp[i]<<" ";
//	cout<<endl<<"_______________"<<endl;
//	for(int i=1;i<=n;i++)
//	cout<<in[i]<<" "<<out[i]<<" "<<endl;
	printf("%d",ans);
	return 0;
}
