#include<bits/stdc++.h>
using namespace std;
#define maxn 200001
int n,m,data[maxn],point[maxn],size,num;
vector<int>v[maxn];
void rebuild(int k)
{
	v[k].clear();
	for(int i=size*(i-1)+1;i<=size*i&&i<=n;i++)
		v[k].push_back(data[i]);
	sort(v[k].begin(),v[k].end());
	return;
}
int queryblock(int k)
{
	return v[k].back();
}
int query(int x,int y)
{
	int maxx=0;
	for(int i=x;i<=point[x]*size;i++)
		maxx=max(maxx,data[i]);
	if(point[x]!=point[y]) {
		for(int i=(point[y]-1)*size+1;i<=y;i++)
			maxx=max(data[i],maxx);
	}
	for(int i=point[x]+1;i<=point[y]-1;i++)
		maxx=max(queryblock(i),maxx);
	return maxx;
}
void change(int x,int y)
{
	rebuild(x);
	return;
}
int main()
{
	while((scanf("%d%d",&n,&m)!=EOF))
	{
		memset(data,0,sizeof(data));
		//v.clear();
		size=sqrt(n+0.5);//分块大小 
		num=(n-1)/size+1;//分块个数 
		for(int i=1;i<=n;i++)
			scanf("%d",&data[i]),point[i]=(i-1)/size+1;
		for(int i=1;i<=num;i++)
			rebuild(i);
		for(int i=1;i<=m;i++)
		{
			char c;
			cin>>c;
			if(c=='Q')
			{
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",query(x,y));
			}
			else{
				int x,y;
				scanf("%d%d",&x,&y);
				data[x]=y;
				change(x,y);
			}
		}
		for(int i=1;i<=num;i++)
			v[i].clear();
	}
}
