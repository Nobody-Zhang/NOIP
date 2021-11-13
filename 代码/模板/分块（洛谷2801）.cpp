#include<bits/stdc++.h>
using namespace std;
#define maxn 1000001 
vector<int>v[maxn];
int m,n,data[maxn],size,num,pos[maxn],delta[maxn];
void refresh(int b)
{
	v[b].clear();
	for(int i=(b-1)*size+1;i<=b*size&&i<=m;i++)
		v[b].push_back(data[i]);
	sort(v[b].begin(),v[b].end());
}
int queryblock(int b,int x)
{
	return v[b].end()-lower_bound(v[b].begin(),v[b].end(),x-delta[b]);
}
int query(int from,int to,int minn)
{
	int ans=0;
	for(int i=from;i<=pos[from]*size&&i<=to;i++){
		if(data[i]+delta[pos[from]]>=minn) ans++;
	}
	if(pos[from]!=pos[to]){
		for(int i=(pos[to]-1)*size+1;i<=to;i++)
		{
			if(data[i]+delta[pos[to]]>=minn) ans++;
		}
	}
	for(int i=pos[from]+1;i<=pos[to]-1;i++){
		ans+=queryblock(i,minn);
	}
	return ans;
}
void add(int l,int r,int x)
{
	for(int i=l;i<=pos[l]*size&&i<=r;i++)
		data[i]+=x;
	refresh(pos[l]);
	if(pos[l]!=pos[r]){
		for(int i=(pos[r]-1)*size+1;i<=r;i++)
			data[i]+=x;
		refresh(pos[r]);
	}
	for(int i=pos[l]+1;i<=pos[r]-1;i++)
		delta[i]+=x;	
	return;
}
int main()
{
	scanf("%d%d",&m,&n);
	size=(int)sqrt(m+0.5),num=(m-1)/size+1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&data[i]);
		pos[i]=(i-1)/size+1;
	}
	for(int i=1;i<=pos[m];i++)
		refresh(i);
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		if(c=='A'){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",query(l,r,x));
		}
		if(c=='M'){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			add(l,r,x);
		}
	}
}
