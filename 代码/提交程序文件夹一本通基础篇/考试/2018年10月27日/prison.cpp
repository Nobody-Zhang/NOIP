#include<bits/stdc++.h>
#define MAXX 200000*2+5
using namespace std;
int father[MAXX];
struct aaa
{
	int f1,f2,len;
}k[MAXX];
int cmp(const aaa a,const aaa b)
{
	return a.len>b.len;
}
int find(int i)
{
	if(father[i]!=i) father[i]=find(father[i]);
	return father[i];
}
int n,m;
void unionn(int i,int j)
{
	int i1=find(i);
	int j1=find(j);
	father[i1]=j1;
	i1=find(i1);
	j1=find(j1);
}
int main()
{
	freopen("prison.in","r",stdin);
	freopen("prison.out","w",stdout);
	cin>>n>>m;//m是多少组罪犯怨恨值，n是多少个罪犯 
	for(int i=1;i<=n*2;i++)
	 father[i]=i;
	for(int i=1;i<=m;i++)
	 cin>>k[i].f1>>k[i].f2>>k[i].len;
	sort(k+1,k+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=find(k[i].f1),y=find(k[i].f2);
		if(x==y)
		{
			cout<<k[i].len<<endl;
			return 0;
		}
		unionn(k[i].f1+n,y);
		unionn(k[i].f2+n,x);
	}
	cout<<"0"<<endl;
	return 0;
}
