#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int minpos[maxn][22],lg2[maxn],n,k,l,r,in[maxn];
long long sum[maxn],minn[maxn][22];
struct Node{
	int ll,rr,r,pos;
	Node (int oll=0,int orr=0,int orrr=0,int opos=0){
		ll=oll,rr=orr,r=orrr,pos=opos;
	}
};
priority_queue<Node>q;
bool operator< (const Node &a,const Node b){
	return sum[a.r]-sum[a.pos]<sum[b.r]-sum[b.pos];
}
void init()
{
	lg2[0]=-1;
	for(int i=0;i<=n;i++)
	{
		if(i) lg2[i]=(i&(i-1))?lg2[i-1]:lg2[i-1]+1;
		minn[i][0]=sum[i];minpos[i][0]=i;
	}
	for(int k=1;k<=lg2[n];k++)
		for(int i=0;i<=n;i++)
			if(i+(1<<(k-1))<=n){
				minn[i][k]=min(minn[i][k-1],minn[i+(1<<(k-1))][k-1]);
				minpos[i][k]=(minn[i][k-1]<minn[i+(1<<(k-1))][k-1])?minpos[i+(1<<(k-1))][k-1]:minpos[i][k-1];
			}
			else{
				minn[i][k]=minn[i][k-1];
				minpos[i][k]=minpos[i][k];
			}
}
int query(int l,int r)
{
	l=max(l,0);
	if(l>r) return -1;
	int t=lg2[r-l+1];
	return (minn[l][t]<minn[r-(1<<t)+1][t])?minpos[l][t]:minpos[r-(1<<t)+1][t];
}
void add(int ll,int rr,int r)
{
	int pos=query(r-rr,r-ll);
	if(pos!=-1) q.push(Node(ll,rr,r,pos));
}
int main()
{
	freopen("kth.in","r",stdin);
	freopen("kth.out","w",stdout);
	scanf("%d%d%d%d",&n,&k,&l,&r);
	for(int i=1;i<=n;i++)
		scanf("%d",&in[i]),sum[i]=sum[i-1]+in[i];
	init();
	for(int i=1;i<=n;i++) add(l,r,i);
	long long ans=0;
	while(k--)
	{
		Node a=q.top();
		q.pop();
		ans+=(sum[a.r]-sum[a.pos]);
		int len=a.r-a.pos;
		if(len!=a.ll) add(a.ll,len-1,a.r);
		if(len!=a.rr) add(len+1,a.rr,a.r);
	}
	cout<<ans<<endl;
	return 0;
}
