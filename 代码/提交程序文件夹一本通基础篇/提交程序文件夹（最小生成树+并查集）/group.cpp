#include<bits/stdc++.h>
using namespace std;
int m,n,father[5001],anti[5001],tot;
int find(int i)
{
	if(father[i]!=i) father[i]=find(father[i]);
	return father[i];
}
void unionn(int i,int j)
{
	i=find(i);
	j=find(j);
	father[i]=j;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("group.in","r",stdin);
	//freopen("group.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	 father[i]=i;
	for(int i=1;i<=n;i++)
	{
		char o;
		int x,y;
		cin>>o>>x>>y;
		if(o=='F') unionn(x,y);
		else
		{
			if(anti[x]==0) anti[x]=y;
			else unionn(anti[x],y);
			if(anti[y]==0) anti[y]=x;
			else unionn(anti[y],x);
		}
	}
	for(int i=1;i<=m;i++)
	 if(father[i]==i) tot++;
	cout<<tot<<endl;
	return 0;
}
