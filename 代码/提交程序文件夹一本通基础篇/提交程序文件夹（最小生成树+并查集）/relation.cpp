#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxn 20001
int father[maxn],m,n;
int find(int i)
{
	if(father[i]!=i) father[i]=find(father[i]);
	return father[i];
}
void unionn(int i,int j)
{
	int xx=find(i);
	int yy=find(j);
	father[xx]=yy;
}
int main()
{
	freopen("relation.in","r",stdin);
	freopen("relation.out","w",stdout);
	//ios::sync_with_stdio(false);
	scanf("%d%d",&n,&m);//cin>>n>>m;//有n个人，m组关系 
	for(int i=1;i<=n;i++)
	 father[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int x1=find(x);
		int x2=find(y);
		if(x1!=x2) unionn(x1,x2);
	}
	int cx;
	cin>>cx;
	for(int i=1;i<=cx;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int x1=find(x);
		int y1=find(y);
		if(x1==y1) printf("Yes\n");
		else printf("No\n");
	} 
	return 0;
}
